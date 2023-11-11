Wavetable was made by Alec Charney

For my part of the project, I made a wavetable. Here are the different features as described by the grading rubric:

**Wave Playback on demand**
When an XML asks for notes of instrument type "wavetable", a wavetable instrument is created and generates the audio needed.

**Envelope Generation**
This component uses the AR class defined elsewhere in this project. The AR modifies the generated sound source, facilitating attack and release.

**Pitch**
When asked to play a note, the waveform attached to the wavetable loads the sound sample indicated by the note's name into a multidimensonal vector. Each pitch from C1 to B4 has a different sample that is only loaded in the first time that note is to be played and retrieved from the storage vector any time afterwards.

**Loop Points**
The start and end times of a loopable sequence in the samples are stored in the waveform. If the waveform reaches the loop end but the note duration has not been reached, the waveform's playback time is set back to the loop start. (This repitition sounds somewhat buzzing and noisy - this is due to the sample used and not the way the looping was programmed; please do not listen to the playback with headphones and/or wth high volume)

**Glissando**
On notes marked with a "gliss" parameter in the XML score, the wavetable will play all the notes in-between the marked note and the note specified in the "gliss" parameter one at a time to produce a discreet glissando effect. This glissando can go up and down and is entirely non-present on notes without a "gliss" parameter.
