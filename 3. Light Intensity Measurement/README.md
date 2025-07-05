***Introduction:***



Light intensity measurement plays a crucial role in applications like home automation, where it helps control lighting based on ambient conditions. The LDR (Light Dependent Resistor) sensor, also known as a photoresistor, is widely used for this purpose. It changes its resistance depending on the amount of light falling on it, enabling Arduino to measure light levels and respond accordingly.



***Hardware Components:***



* Arduino UNO Board: The microcontroller that reads sensor input and controls output devices.
* LDR Sensor: A photoresistor whose resistance decreases with increasing light intensity.
* Resistor (typically 1.5kΩ): Used in a voltage divider circuit with the LDR to convert resistance changes into measurable voltage changes.
* Breadboard and Jumper Wires: For easy circuit connections.
* LED: Can be used as an output indicator based on light intensity.



***Circuit Connections:***



* Connect one terminal of the LDR to 5V.
* Connect the other terminal of the LDR to one end of the resistor.
* Connect the other end of the resistor to Ground (GND).
* Connect the junction between LDR and resistor to Arduino analog input pin (e.g., A0).
* Connect LED cathode to GND and anode through a resistor to a digital pin (optional for output).
* This forms a voltage divider where the voltage at the junction varies with light intensity.



***Working Principle:***



* The LDR’s resistance decreases as light intensity increases, causing the voltage at the analog pin to change.
* Arduino reads this analog voltage and converts it into a digital value using its ADC (Analog to Digital Converter).
* By setting thresholds in the Arduino code, the system can decide when to turn on/off LEDs or other devices based on ambient light levels.



***Applications:***



* Automatic street lighting.
* Camera exposure control.
* Security systems triggering lights or alarms.
* Solar panel positioning.
* Home automation for energy-efficient lighting.
