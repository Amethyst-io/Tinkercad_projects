***Hardware Requirements:***



* Arduino UNO Board: The Arduino UNO is a popular microcontroller board that reads sensor inputs and controls output devices. It has analog and digital pins to interface with various sensors like the LM35 temperature sensor.
* LM35 Temperature Sensor: The LM35 is an analog temperature sensor that outputs a voltage proportional to the temperature. It has three pins:
* Vcc (Supply Voltage): Connects to 5V power from Arduino.
* Output (Analog Voltage): Connects to Arduino analog input pin (A0).
* GND (Ground): Connects to Arduino ground.
* Jumper Wires: Used to connect the Arduino board and LM35 sensor pins. Types include male-to-male, male-to-female, and female-to-female depending on your setup.





***Working Principle:***



* The LM35 sensor produces an analog voltage output proportional to the temperature.
* Arduino reads this voltage via its analog input pin (A0).
* The Arduino converts this analog voltage to a digital value using its ADC (Analog to Digital Converter).
* Using the sensor’s voltage-to-temperature relationship, the Arduino calculates the temperature in degrees Celsius.
* This temperature data can be displayed on the Serial Monitor or used to control other devices.
