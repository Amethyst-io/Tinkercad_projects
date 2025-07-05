***Introduction:***



An Ultrasonic Sensor is an electronic device that measures the distance to an object by emitting ultrasonic sound waves—sound waves at frequencies above human hearing—and detecting their reflection. It calculates distance by measuring the time it takes for the sound waves to travel to the object and back. Ultrasonic sensors are widely used in obstacle-avoiding robots, automation systems, and proximity detection applications due to their accuracy and reliability.



***Components Used:***



* HC-SR04 Ultrasonic Sensor: Contains a transmitter that emits ultrasonic pulses and a receiver that detects the reflected sound waves.
* Arduino Uno R3: Processes signals from the sensor and calculates distance.
* Breadboard and Jumper Wires: Facilitate connections between components.
* Power Supply: 5V from Arduino for sensor operation.





***Working Principle:***



* The Arduino sends a 10-microsecond HIGH pulse to the Trigger pin to initiate ultrasonic waves.
* The sensor emits an 8-cycle burst of 40 kHz ultrasonic sound.
* The Echo pin goes HIGH for the duration it takes the sound to travel to the object and back.
* Arduino measures this time using the pulseIn() function.
* Distance is calculated using the formula:



Distance (cm)

= (Time (µs)×0.034)/2

&nbsp;

where 0.034 cm/µs is the speed of sound in air, and division by 2 accounts for the round trip of the pulse.

