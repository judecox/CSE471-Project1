# Organ
Component created by Leo Hoerdemann

### Tonewheels
The Tonewheels are stored as part of the m_harmonics vector in OrganWave that contains structures with how much to multiply the fundamental frequency for each harmonic and the amplitude of the tonewheel as set by the drawbars. This vector is used in the Generate function to get the tonewheels and their amplitudes to perform the additive synthesis.
### Drawbars
It can be specified per note by adding the drawbar tag and a value such as "805020000" to adjust the amplitude of each tonewheel after converting from the 0-8 value to the new amplitude ratio based on the decibel amount ratios found online. 
### Envelope Generation
This component is run through the Attack and Release class (AR) to add an envelope. The attack and release can be set using the corresponding tags for each note in the XML.
### Vibrato
The vibrato can be specified as a double range from 0 to 1 per note in the XML. The higher the vibrato amount specified the more dramatic the effect becomes. With a higher vibrato amount the effect will become faster and the range will become larger. This is done in the OrganWave Class and works by adjusting the phase for each harmonic upon generation.
### Leslie speaker
The Leslie speaker can be specified as a double range from 0 to 1 per note in the XML. The higher the amount the faster the Leslie speaker spins up to its max rate. This works by adjusting the amplitude of the signal genorated in OrganWave based on a sin and cosine function for the left and right respectively. These functions follow the time given to the organ. 




## Demo XML and Output File
[OrganTest.score](../Scores/Testing/OrganTest.score)
```xml
<?xml version="1.0" encoding="utf-8"?>
<score bpm="120" beatspermeasure="4">
   <instrument instrument="organ">
	<note measure="1" beat="1" duration="4" note="C4" drawbar="876543210" leslie ="0.5" vibrato = "0.2"/>
	<note measure="1" beat="1" duration="4" note="E4" drawbar="876543210" leslie ="0.5" vibrato = "0.2"/>
	<note measure="1" beat="1" duration="4" note="G4" drawbar="876543210" leslie ="0.5" vibrato = "0.2"/>

	<note measure="2" beat="1" duration="4" note="F4" drawbar="876543210" leslie ="0.5" vibrato = "0.2"/>
	<note measure="2" beat="1" duration="4" note="A4" drawbar="876543210" leslie ="0.5" vibrato = "0.2"/>
	<note measure="2" beat="1" duration="4" note="C4" drawbar="876543210" leslie ="0.5" vibrato = "0.2"/>

	<note measure="3" beat="1" duration="4" note="A4" drawbar="876543210" leslie ="0.5" vibrato = "0.2"/>
	<note measure="3" beat="1" duration="4" note="C4" drawbar="876543210" leslie ="0.5" vibrato = "0.2"/>
	<note measure="3" beat="1" duration="4" note="E4" drawbar="876543210" leslie ="0.5" vibrato = "0.2"/>

	<note measure="4" beat="1" duration="4" note="G3" drawbar="876543210" leslie ="0.5" vibrato = "0.2"/>
	<note measure="4" beat="1" duration="4" note="G4" drawbar="876543210" leslie ="0.5" vibrato = "0.2"/>
	<note measure="4" beat="1" duration="4" note="B4" drawbar="876543210" leslie ="0.5" vibrato = "0.2"/>
	<note measure="4" beat="1" duration="4" note="D4" drawbar="876543210" leslie ="0.5" vibrato = "0.2"/>

	<note measure="5" beat="1" duration="8" note="C3" drawbar="876543210" leslie ="0.5" vibrato = "0.2"/>
	<note measure="5" beat="1" duration="8" note="C4" drawbar="876543210" leslie ="0.5" vibrato = "0.2"/>
	<note measure="5" beat="1" duration="8" note="E4" drawbar="876543210" leslie ="0.5" vibrato = "0.2"/>
	<note measure="5" beat="1" duration="8" note="G4" drawbar="876543210" leslie ="0.5" vibrato = "0.2"/>
   </instrument>
</score>
```
[Audio Output](../Audio%20Outputs%20-%20FINAL%20RECORDINGS/OrganDemo.wav)