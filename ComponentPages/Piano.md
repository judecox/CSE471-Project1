# Piano Synthesizer
Developed by Jude Cox

The Piano component within the Synthie project loads and generates sounds from a series of 88
note samples, representing each note found on a classical 88-key piano. 

The keys range sequentially from A-G, represented alphanumerically and replicated for octaves 0-7 where applicable.
Half-step notes (#) are included where applicable on a classical 88-key piano.

The Piano Synthesizer accounts for the following musical principles and capabilities:

### Polyphony
Polyphony simply means playing more than one note at a time.
Through the use of XML beat notation in our pre-determined audio scores,
the synthesizer allows for multi-note sample loading, letting XML-specified 
notes start and stop at any given time.

### Envelopes
Envelopes in the Synthesizer implementation accounts for the dampening of a
note as opposed to the note ringing out for a extended period of time, utilizing
an "Attack and Release" algorithm.

### Pedal Simulation
When a pedal is designated to be pressed in the XML score, an audible pedal sample
is played on both the down and up motion, and the dampening effect that occurs when a key is 
released is nulled, letting the note sustain for its entire duration.

### Basic and Advanced Dynamics
The XML score provided for the synthesizer contains specified attributes for 
Key Press Speed (keydynamics) and Key Press Effect (advkeydynamics), causing the
speed with which a key is pressed to make the given note louder, the higher the 
speed value represented as a double. An advanced version of that dynamic is also
implemented, causing a more realistic and tone by interpolating between its 
sustained and non-sustained sample.

### Score File
To store and load scores, we utilized XML to store the individual notes and
effects within our score. Each note is tied to one instrument, and each
instrument may be tied to one or more effects. We also allow any mixture of
parallel or serial effects.

The score file for FinalPianoDemo is shown below for reference.

```xml
<?xml version="1.0" encoding="utf-8"?>
<score bpm="100" beatspermeasure="6">
	<instrument instrument="piano">
		<note measure="1" beat="1" pedal="released" duration="3" keydynamic="1" note="WaveSamples/CompletePiano/C1#l.wav"/>
		<note measure="1" beat="1" duration="3" keydynamic="1" note="WaveSamples/CompletePiano/C2#l.wav"/>

		<note measure="1" beat="1" duration="1" note="WaveSamples/CompletePiano/G1#s.wav"/>
		<note measure="1" beat="2" duration="1" note="WaveSamples/CompletePiano/C4#s.wav"/>
		<note measure="1" beat="3" duration="1" note="WaveSamples/CompletePiano/E4s.wav"/>

		<note measure="1" beat="4" duration="1" note="WaveSamples/CompletePiano/G1#s.wav"/>
		<note measure="1" beat="5" duration="1" note="WaveSamples/CompletePiano/C4#s.wav"/>
		<note measure="1" beat="6" pedal="pressed" duration="1" note="WaveSamples/CompletePiano/E4s.wav"/>

		<note measure="2" beat="1" duration="1" note="WaveSamples/CompletePiano/G1#s.wav"/>
		<note measure="2" beat="2" duration="1" note="WaveSamples/CompletePiano/C4#s.wav"/>
		<note measure="2" beat="3" duration="1" note="WaveSamples/CompletePiano/E4s.wav"/>

		<note measure="2" beat="4" duration="1" note="WaveSamples/CompletePiano/G1#s.wav"/>
		<note measure="2" beat="5" duration="1" note="WaveSamples/CompletePiano/C4#s.wav"/>
		<note measure="2" beat="6" pedal="pressed" duration="1" note="WaveSamples/CompletePiano/E4s.wav"/>
		
		<note measure="3" beat="1" pedal="released" duration="3" keydynamic="1" note="WaveSamples/CompletePiano/B2l.wav"/>
		<note measure="3" beat="1" duration="3" keydynamic="1" note="WaveSamples/CompletePiano/B3l.wav"/>

		<note measure="3" beat="1" duration="1" note="WaveSamples/CompletePiano/G1#s.wav"/>
		<note measure="3" beat="2" duration="1" note="WaveSamples/CompletePiano/C4#s.wav"/>
		<note measure="3" beat="3" duration="1" note="WaveSamples/CompletePiano/E4s.wav"/>

		<note measure="3" beat="4" duration="1" note="WaveSamples/CompletePiano/G1#s.wav"/>
		<note measure="3" beat="5" duration="1" note="WaveSamples/CompletePiano/C4#s.wav"/>
		<note measure="3" beat="6" pedal="pressed" duration="1" note="WaveSamples/CompletePiano/E4s.wav"/>

		<note measure="4" beat="1" duration="1" note="WaveSamples/CompletePiano/G1#s.wav"/>
		<note measure="4" beat="2" duration="1" note="WaveSamples/CompletePiano/C4#s.wav"/>
		<note measure="4" beat="3" duration="1" note="WaveSamples/CompletePiano/E4s.wav"/>

		<note measure="4" beat="4" duration="1" note="WaveSamples/CompletePiano/G1#s.wav"/>
		<note measure="4" beat="5" duration="1" note="WaveSamples/CompletePiano/C4#s.wav"/>
		<note measure="4" beat="6" pedal="pressed" duration="1" note="WaveSamples/CompletePiano/E4s.wav"/>

		<note measure="5" beat="1" pedal="released" duration="3" keydynamic="1" note="WaveSamples/CompletePiano/A2l.wav"/>
		<note measure="5" beat="1" duration="3" keydynamic="1" note="WaveSamples/CompletePiano/A3l.wav"/>

		<note measure="5" beat="1" duration="1" note="WaveSamples/CompletePiano/A4s.wav"/>
		<note measure="5" beat="2" duration="1" note="WaveSamples/CompletePiano/C4#s.wav"/>
		<note measure="5" beat="3" duration="1" note="WaveSamples/CompletePiano/E4s.wav"/>

		<note measure="5" beat="4" duration="1" note="WaveSamples/CompletePiano/A4s.wav"/>
		<note measure="5" beat="5" duration="1" note="WaveSamples/CompletePiano/C4#s.wav"/>
		<note measure="5" beat="6" pedal="pressed" duration="1" note="WaveSamples/CompletePiano/E4s.wav"/>

		<note measure="6" beat="1" pedal="released" duration="3" keydynamic="1" note="WaveSamples/CompletePiano/F1#l.wav"/>
		<note measure="6" beat="1" duration="3" keydynamic="1" note="WaveSamples/CompletePiano/F2#l.wav"/>

		<note measure="6" beat="1" duration="1" note="WaveSamples/CompletePiano/A4s.wav"/>
		<note measure="6" beat="2" duration="1" note="WaveSamples/CompletePiano/D4s.wav"/>
		<note measure="6" beat="3" duration="1" note="WaveSamples/CompletePiano/F4#s.wav"/>

		<note measure="6" beat="4" duration="1" note="WaveSamples/CompletePiano/A4s.wav"/>
		<note measure="6" beat="5" duration="1" note="WaveSamples/CompletePiano/D4s.wav"/>
		<note measure="6" beat="6" pedal="pressed" duration="1" note="WaveSamples/CompletePiano/F4#s.wav"/>
	</instrument>
</score>
```





