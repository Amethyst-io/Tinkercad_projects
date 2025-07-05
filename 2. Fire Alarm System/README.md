***Introduction:***



Fires pose a significant threat to life and property. Early detection is crucial for safety. This project demonstrates a simple yet effective Fire Alarm System that leverages an Arduino microcontroller interfaced with both a temperature sensor and a gas sensor. Simulated in TinkerCad, this system aims to detect potential fire hazards by monitoring changes in ambient temperature and the presence of combustible gases or smoke, triggering an alarm to alert users.



***What the Project Does:***



* Detects Elevated Temperatures: Utilizes an LM-35 temperature sensor to continuously monitor the surrounding temperature.
* Detects Combustible Gases/Smoke: Employs an MQ-2 gas sensor to identify the presence of hazardous gases or smoke in the atmosphere.
* Triggers Alarm: Activates a piezo buzzer for an audible alert and an LED for a visual warning when predefined temperature or gas thresholds are exceeded.



***Components Used:***



* Arduino UNO Board: The central microcontroller that reads sensor data, processes it, and controls the alarm outputs.
* LM-35 Temperature Sensor: Provides analog output proportional to temperature, connected to Arduino's analog input (A1).
* MQ-2 Gas Sensor: Detects smoke and various gases, providing an analog output (connected to Arduino's analog input A0).
* Piezo Buzzer: For audible alarm alerts (connected to Arduino's digital pin 7).
* LED: For visual alarm indication (connected to Arduino's digital pin 13).
* Resistors: To limit current to the LED and for the gas sensor's operation.
* Breadboard and Jumper Wires: For organized circuit assembly and connections.
