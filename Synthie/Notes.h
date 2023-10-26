//
// Name :         Notes.h
// Description :  Header file with consts for notes to frequency conversions
//				  or note to audio file conversions.
//

#pragma once

struct Notes
{
   const TCHAR *name;
   double freq;
};

const Notes notes[] = {{TEXT("A0"), 27.5}, {TEXT("A#0"), 29.1352}, {TEXT("Bb0"), 29.1352}, {TEXT("B0"), 30.8677},
{TEXT("C1"), 32.7032}, {TEXT("C#1"), 34.6478}, {TEXT("Db1"), 34.6478}, {TEXT("D1"), 36.7081}, {TEXT("D#1"), 38.8909}, 
{TEXT("Eb1"), 38.8909}, {TEXT("E1"), 41.2034}, {TEXT("F1"), 43.6535}, {TEXT("F#1"), 46.2493}, {TEXT("Gb1"), 46.2493}, 
{TEXT("G1"), 48.9994}, {TEXT("G#1"), 51.9131}, {TEXT("Ab1"), 51.9131}, {TEXT("A1"), 55.0}, {TEXT("A#1"), 58.2705}, 
{TEXT("Bb1"), 58.2705}, {TEXT("B1"), 61.7354}, {TEXT("C2"), 65.4064}, {TEXT("C#2"), 69.2957}, {TEXT("Db2"), 69.2957}, 
{TEXT("D2"), 73.4162}, {TEXT("D#2"), 77.7817}, {TEXT("Eb2"), 77.7817}, {TEXT("E2"), 82.4069}, {TEXT("F2"), 87.3071}, 
{TEXT("F#2"), 92.4986}, {TEXT("Gb2"), 92.4986}, {TEXT("G2"), 97.9989}, {TEXT("G#2"), 103.826}, {TEXT("Ab2"), 103.826}, 
{TEXT("A2"), 110.0}, {TEXT("A#2"), 116.541}, {TEXT("Bb2"), 116.541}, {TEXT("B2"), 123.471}, {TEXT("C3"), 130.813}, 
{TEXT("C#3"), 138.591}, {TEXT("Db3"), 138.591}, {TEXT("D3"), 146.832}, {TEXT("D#3"), 155.563}, {TEXT("Eb3"), 155.563}, 
{TEXT("E3"), 164.814}, {TEXT("F3"), 174.614}, {TEXT("F#3"), 184.997}, {TEXT("Gb3"), 184.997}, {TEXT("G3"), 195.998}, 
{TEXT("G#3"), 207.652}, {TEXT("Ab3"), 207.652}, {TEXT("A3"), 220.0}, {TEXT("A#3"), 233.082}, {TEXT("Bb3"), 233.082}, 
{TEXT("B3"), 246.942}, {TEXT("C4"), 261.626}, {TEXT("C#4"), 277.183}, {TEXT("Db4"), 277.183}, {TEXT("D4"), 293.665}, 
{TEXT("D#4"), 311.127}, {TEXT("Eb4"), 311.127}, {TEXT("E4"), 329.628}, {TEXT("F4"), 349.228}, {TEXT("F#4"), 369.994}, 
{TEXT("Gb4"), 369.994}, {TEXT("G4"), 391.995}, {TEXT("G#4"), 415.305}, {TEXT("Ab4"), 415.305}, {TEXT("A4"), 440.0}, 
{TEXT("A#4"), 466.164}, {TEXT("Bb4"), 466.164}, {TEXT("B4"), 493.883}, {TEXT("C5"), 523.251}, {TEXT("C#5"), 554.365}, 
{TEXT("Db5"), 554.365}, {TEXT("D5"), 587.33}, {TEXT("D#5"), 622.254}, {TEXT("Eb5"), 622.254}, {TEXT("E5"), 659.255}, 
{TEXT("F5"), 698.456}, {TEXT("F#5"), 739.989}, {TEXT("Gb5"), 739.989}, {TEXT("G5"), 783.991}, {TEXT("G#5"), 830.609}, 
{TEXT("Ab5"), 830.609}, {TEXT("A5"), 880.0}, {TEXT("A#5"), 932.328}, {TEXT("Bb5"), 932.328}, {TEXT("B5"), 987.767}, 
{TEXT("C6"), 1046.5}, {TEXT("C#6"), 1108.73}, {TEXT("Db6"), 1108.73}, {TEXT("D6"), 1174.66}, {TEXT("D#6"), 1244.51}, 
{TEXT("Eb6"), 1244.51}, {TEXT("E6"), 1318.51}, {TEXT("F6"), 1396.91}, {TEXT("F#6"), 1479.98}, {TEXT("Gb6"), 1479.98}, 
{TEXT("G6"), 1567.98}, {TEXT("G#6"), 1661.22}, {TEXT("Ab6"), 1661.22}, {TEXT("A6"), 1760.0}, {TEXT("A#6"), 1864.66}, 
{TEXT("Bb6"), 1864.66}, {TEXT("B6"), 1975.53}, {TEXT("C7"), 2093.0}, {TEXT("C#7"), 2217.46}, {TEXT("Db7"), 2217.46}, 
{TEXT("D7"), 2349.32}, {TEXT("D#7"), 2489.02}, {TEXT("Eb7"), 2489.02}, {TEXT("E7"), 2637.02}, {TEXT("F7"), 2793.83}, 
{TEXT("F#7"), 2959.96}, {TEXT("Gb7"), 2959.96}, {TEXT("G7"), 3135.96}, {TEXT("G#7"), 3322.44}, {TEXT("Ab7"), 3322.44}, 
{TEXT("A7"), 3520.0}, {TEXT("A#7"), 3729.31}, {TEXT("Bb7"), 3729.31}, {TEXT("B7"), 3951.07}, {TEXT("C8"), 4186.01}};

