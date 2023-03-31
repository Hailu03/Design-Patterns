public class Main {
    public static class Light {
        public void turnOn() {
            System.out.println("Light turned on");
        }
        
        public void turnOff() {
            System.out.println("Light turned off");
        }
    }
    
    // create the Command interface that defines the execute method
    public static interface Command {
        void execute();
    }
    
    // create a few concrete command classes that implement the Command interface
    public static class LightOnCommand implements Command {
        private final Light light;
        
        public LightOnCommand(Light light) {
            this.light = light;
        }
        
        @Override
        public void execute() {
            light.turnOn();
        }
    }
    
    public static class LightOffCommand implements Command {
        private final Light light;
        
        public LightOffCommand(Light light) {
            this.light = light;
        }
        
        @Override
        public void execute() {
            light.turnOff();
        }
    }
    
    
    // two above classes encapsulate requests to turn a light on or off. They both take a 'Light' object
    // as a parameter in their contructor and call the turnOn() or turnOff() method on that object
    // in their execute method
    
    // create invoker class that will execute the commands:
    public static class RemoteControl {
        private Command command;
        
        public void setCommand(Command command) {
            this.command = command;
        }
        
        public void pressButton() {
            command.execute();
        }
    }
    // In this example, the RemoteControl class has a setCommand() method that 
    //allows the client to set the command to be executed. The pressButton() 
    //method then calls the execute() method on the command object.

    public static void main(String[] args) {
        Light light = new Light();
        Command lightOnCommand = new LightOnCommand(light);
        RemoteControl remoteControl = new RemoteControl();
        remoteControl.setCommand(lightOnCommand);
        remoteControl.pressButton(); // Output: Light turned on

        Command lightOffCommand = new LightOffCommand(light);
        remoteControl.setCommand(lightOffCommand);
        remoteControl.pressButton();
    }
  }