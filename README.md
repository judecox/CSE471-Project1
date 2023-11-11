--# Project 1: Multi-Component Music Synthesizer
[Placeholder audio. Replace.]


https://github.com/judecox/CSE471-Project1/assets/61844345/bd83dfd8-ac40-4593-8528-f89ee76ccd73


## Group Members
* Alec Charney - Wavetable/Integration Management
* Jude Cox - Piano/Git control
* Leo Hoerdeman - Organ/Project Management
* Ryan Chang - Effects/GitHub Presentation
* Kate Nagy - Prerecorded synth/1-minute piece

## Navigation
[Links to the component pages here. Example:]
* [Wavetable](./ComponentPages/Wavetable.md)
* [Organ](./ComponentPages/Organ.md)
* [Piano](./ComponentPages/Piano.md)
* [Recorded Performance](./ComponentPages/RecordedPerformance.md)


## Project Information
### Score File
To store and load scores, we utilized XML to store the individual notes and
effects within our score. Each note is tied to one instrument, and each
instrument may be tied to one or more effects. We also allow any mixture of
parallel or serial effects.

A sample score file is shown below for reference.

```xml
<?xml version="1.0" encoding="utf-8"?>
<score bpm="120" beatspermeasure="2">
	<effects>
		<compress id="test002" ratio="1" threshold="0.05" attack="0" release="0" />
	</effects>
	<instrument instrument="ToneInstrument">
		<note measure="1" beat="2" duration="0.33" note="F4" />
		<note measure="1" beat="2.33" duration="0.33" note="G4" />
		<note measure="1" beat="2.6" duration="0.33" note="A4" />

		<note measure="2" beat="1" duration="0.5" note="Bb4" />
		<note measure="2" beat="1" duration="0.5" note="G4" />
		<note measure="2" beat="1" duration="0.5" note="Eb4" />

		<note measure="3" beat="1" duration="0.5" note="Bb4" />
		<note measure="3" beat="1" duration="0.5" note="G4" />
		<note measure="3" beat="1" duration="0.5" note="Eb4" />

		<note measure="4" beat="1" duration="0.5" note="Bb4" />
		<note measure="4" beat="1" duration="0.5" note="D4" />
		<note measure="4" beat="1" duration="0.5" note="F4" />

		<note measure="4" beat="2" duration="0.5" note="Bb4" />
		<note measure="4" beat="2" duration="0.5" note="G4" />
		<note measure="4" beat="2" duration="0.5" note="Eb4" />

		<note measure="5" beat="1" duration="0.5" note="Bb4" />
		<note measure="5" beat="1" duration="0.5" note="D4" />
		<note measure="5" beat="1" duration="0.5" note="F4" />

		<note measure="6" beat="1" duration="0.5" note="G4" />
		<note measure="6" beat="1.5" duration="0.5" note="F#4" />
		<note measure="6" beat="2" duration="0.5" note="G4" />
		<note measure="6" beat="2.5" duration="0.5" note="G#4" />

		<note measure="7" beat="1" duration="1" note="A4" />
		<note measure="7" beat="2" duration="1" note="F4" />

		<note measure="8" beat="1" duration="3" note="Bb4" />
		<note measure="8" beat="1" duration="3" note="F4" />
		<note measure="8" beat="1" duration="3" note="D4" />
	</instrument>
</score>
```