double NoteToFrequency(const WCHAR *name);


struct AudioFiles
{
	const TCHAR *name;
	const char *sample;
};

const AudioFiles samples[] = { 

{TEXT("A0al"), "A0l.wav"}, { TEXT("A0as"), "A0s.wav" }, { TEXT("A0#al"), "A0#l.wav" }, { TEXT("A0#as"), "A0#s.wav" },
{TEXT("A1al"), "A1l.wav"}, { TEXT("A1as"), "A1s.wav" }, { TEXT("A1#al"), "A1#l.wav" }, { TEXT("A1#as"), "A1#s.wav" },
{TEXT("A2al"), "A2l.wav"}, { TEXT("A2as"), "A2s.wav" }, { TEXT("A2#al"), "A2#l.wav" }, { TEXT("A2#as"), "A2#s.wav" },
{TEXT("A3al"), "A3l.wav"}, { TEXT("A3as"), "A3s.wav" }, { TEXT("A3#al"), "A3#l.wav" }, { TEXT("A3#as"), "A3#s.wav" },
{TEXT("A4al"), "A4l.wav"}, { TEXT("A4as"), "A4s.wav" }, { TEXT("A4#al"), "A4#l.wav" }, { TEXT("A4#as"), "A4#s.wav" },
{TEXT("A5al"), "A5l.wav"}, { TEXT("A5as"), "A5s.wav" }, { TEXT("A5#al"), "A5#l.wav" }, { TEXT("A5#as"), "A5#s.wav" },
{TEXT("A6al"), "A6l.wav"}, { TEXT("A6as"), "A6s.wav" }, { TEXT("A6#al"), "A6#l.wav" }, { TEXT("A6#as"), "A6#s.wav" },
{TEXT("A7al"), "A7l.wav"}, { TEXT("A7as"), "A7s.wav" }, { TEXT("A7#al"), "A7#l.wav" }, { TEXT("A7#as"), "A7#s.wav" },

{TEXT("B0al"), "B0l.wav" }, { TEXT("B0as"), "B0s.wav" },
{TEXT("B1al"), "B1l.wav" }, { TEXT("B1as"), "B1s.wav" },
{TEXT("B2al"), "B2l.wav" }, { TEXT("B2as"), "B2s.wav" },
{TEXT("B3al"), "B3l.wav" }, { TEXT("B3as"), "B3s.wav" },
{TEXT("B4al"), "B4l.wav" }, { TEXT("B4as"), "B4s.wav" },
{TEXT("B5al"), "B5l.wav" }, { TEXT("B5as"), "B5s.wav" },
{TEXT("B6al"), "B6l.wav" }, { TEXT("B6as"), "B6s.wav" },
{TEXT("B7al"), "B7l.wav" }, { TEXT("B7as"), "B7s.wav" },

{TEXT("C0al"), "C0l.wav"}, { TEXT("C0as"), "C0s.wav" }, { TEXT("C0#al"), "C0#l.wav" }, { TEXT("C0#as"), "C0#s.wav" },
{TEXT("C1al"), "C1l.wav"}, { TEXT("C1as"), "C1s.wav" }, { TEXT("C1#al"), "C1#l.wav" }, { TEXT("C1#as"), "C1#s.wav" },
{TEXT("C2al"), "C2l.wav"}, { TEXT("C2as"), "C2s.wav" }, { TEXT("C2#al"), "C2#l.wav" }, { TEXT("C2#as"), "C2#s.wav" },
{TEXT("C3al"), "C3l.wav"}, { TEXT("C3as"), "C3s.wav" }, { TEXT("C3#al"), "C3#l.wav" }, { TEXT("C3#as"), "C3#s.wav" },
{TEXT("C4al"), "C4l.wav"}, { TEXT("C4as"), "C4s.wav" }, { TEXT("C4#al"), "C4#l.wav" }, { TEXT("C4#as"), "C4#s.wav" },
{TEXT("C5al"), "C5l.wav"}, { TEXT("C5as"), "C5s.wav" }, { TEXT("C5#al"), "C5#l.wav" }, { TEXT("C5#as"), "C5#s.wav" },
{TEXT("C6al"), "C6l.wav"}, { TEXT("C6as"), "C6s.wav" }, { TEXT("C6#al"), "C6#l.wav" }, { TEXT("C6#as"), "C6#s.wav" },
{TEXT("C7al"), "C7l.wav"}, { TEXT("C7as"), "C7s.wav" }, { TEXT("C7#al"), "C7#l.wav" }, { TEXT("C7#as"), "C7#s.wav" },

{TEXT("D1al"), "D1l.wav"}, { TEXT("D1as"), "D1s.wav" }, { TEXT("D1#al"), "D1#l.wav" }, { TEXT("D1#as"), "D1#s.wav" },
{TEXT("D2al"), "D2l.wav"}, { TEXT("D2as"), "D2s.wav" }, { TEXT("D2#al"), "D2#l.wav" }, { TEXT("D2#as"), "D2#s.wav" },
{TEXT("D3al"), "D3l.wav"}, { TEXT("D3as"), "D3s.wav" }, { TEXT("D3#al"), "D3#l.wav" }, { TEXT("D3#as"), "D3#s.wav" },
{TEXT("D4al"), "D4l.wav"}, { TEXT("D4as"), "D4s.wav" }, { TEXT("D4#al"), "D4#l.wav" }, { TEXT("D4#as"), "D4#s.wav" },
{TEXT("D5al"), "D5l.wav"}, { TEXT("D5as"), "D5s.wav" }, { TEXT("D5#al"), "D5#l.wav" }, { TEXT("D5#as"), "D5#s.wav" },
{TEXT("D6al"), "D6l.wav"}, { TEXT("D6as"), "D6s.wav" }, { TEXT("D6#al"), "D6#l.wav" }, { TEXT("D6#as"), "D6#s.wav" },
{TEXT("D7al"), "D7l.wav"}, { TEXT("D7as"), "D7s.wav" }, { TEXT("D7#al"), "D7#l.wav" }, { TEXT("D7#as"), "D7#s.wav" },

{TEXT("E1al"), "E1l.wav" }, { TEXT("E1as"), "E1s.wav" },
{TEXT("E2al"), "E2l.wav" }, { TEXT("E2as"), "E2s.wav" },
{TEXT("E3al"), "E3l.wav" }, { TEXT("E3as"), "E3s.wav" },
{TEXT("E4al"), "E4l.wav" }, { TEXT("E4as"), "E4s.wav" },
{TEXT("E5al"), "E5l.wav" }, { TEXT("E5as"), "E5s.wav" },
{TEXT("E6al"), "E6l.wav" }, { TEXT("E6as"), "E6s.wav" },
{TEXT("E7al"), "E7l.wav" }, { TEXT("E7as"), "E7s.wav" },

{TEXT("F1al"), "F1l.wav"}, { TEXT("F1as"), "F1s.wav" }, { TEXT("F1#al"), "F1#l.wav" }, { TEXT("F1#as"), "F1#s.wav" },
{TEXT("F2al"), "F2l.wav"}, { TEXT("F2as"), "F2s.wav" }, { TEXT("F2#al"), "F2#l.wav" }, { TEXT("F2#as"), "F2#s.wav" },
{TEXT("F3al"), "F3l.wav"}, { TEXT("F3as"), "F3s.wav" }, { TEXT("F3#al"), "F3#l.wav" }, { TEXT("F3#as"), "F3#s.wav" },
{TEXT("F4al"), "F4l.wav"}, { TEXT("F4as"), "F4s.wav" }, { TEXT("F4#al"), "F4#l.wav" }, { TEXT("F4#as"), "F4#s.wav" },
{TEXT("F5al"), "F5l.wav"}, { TEXT("F5as"), "F5s.wav" }, { TEXT("F5#al"), "F5#l.wav" }, { TEXT("F5#as"), "F5#s.wav" },
{TEXT("F6al"), "F6l.wav"}, { TEXT("F6as"), "F6s.wav" }, { TEXT("F6#al"), "F6#l.wav" }, { TEXT("F6#as"), "F6#s.wav" },
{TEXT("F7al"), "F7l.wav"}, { TEXT("F7as"), "F7s.wav" }, { TEXT("F7#al"), "F7#l.wav" }, { TEXT("F7#as"), "F7#s.wav" },

{TEXT("G1al"), "G1l.wav"}, { TEXT("G1as"), "G1s.wav" }, { TEXT("G1#al"), "G1#l.wav" }, { TEXT("G1#as"), "G1#s.wav" },
{TEXT("G2al"), "G2l.wav"}, { TEXT("G2as"), "G2s.wav" }, { TEXT("G2#al"), "G2#l.wav" }, { TEXT("G2#as"), "G2#s.wav" },
{TEXT("G3al"), "G3l.wav"}, { TEXT("G3as"), "G3s.wav" }, { TEXT("G3#al"), "G3#l.wav" }, { TEXT("G3#as"), "G3#s.wav" },
{TEXT("G4al"), "G4l.wav"}, { TEXT("G4as"), "G4s.wav" }, { TEXT("G4#al"), "G4#l.wav" }, { TEXT("G4#as"), "G4#s.wav" },
{TEXT("G5al"), "G5l.wav"}, { TEXT("G5as"), "G5s.wav" }, { TEXT("G5#al"), "G5#l.wav" }, { TEXT("G5#as"), "G5#s.wav" },
{TEXT("G6al"), "G6l.wav"}, { TEXT("G6as"), "G6s.wav" }, { TEXT("G6#al"), "G6#l.wav" }, { TEXT("G6#as"), "G6#s.wav" },
{TEXT("G7al"), "G7l.wav"}, { TEXT("G7as"), "G7s.wav" }, { TEXT("G7#al"), "G7#l.wav" }, { TEXT("G7#as"), "G7#s.wav" },

{TEXT("pedald"), "pedald.wav"}, { TEXT("pedalu"), "pedalu.wav" }

};

double NoteToAudioFile(const WCHAR* name);