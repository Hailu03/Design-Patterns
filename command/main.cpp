#include<iostream>
using namespace std;

class Light {
public:
    Light(){}
    void turnOn() {
        cout << "Light turned on" <<endl;
    }
    
    void turnOff() {
        cout << "Light turned off" <<endl;
    }
};

// create the Command interface that defines the execute method
class Command {
public:
    Command(){}
    virtual void execute() = 0;
};

// create a few concrete command classes that implement the Command interface
class LightOnCommand : public Command {
private:
    Light light;

public:
    LightOnCommand(Light light) {
        this->light = light;
    }
    
    void execute() {
        light.turnOn();
    }
};

class LightOffCommand : public Command {
private:
    Light light;
public:
    LightOffCommand(Light light) {
        this->light = light;
    }
    
    void execute() {
        light.turnOff();
    }
};


// two above classes encapsulate requests to turn a light on or off. They both take a 'Light' object
// as a parameter in their contructor and call the turnOn() or turnOff() method on that object
// in their execute method

// create invoker class that will execute the commands:
class RemoteControl {
private:
    Command *command;
    
public:
    void setCommand(Command *command) {
        this->command = command;
    }
    
    void pressButton() {
        command->execute();
    }
};
// In this example, the RemoteControl class has a setCommand() method that 
//allows the client to set the command to be executed. The pressButton() 
//method then calls the execute() method on the command object.

int main() {
    Light light;
    Command *lightOnCommand = new LightOnCommand(light);
    RemoteControl remoteControl;
    remoteControl.setCommand(lightOnCommand);
    remoteControl.pressButton(); // Output: Light turned on

    Command *lightOffCommand = new LightOffCommand(light);
    remoteControl.setCommand(lightOffCommand);
    remoteControl.pressButton();
    delete(lightOnCommand);
    delete(lightOffCommand);
}
