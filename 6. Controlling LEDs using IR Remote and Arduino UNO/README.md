***Introduction***



This project demonstrates how to control multiple LEDs using an IR remote and an Arduino UNO, all simulated within TinkerCAD. By integrating an IR sensor and remote, you can wirelessly switch LEDs on and off, mimicking the functionality of remote-controlled lighting systems commonly used in home automation.



***Components Required***



* Arduino UNO: The microcontroller board that processes IR signals and controls the LEDs.
* Breadboard: For easy and solderless circuit assembly.
* IR Remote: Acts as a wireless transmitter, sending coded signals to the Arduino.
* IR Sensor Module: Receives IR signals from the remote and passes them to the Arduino.
* LEDs (Blue, Orange, Green): Visual indicators controlled by the Arduino.
* Resistors (220Ω each): Limit current to protect the LEDs.
* Jumper Wires: For making all necessary connections.



***How It Works***



* IR Remote: When you press a button, the remote emits a unique infrared signal.
* IR Sensor: Receives the IR signal and sends a corresponding digital code to the Arduino.
* Arduino UNO: Decodes the received signal and, based on the button pressed, turns the appropriate LED on or off.
* LEDs: Each LED is assigned to a pair of remote buttons—one for ON, one for OFF.
