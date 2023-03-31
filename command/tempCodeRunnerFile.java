public static void main(Stirng[] args) {
    Light light = new Light();
    Command lightOnCommand = new LightOnCommand(light);
    RemoteControl remoteControl = new RemoteControl();
    remoteControl.setCommand(lightOnCommand);
    remoteControl.pressButton();
}