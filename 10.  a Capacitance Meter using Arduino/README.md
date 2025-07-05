**Introduction**



Capacitance is the ability of a component (capacitor) to store electrical charge. Measuring capacitance is useful for identifying unknown or unmarked capacitors, or for testing self-built ones. This guide explains how to use an Arduino to measure the capacitance of a capacitor using a simple RC (Resistor-Capacitor) charging circuit.



**What Is Capacitance?**



Capacitance (C) is the property of a capacitor to store electric charge.



In a parallel plate capacitor, capacitance is given by:  C= d\*ε\*A

&nbsp;

where:

ε = permittivity of the dielectric,

A = area of plate overlap,

d = distance between plates.



**How Is Capacitance Measured?**



The RC Time Constant (τ) is a key property: τ=R×C



τ is the time it takes a capacitor to charge to 63.2% of the supply voltage through a resistor.

By measuring the time to reach this voltage, and knowing the resistor value, you can calculate the capacitance.



**Parts Needed**



* Arduino UNO
* Breadboard
* Jumper wires
* 220 Ω resistor (optional, for faster discharge)
* 10 kΩ resistor (for charging)
* Capacitor (unknown value to measure)



**How It Works**



* The Arduino charges the capacitor through a known resistor and times how long it takes to reach 63.2% of the supply voltage.
* It calculates the capacitance using the RC time constant formula.
* The result is displayed in microfarads (μF) or nanofarads (nF) on the Serial Monitor.
* The process repeats, allowing you to take an average for more accurate results.