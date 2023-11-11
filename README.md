# Project 1: Multi-Component Music Synthesizer

https://github.com/judecox/CSE471-Project1/assets/61844345/bd83dfd8-ac40-4593-8528-f89ee76ccd73


## Group Members
* Alec Charney - Wavetable/Integration Management
* Jude Cox - Piano/Git control
* Leo Hoerdeman - Organ/Project Management
* Ryan Chang - Effects/GitHub Presentation
* Kate Nagy - Prerecorded synth/1-minute piece

## Navigation
* [Wavetable](./ComponentPages/Wavetable.md)
* [Organ](./ComponentPages/Organ.md)
* [Piano](./ComponentPages/Piano.md)
* [Recorded Performance](./ComponentPages/RecordedPerformance.md)
* [Effects](./ComponentPages/Effects.md)

## Project Information
### Score File
To store and load scores, we utilized XML to store the individual notes and
effects within our score. Each note is tied to one instrument, and each
instrument may be tied to one or more effects. We also allow any mixture of
parallel or serial effects.

A sample score file is shown below for reference.

```xml
<?xml version="1.0" encoding="utf-8"?>
<score bpm="96" beatspermeasure="4">
   <effects>
      <parallel id="CD_parallel01">
         <choir id="CD_choir01" delay="0.3641" rate="0.2" amount="0.5" mix="0.5" />
         <choir id="CD_choir02" phase="0.1" delay="0.2" offset="1" rate="0.3" amount="0.5" mix="0.5" />
      </parallel>
      <flange id="flange01" rate="0.5" amount="0.4" feedback="1" mix="0.5" gain="1.5" />
      <serial id="flangellium">
         <flange id="flange02" rate="0.7" amount="0.6" feedback="1" mix="0.5" gain="2" />
         <gate id="nonoise" threshold="0.2" attack="0.10" release="0.10" hold="0.50" />
      </serial>
      
   </effects>
   <instrument instrument="organ" effect="CD_parallel01">
      <note measure="1" beat="1" duration="2.9" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="1" beat="4" duration="0.15" note="Gb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="1" beat="4.25" duration="0.65" note="Gb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="2" beat="1" duration="1.65" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="2" beat="2.75" duration="0.15" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="2" beat="3" duration="1.9" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="1" beat="1" duration="2.9" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="1" beat="4" duration="0.15" note="Bb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="1" beat="4.25" duration="0.65" note="Bb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="2" beat="1" duration="1.65" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="2" beat="2.75" duration="0.15" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="2" beat="3" duration="1.9" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="1" beat="1" duration="2.9" note="Ab3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="1" beat="4" duration="0.15" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="1" beat="4.25" duration="0.65" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="2" beat="1" duration="1.65" note="Ab3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="2" beat="2.75" duration="0.15" note="Ab3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="2" beat="3" duration="1.9" note="Ab3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="1" beat="1" duration="2.9" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="1" beat="4" duration="0.15" note="Db3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="1" beat="4.25" duration="0.65" note="Db3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="2" beat="1" duration="1.65" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="2" beat="2.75" duration="0.15" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="2" beat="3" duration="1.9" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="3" beat="1" duration="2.9" note="Gb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="3" beat="4" duration="0.15" note="Gb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="3" beat="4.25" duration="0.65" note="Bb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="4" beat="1" duration="1.65" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="4" beat="2.75" duration="0.15" note="Gb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="4" beat="3" duration="1.9" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="3" beat="1" duration="2.9" note="Bb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="3" beat="4" duration="0.15" note="Bb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="3" beat="4.25" duration="0.65" note="Bb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="4" beat="1" duration="1.65" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="4" beat="2.75" duration="0.15" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="4" beat="3" duration="1.9" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="3" beat="1" duration="2.9" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="3" beat="4" duration="0.15" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="3" beat="4.25" duration="0.65" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="4" beat="1" duration="1.65" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="4" beat="2.75" duration="0.15" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="4" beat="3" duration="1.9" note="Ab3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="3" beat="1" duration="2.9" note="Db3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="3" beat="4" duration="0.15" note="Db3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="3" beat="4.25" duration="0.65" note="Bb2" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="4" beat="1" duration="1.65" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="4" beat="2.75" duration="0.15" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="4" beat="3" duration="1.9" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="5" beat="1" duration="2.9" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="5" beat="4" duration="0.15" note="Gb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="5" beat="4.25" duration="0.65" note="Gb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="6" beat="1" duration="1.65" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="6" beat="2.75" duration="0.15" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="6" beat="3" duration="1.9" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="5" beat="1" duration="2.9" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="5" beat="4" duration="0.15" note="Bb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="5" beat="4.25" duration="0.65" note="Bb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="6" beat="1" duration="1.65" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="6" beat="2.75" duration="0.15" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="6" beat="3" duration="1.9" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="5" beat="1" duration="2.9" note="Ab3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="5" beat="4" duration="0.15" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="5" beat="4.25" duration="0.65" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="6" beat="1" duration="1.65" note="Ab3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="6" beat="2.75" duration="0.15" note="Ab3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="6" beat="3" duration="1.9" note="Ab3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="5" beat="1" duration="2.9" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="5" beat="4" duration="0.15" note="Db3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="5" beat="4.25" duration="0.65" note="Db3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="6" beat="1" duration="1.65" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="6" beat="2.75" duration="0.15" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="6" beat="3" duration="1.9" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="7" beat="1" duration="2.9" note="Gb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="7" beat="4" duration="0.15" note="Gb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="7" beat="4.25" duration="0.65" note="Bb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="8" beat="1" duration="1.65" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="8" beat="2.75" duration="0.15" note="Gb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="8" beat="3" duration="1.9" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="7" beat="1" duration="2.9" note="Bb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="7" beat="4" duration="0.15" note="Bb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="7" beat="4.25" duration="0.65" note="Bb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="8" beat="1" duration="1.65" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="8" beat="2.75" duration="0.15" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="8" beat="3" duration="1.9" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="7" beat="1" duration="2.9" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="7" beat="4" duration="0.15" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="7" beat="4.25" duration="0.65" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="8" beat="1" duration="1.65" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="8" beat="2.75" duration="0.15" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="8" beat="3" duration="1.9" note="Ab3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="7" beat="1" duration="2.9" note="Db3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="7" beat="4" duration="0.15" note="Db3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="7" beat="4.25" duration="0.65" note="Bb2" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="8" beat="1" duration="1.65" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="8" beat="2.75" duration="0.15" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="8" beat="3" duration="1.9" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="9" beat="1" duration="2.9" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="9" beat="4" duration="0.15" note="Gb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="9" beat="4.25" duration="0.65" note="Gb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="10" beat="1" duration="1.65" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="10" beat="2.75" duration="0.15" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="10" beat="3" duration="1.9" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="9" beat="1" duration="2.9" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="9" beat="4" duration="0.15" note="Bb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="9" beat="4.25" duration="0.65" note="Bb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="10" beat="1" duration="1.65" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="10" beat="2.75" duration="0.15" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="10" beat="3" duration="1.9" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="9" beat="1" duration="2.9" note="Ab3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="9" beat="4" duration="0.15" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="9" beat="4.25" duration="0.65" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="10" beat="1" duration="1.65" note="Ab3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="10" beat="2.75" duration="0.15" note="Ab3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="10" beat="3" duration="1.9" note="Ab3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="9" beat="1" duration="2.9" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="9" beat="4" duration="0.15" note="Db3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="9" beat="4.25" duration="0.65" note="Db3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="10" beat="1" duration="1.65" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="10" beat="2.75" duration="0.15" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="10" beat="3" duration="1.9" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="11" beat="1" duration="2.9" note="Gb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="11" beat="4" duration="0.15" note="Gb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="11" beat="4.25" duration="0.65" note="Bb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="12" beat="1" duration="1.65" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="12" beat="2.75" duration="0.15" note="Gb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="12" beat="3" duration="1.9" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="11" beat="1" duration="2.9" note="Bb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="11" beat="4" duration="0.15" note="Bb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="11" beat="4.25" duration="0.65" note="Bb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="12" beat="1" duration="1.65" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="12" beat="2.75" duration="0.15" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="12" beat="3" duration="1.9" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="11" beat="1" duration="2.9" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="11" beat="4" duration="0.15" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="11" beat="4.25" duration="0.65" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="12" beat="1" duration="1.65" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="12" beat="2.75" duration="0.15" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="12" beat="3" duration="1.9" note="Ab3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="11" beat="1" duration="2.9" note="Db3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="11" beat="4" duration="0.15" note="Db3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="11" beat="4.25" duration="0.65" note="Bb2" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="12" beat="1" duration="1.65" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="12" beat="2.75" duration="0.15" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="12" beat="3" duration="1.9" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="13" beat="1" duration="2.9" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="13" beat="4" duration="0.15" note="Gb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="13" beat="4.25" duration="0.65" note="Gb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="14" beat="1" duration="1.65" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="14" beat="2.75" duration="0.15" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="14" beat="3" duration="1.9" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="13" beat="1" duration="2.9" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="13" beat="4" duration="0.15" note="Bb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="13" beat="4.25" duration="0.65" note="Bb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="14" beat="1" duration="1.65" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="14" beat="2.75" duration="0.15" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="14" beat="3" duration="1.9" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="13" beat="1" duration="2.9" note="Ab3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="13" beat="4" duration="0.15" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="13" beat="4.25" duration="0.65" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="14" beat="1" duration="1.65" note="Ab3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="14" beat="2.75" duration="0.15" note="Ab3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="14" beat="3" duration="1.9" note="Ab3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="13" beat="1" duration="2.9" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="13" beat="4" duration="0.15" note="Db3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="13" beat="4.25" duration="0.65" note="Db3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="14" beat="1" duration="1.65" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="14" beat="2.75" duration="0.15" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="14" beat="3" duration="1.9" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="15" beat="4" duration="0.15" note="E4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="15" beat="4.25" duration="0.65" note="Gb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="16" beat="1" duration="1.65" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="16" beat="2.75" duration="0.15" note="Gb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="16" beat="3" duration="1.9" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="15" beat="1" duration="2.9" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="15" beat="4" duration="0.15" note="Bb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="15" beat="4.25" duration="0.65" note="Bb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="16" beat="1" duration="1.65" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="16" beat="2.75" duration="0.15" note="Bb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="16" beat="3" duration="1.9" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="15" beat="1" duration="2.9" note="Ab3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="15" beat="4" duration="0.15" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="15" beat="4.25" duration="0.65" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="16" beat="1" duration="1.65" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="16" beat="3" duration="1.9" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="15" beat="1" duration="2.9" note="E3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="15" beat="4" duration="0.15" note="Db3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="15" beat="4.25" duration="0.65" note="Bb2" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="16" beat="1" duration="1.65" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="16" beat="2.75" duration="0.15" note="E3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="16" beat="3" duration="1.9" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="17" beat="1" duration="2.9" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="17" beat="4" duration="0.15" note="Gb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="17" beat="4.25" duration="0.65" note="Gb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="18" beat="1" duration="1.65" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="18" beat="2.75" duration="0.15" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="18" beat="3" duration="1.9" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="17" beat="1" duration="2.9" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="17" beat="4" duration="0.15" note="Bb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="17" beat="4.25" duration="0.65" note="Bb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="18" beat="1" duration="1.65" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="18" beat="2.75" duration="0.15" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="18" beat="3" duration="1.9" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="17" beat="1" duration="2.9" note="Ab3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="17" beat="4" duration="0.15" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="17" beat="4.25" duration="0.65" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="18" beat="1" duration="1.65" note="Ab3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="18" beat="2.75" duration="0.15" note="Ab3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="18" beat="3" duration="1.9" note="Ab3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="17" beat="1" duration="2.9" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="17" beat="4" duration="0.15" note="Db3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="17" beat="4.25" duration="0.65" note="Db3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="18" beat="1" duration="1.65" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="18" beat="2.75" duration="0.15" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="18" beat="3" duration="1.9" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="19" beat="4" duration="0.15" note="E4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="19" beat="4.25" duration="0.65" note="Gb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="20" beat="1" duration="1.65" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="20" beat="2.75" duration="0.15" note="Gb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="20" beat="3" duration="1.9" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="19" beat="1" duration="2.9" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="19" beat="4" duration="0.15" note="Bb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="19" beat="4.25" duration="0.65" note="Bb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="20" beat="1" duration="1.65" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="20" beat="2.75" duration="0.15" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="20" beat="3" duration="1.9" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="19" beat="1" duration="2.9" note="Ab3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="19" beat="4" duration="0.15" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="19" beat="4.25" duration="0.65" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="20" beat="1" duration="1.65" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="20" beat="2.75" duration="0.15" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="20" beat="3" duration="1.9" note="Ab3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="19" beat="1" duration="2.9" note="E3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="19" beat="4" duration="0.15" note="Db3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="19" beat="4.25" duration="0.65" note="Bb2" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="20" beat="1" duration="1.65" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="20" beat="2.75" duration="0.15" note="E3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="20" beat="3" duration="1.9" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="21" beat="1" duration="2.9" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="21" beat="4" duration="0.15" note="Gb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="21" beat="4.25" duration="0.65" note="Gb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="22" beat="1" duration="1.65" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="22" beat="2.75" duration="0.15" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="22" beat="3" duration="1.9" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="21" beat="1" duration="2.9" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="21" beat="4" duration="0.15" note="Bb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="21" beat="4.25" duration="0.65" note="Bb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="22" beat="1" duration="1.65" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="22" beat="2.75" duration="0.15" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="22" beat="3" duration="1.9" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="21" beat="1" duration="2.9" note="Ab3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="21" beat="4" duration="0.15" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="21" beat="4.25" duration="0.65" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="22" beat="1" duration="1.65" note="Ab3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="22" beat="2.75" duration="0.15" note="Ab3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="22" beat="3" duration="1.9" note="Ab3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="21" beat="1" duration="2.9" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="21" beat="4" duration="0.15" note="Db3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="21" beat="4.25" duration="0.65" note="Db3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="22" beat="1" duration="1.65" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="22" beat="2.75" duration="0.15" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="22" beat="3" duration="1.9" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="23" beat="1" duration="2.9" note="Gb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="23" beat="4" duration="0.15" note="Gb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="23" beat="4.25" duration="0.65" note="Bb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="24" beat="1" duration="1.65" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="24" beat="2.75" duration="0.15" note="Gb4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="24" beat="3" duration="2.9" note="Ab4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="23" beat="1" duration="2.9" note="Bb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="23" beat="4" duration="0.15" note="Bb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="23" beat="4.25" duration="0.65" note="Bb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="24" beat="1" duration="1.65" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="24" beat="2.75" duration="0.15" note="B3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="24" beat="3" duration="2.9" note="C4" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="23" beat="1" duration="2.9" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="23" beat="4" duration="0.15" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="23" beat="4.25" duration="0.65" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="24" beat="1" duration="1.65" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="24" beat="2.75" duration="0.15" note="Gb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="24" beat="3" duration="2.9" note="Ab3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="23" beat="1" duration="2.9" note="Db3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="23" beat="4" duration="0.15" note="Db3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="23" beat="4.25" duration="0.65" note="Bb2" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="24" beat="1" duration="1.65" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="24" beat="2.75" duration="0.15" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
      <note measure="24" beat="3" duration="2.9" note="Eb3" drawbar="876543210" leslie="0.1"
         vibrato="0.1" />
   </instrument>
   <instrument instrument="wavetable" effect="flange01">
      <note measure="5" beat="1" duration="0.9" note="Ab4" />
      <note measure="5" beat="2" duration="1.9" note="B4" gliss="Db4" />
      <note measure="5" beat="4" duration="0.9" note="Db4" />
      <note measure="6" beat="1" duration="0.9" note="B4" />
      <note measure="6" beat="2" duration="0.4" note="Ab4" />
      <note measure="6" beat="2.5" duration="0.4" note="E4" />
      <note measure="6" beat="3" duration="0.9" note="Gb4" />
      <note measure="6" beat="4" duration="0.9" note="Ab4" />
      <note measure="5" beat="1" duration="0.9" note="Eb4" />
      <note measure="5" beat="2" duration="1.9" note="Eb4" gliss="Db4" />
      <note measure="5" beat="4" duration="0.9" note="Db4" />
      <note measure="6" beat="1" duration="0.9" note="B3" />
      <note measure="6" beat="2" duration="0.4" note="B3" />
      <note measure="6" beat="2.5" duration="0.4" note="Db4" />
      <note measure="6" beat="3" duration="0.9" note="Db4" />
      <note measure="6" beat="4" duration="0.9" note="Eb4" />
      <note measure="7" beat="1" duration="0.9" note="Gb4" />
      <note measure="7" beat="2" duration="1.9" note="Bb4" gliss="Gb4" />
      <note measure="7" beat="4" duration="0.9" note="Gb4" />
      <note measure="8" beat="1" duration="0.9" note="Ab4" />
      <note measure="8" beat="2" duration="0.4" note="Eb4" />
      <note measure="8" beat="2.5" duration="0.4" note="Gb4" />
      <note measure="8" beat="3" duration="0.9" note="B4" />
      <note measure="8" beat="4" duration="0.9" note="Ab4" />
      <note measure="7" beat="1" duration="0.9" note="Db4" />
      <note measure="7" beat="2" duration="1.9" note="Db4" gliss="Bb3" />
      <note measure="7" beat="4" duration="0.9" note="Bb3" />
      <note measure="8" beat="1" duration="0.9" note="B3" />
      <note measure="8" beat="2" duration="0.4" note="B3" />
      <note measure="8" beat="2.5" duration="0.4" note="Db4" />
      <note measure="8" beat="3" duration="0.9" note="Eb4" />
      <note measure="8" beat="4" duration="0.9" note="Eb4" />
      <note measure="9" beat="1" duration="2.9" note="B4" gliss="Db4" />
      <note measure="9" beat="4" duration="0.9" note="Db4" />
      <note measure="10" beat="1" duration="0.9" note="B4" />
      <note measure="10" beat="2" duration="0.4" note="Ab4" />
      <note measure="10" beat="2.5" duration="0.4" note="E4" />
      <note measure="10" beat="3" duration="0.9" note="Gb4" />
      <note measure="10" beat="4" duration="0.9" note="Ab4" />
      <note measure="9" beat="1" duration="2.9" note="Eb4" />
      <note measure="9" beat="4" duration="0.9" note="Db4" />
      <note measure="10" beat="1" duration="0.9" note="B3" />
      <note measure="10" beat="2" duration="0.4" note="B3" />
      <note measure="10" beat="2.5" duration="0.4" note="Db4" />
      <note measure="10" beat="3" duration="0.9" note="Db4" />
      <note measure="10" beat="4" duration="0.9" note="Eb4" />
      <note measure="11" beat="1" duration="2.9" note="Bb4" gliss="B4" />
      <note measure="11" beat="4" duration="0.9" note="B4" />
      <note measure="12" beat="1" duration="0.9" note="Gb4" />
      <note measure="12" beat="1.5" duration="0.4" note="Bb4" />
      <note measure="12" beat="2" duration="0.4" note="Bb4" />
      <note measure="12" beat="3" duration="1.9" note="B4" />
      <note measure="11" beat="1" duration="2.9" note="Db4" gliss="Eb4" />
      <note measure="11" beat="4" duration="0.9" note="Eb4" />
      <note measure="12" beat="1" duration="0.9" note="B3" />
      <note measure="12" beat="1.5" duration="0.4" note="Eb4" />
      <note measure="12" beat="2" duration="0.4" note="Db4" />
      <note measure="12" beat="3" duration="1.9" note="Eb4" gliss="B4" />
      <note measure="21" beat="1" duration="2.9" note="B4" gliss="Db4" />
      <note measure="21" beat="4" duration="0.9" note="Db4" />
      <note measure="22" beat="1" duration="0.9" note="B4" />
      <note measure="22" beat="2" duration="0.4" note="Ab4" />
      <note measure="22" beat="2.5" duration="0.4" note="E4" />
      <note measure="22" beat="3" duration="0.9" note="Gb4" />
      <note measure="22" beat="4" duration="0.9" note="Ab4" />
      <note measure="21" beat="1" duration="2.9" note="Eb4" gliss="Db4" />
      <note measure="21" beat="4" duration="0.9" note="Db4" />
      <note measure="22" beat="1" duration="0.9" note="B3" />
      <note measure="22" beat="2" duration="0.4" note="B3" />
      <note measure="22" beat="2.5" duration="0.4" note="Db4" />
      <note measure="22" beat="3" duration="0.9" note="Db4" />
      <note measure="22" beat="4" duration="0.9" note="Eb4" />
      <note measure="23" beat="1" duration="2.9" note="Bb4" gliss="B4" />
      <note measure="23" beat="4" duration="0.9" note="B4" />
      <note measure="24" beat="1" duration="0.9" note="Eb4" />
      <note measure="24" beat="2" duration="0.9" note="Db4" />
      <note measure="24" beat="3" duration="2.9" note="C4" gliss="Db4" />
      <note measure="23" beat="1" duration="2.9" note="Db4" gliss="Eb4" />
      <note measure="23" beat="4" duration="0.9" note="Eb4" />
      <note measure="24" beat="1" duration="0.9" note="Gb4" />
      <note measure="24" beat="2" duration="0.9" note="Bb4" />
      <note measure="24" beat="3" duration="2.9" note="Eb4" />
   </instrument>
   <instrument instrument="piano" effect="flangellium">
      <note measure="9" beat="1" pedal="pressed" duration="1.4"
         note="WaveSamples/CompletePiano/G5#s.wav" />
      <note measure="9" beat="2.5" duration="0.4"
         note="WaveSamples/CompletePiano/F5#s.wav" />
      <note measure="9" beat="3" duration="0.9"
         note="WaveSamples/CompletePiano/G5#s.wav" />
      <note measure="9" beat="4" duration="0.9"
         note="WaveSamples/CompletePiano/C6#s.wav" />
      <note measure="10" beat="1" pedal="released"
         duration="0.9" note="WaveSamples/CompletePiano/B5s.wav" />
      <note measure="10" beat="2"
         duration="0.9" note="WaveSamples/CompletePiano/A5#s.wav" />
      <note measure="10" beat="3"
         duration="0.5" note="WaveSamples/CompletePiano/A5#s.wav" />
      <note measure="10" beat="3.5"
         duration="0.25" note="WaveSamples/CompletePiano/B5s.wav" />
      <note measure="10" beat="3.75"
         pedal="pressed" duration="0.25" note="WaveSamples/CompletePiano/A5#s.wav" />
      <note
         measure="10" beat="4" duration="0.9" note="WaveSamples/CompletePiano/G5#s.wav" />
      <note
         measure="11" beat="1" duration="1.4" note="WaveSamples/CompletePiano/F5#s.wav" />
      <note
         measure="11" beat="2.5" duration="0.4" note="WaveSamples/CompletePiano/E5s.wav" />
      <note
         measure="11" beat="3" pedal="released" duration="0.9"
         note="WaveSamples/CompletePiano/F5#s.wav" />
      <note measure="11" beat="4" duration="0.9"
         note="WaveSamples/CompletePiano/B5s.wav" />
      <note measure="12" beat="1" duration="0.9"
         note="WaveSamples/CompletePiano/A5#s.wav" />
      <note measure="12" beat="2" duration="0.75"
         note="WaveSamples/CompletePiano/G5#s.wav" />
      <note measure="12" beat="2.75" pedal="pressed"
         duration="0.25" note="WaveSamples/CompletePiano/F5#s.wav" />
      <note measure="12" beat="3"
         duration="1.9" note="WaveSamples/CompletePiano/G5#s.wav" />
      <note measure="13" beat="1"
         duration="1.4" note="WaveSamples/CompletePiano/G5#s.wav" />
      <note measure="13" beat="2.5"
         duration="0.4" note="WaveSamples/CompletePiano/F5#s.wav" />
      <note measure="13" beat="3"
         pedal="released" duration="1.4" note="WaveSamples/CompletePiano/G5#s.wav" />
      <note
         measure="13" beat="4.5" duration="0.4" note="WaveSamples/CompletePiano/F5#s.wav" />
      <note
         measure="14" beat="1" duration="1.4" note="WaveSamples/CompletePiano/D5#s.wav" />
      <note
         measure="14" beat="2.5" duration="0.4" note="WaveSamples/CompletePiano/C5#s.wav" />
      <note
         measure="14" beat="3" pedal="pressed" duration="0.9"
         note="WaveSamples/CompletePiano/D5#s.wav" />
      <note measure="14" beat="4" duration="0.9"
         note="WaveSamples/CompletePiano/G5s.wav" />
      <note measure="15" beat="1" duration="1.4"
         note="WaveSamples/CompletePiano/E5s.wav" />
      <note measure="15" beat="2.5" duration="0.4"
         note="WaveSamples/CompletePiano/D5#s.wav" />
      <note measure="15" beat="3" pedal="released"
         duration="1.4" note="WaveSamples/CompletePiano/E5s.wav" />
      <note measure="15" beat="4.5"
         duration="0.15" note="WaveSamples/CompletePiano/D5#s.wav" />
      <note measure="15" beat="4.75"
         duration="0.15" note="WaveSamples/CompletePiano/C5#s.wav" />
      <note measure="16" beat="1"
         duration="0.9" note="WaveSamples/CompletePiano/B4s.wav" />
      <note measure="16" beat="2"
         pedal="pressed" duration="0.9" note="WaveSamples/CompletePiano/C5#s.wav" />
      <note
         measure="16" beat="3" duration="1.9" note="WaveSamples/CompletePiano/D5#s.wav" />
      <note
         measure="17" beat="1" duration="1.4" note="WaveSamples/CompletePiano/G5#s.wav" />
      <note
         measure="17" beat="2.5" duration="0.4" keydynamic="1"
         note="WaveSamples/CompletePiano/F5#s.wav" />
      <note measure="17" beat="3" duration="1.4"
         note="WaveSamples/CompletePiano/G5#s.wav" />
      <note measure="17" beat="4.5" duration="0.4"
         note="WaveSamples/CompletePiano/B5s.wav" />
      <note measure="18" beat="1" duration="1.4"
         keydynamic="0.75" note="WaveSamples/CompletePiano/B5s.wav" />
      <note measure="18" beat="2.5"
         duration="0.4" note="WaveSamples/CompletePiano/B5s.wav" />
      <note measure="18" beat="3"
         duration="0.9" note="WaveSamples/CompletePiano/B5s.wav" />
      <note measure="18" beat="4"
         duration="0.65" note="WaveSamples/CompletePiano/G5#s.wav" />
      <note measure="18" beat="4.75"
         duration="0.25" note="WaveSamples/CompletePiano/G5s.wav" />
      <note measure="19" beat="1"
         duration="1.4" keydynamic="0.5" note="WaveSamples/CompletePiano/E5s.wav" />
      <note
         measure="19" beat="2.5" duration="0.4" note="WaveSamples/CompletePiano/D5#s.wav" />
      <note
         measure="19" beat="3" duration="1.4" note="WaveSamples/CompletePiano/E5s.wav" />
      <note
         measure="19" beat="4.5" duration="0.15" note="WaveSamples/CompletePiano/D5#s.wav" />
      <note
         measure="19" beat="4.75" duration="0.15" note="WaveSamples/CompletePiano/E5s.wav" />
      <note
         measure="20" beat="1" duration="0.9" keydynamic="0.25"
         note="WaveSamples/CompletePiano/G5s.wav" />
      <note measure="20" beat="2" duration="0.9"
         note="WaveSamples/CompletePiano/G5#s.wav" />
      <note measure="20" beat="3" duration="1.9"
         note="WaveSamples/CompletePiano/G5#s.wav" />
      <note measure="21" beat="1" duration="1.4"
         note="WaveSamples/CompletePiano/G5#s.wav" />
      <note measure="21" beat="2.5" duration="0.4"
         note="WaveSamples/CompletePiano/F5#s.wav" />
      <note measure="21" beat="3" duration="0.9"
         note="WaveSamples/CompletePiano/G5#s.wav" />
      <note measure="21" beat="4" duration="0.9"
         note="WaveSamples/CompletePiano/D6s.wav" />
      <note measure="22" beat="1" duration="0.9"
         note="WaveSamples/CompletePiano/B5s.wav" />
      <note measure="22" beat="2" duration="0.9"
         note="WaveSamples/CompletePiano/B5s.wav" />
      <note measure="22" beat="3" duration="0.5"
         note="WaveSamples/CompletePiano/B5s.wav" />
      <note measure="22" beat="3.5" duration="0.25"
         note="WaveSamples/CompletePiano/B5s.wav" />
      <note measure="22" beat="3.75" duration="0.25"
         note="WaveSamples/CompletePiano/B5s.wav" />
      <note measure="22" beat="4" duration="0.9"
         note="WaveSamples/CompletePiano/G5#s.wav" advkeydynamic="WaveSamples/CompletePiano/A5l.wav" />

      <note
         measure="23" beat="1" duration="1.4" note="WaveSamples/CompletePiano/F5#s.wav"
         advkeydynamic="WaveSamples/CompletePiano/F5#l.wav" />
      <note measure="23" beat="2.5"
         duration="0.4" note="WaveSamples/CompletePiano/E5s.wav" />
      <note measure="23" beat="3"
         duration="0.9" note="WaveSamples/CompletePiano/F5#s.wav" />
      <note measure="23" beat="4"
         duration="0.9" note="WaveSamples/CompletePiano/B5s.wav"
         advkeydynamic="WaveSamples/CompletePiano/B5l.wav" />
      <note measure="24" beat="1"
         duration="0.9" note="WaveSamples/CompletePiano/B5s.wav"
         advkeydynamic="WaveSamples/CompletePiano/B5l.wav" />
      <note measure="24" beat="2"
         duration="0.75" note="WaveSamples/CompletePiano/G5#s.wav" />
      <note measure="24" beat="2.75"
         duration="0.25" note="WaveSamples/CompletePiano/F5#s.wav" />
      <note measure="24" beat="3"
         duration="2.9" note="WaveSamples/CompletePiano/G5#s.wav"
         advkeydynamic="WaveSamples/CompletePiano/G5#l.wav" />
   </instrument>
   <recording filename="CompletedRecordingDemo-CorrectSpacing.wav" measure="13" beat="1">
      <effectrecorded measure="13" beat="1" effect="0" parameter="0.3" />
      <effectrecorded measure="14" beat="3.5" effect="1" parameter="0.7" />
      <effectrecorded measure="14" beat="3.625" effect="1" parameter="0.8" />
      <effectrecorded measure="14" beat="3.75" effect="1" parameter="0.9" />
      <effectrecorded measure="15" beat="1" effect="1" parameter="0.975" />
      <effectrecorded measure="16" beat="1.1" effect="1" parameter="0.9" />
      <effectrecorded measure="16" beat="1.2" effect="1" parameter="0.85" />
      <effectrecorded measure="16" beat="1.3" effect="1" parameter="0.8" />
      <effectrecorded measure="16" beat="1.4" effect="1" parameter="0.75" />
      <effectrecorded measure="16" beat="1.5" effect="1" parameter="0.7" />
      <effectrecorded measure="16" beat="1.6" effect="1" parameter="0.65" />
      <effectrecorded measure="16" beat="1.7" effect="1" parameter="0.6" />
      <effectrecorded measure="16" beat="1.8" effect="1" parameter="0.55" />
      <effectrecorded measure="16" beat="1.9" effect="1" parameter="0.5" />
      <effectrecorded measure="16" beat="2" effect="1" parameter="0.45" />
      <effectrecorded measure="16" beat="2.1" effect="1" parameter="0.45" />
      <effectrecorded measure="16" beat="2.2" effect="1" parameter="0.35" />
      <effectrecorded measure="16" beat="2.3" effect="1" parameter="0.3" />
      <effectrecorded measure="16" beat="2.4" effect="1" parameter="0.25" />
      <effectrecorded measure="16" beat="2.5" effect="1" parameter="0.2" />
      <effectrecorded measure="16" beat="2.6" effect="1" parameter="0.15" />
      <effectrecorded measure="16" beat="2.7" effect="1" parameter="0.1" />
      <effectrecorded measure="16" beat="2.8" effect="1" parameter="0.05" />
      <effectrecorded measure="16" beat="2.9" effect="1" parameter="0.0" />
      <effectrecorded measure="17" beat="2" effect="0" parameter="10.0" />
      <effectrecorded measure="17" beat="2" effect="2" parameter="1.0" />
      <effectrecorded measure="17" beat="2" effect="3" parameter="0.01" />
      <effectrecorded measure="17" beat="2" effect="4" parameter="0.1" />
      <effectrecorded measure="17" beat="2.1" effect="4" parameter="0.09" />
      <effectrecorded measure="17" beat="2.2" effect="4" parameter="0.08" />
      <effectrecorded measure="17" beat="2.3" effect="4" parameter="0.07" />
      <effectrecorded measure="17" beat="2.4" effect="4" parameter="0.06" />
      <effectrecorded measure="17" beat="2.5" effect="4" parameter="0.05" />
      <effectrecorded measure="17" beat="2.6" effect="4" parameter="0.04" />
      <effectrecorded measure="17" beat="2.7" effect="4" parameter="0.03" />
      <effectrecorded measure="17" beat="2.8" effect="4" parameter="0.02" />
      <effectrecorded measure="18" beat="2.9" effect="4" parameter="0.01" />
      <effectrecorded measure="18" beat="3" effect="4" parameter="0.02" />
      <effectrecorded measure="18" beat="3.1" effect="4" parameter="0.03" />
      <effectrecorded measure="18" beat="3.2" effect="4" parameter="0.04" />
      <effectrecorded measure="18" beat="3.3" effect="4" parameter="0.05" />
      <effectrecorded measure="18" beat="3.4" effect="4" parameter="0.06" />
      <effectrecorded measure="18" beat="3.5" effect="4" parameter="0.07" />
      <effectrecorded measure="18" beat="3.6" effect="4" parameter="0.08" />
      <effectrecorded measure="18" beat="3.7" effect="4" parameter="0.09" />
      <effectrecorded measure="18" beat="3.8" effect="4" parameter="0.1" />
   </recording>
</score>
```
