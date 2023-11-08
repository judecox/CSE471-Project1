# Effects
Component created by Ryan Chang

## Components
### Noise Gate
#### Description
A noise gate reduces audible noise in the signal by essentially muting the
signal once it falls below a certain point.

Our noise gate features attack, open, hold, and release stages, to allow for
maximal control over the effect, and to avoid the click that can be produced
when suddenly muting the signal.

#### Parameters
The effect can be controlled via the threshold, attack, hold, and release
parameters defined as attributes on the noise gate's XML tag.

The threshold parameter controls the volume at which the noise gate starts to
close. The valid range for this parameter is [0, 1], where 0 is no signal
amplitude and 1 is maximal signal amplitude.

The hold parameter controls how long to hold the gate open even if the signal
falls below the threshold. Its valid range is [0, inf), and represent the
duration of the holding stage in seconds.

The attack and release parameters control the duration, in seconds, of the
attack and release stages. Both of their valid ranges are also [0, inf).

### Compression/Limiting
#### Description
Compression limits the dynamic range of a signal by either increasing quiet
sounds (upwards compression) or decreasing load sounds (downwards compression).
Our compression effect supports both.

Like the noise gate, our compression effect features attack, open, and release
stages. They serve the same purpose as they do in the noise gate; they avoid
sudden changes in the output of the signal. We also support additional
parameters, outlined below.

#### Parameters
The effect is controlled via the threshold, ratio, attack, release, and
isUpwards parameters. The threshold parameter determines at which amplitude to
start the effect. The valid range is [0, 1], where 0 is no signal amplitude and
1 is maximal signal amplitude.

Whether the effect triggers once the signal is greater than or less than the
threshold depends on the isUpwards parameter. It is a boolean value that
determines whether or not to perform upwards or downwards compression. The valid
options are true or false.

The ratio measures the strength of the effect. It is commonly represented as
X:Y, where X is the input level and Y is the output level. As a parameter, this
is simply the decimal representation of the fractional value of the ratio. If X
is less than Y, then the effect will function as an expander instead. The valid
range is [0, inf). Values greater than 1 will make the effect function as a
compressor. Values less than one makes it function as an expander.

### Chorus
#### Description
Our chorus effect is loosely based off of the Boss CH1 Super Chorus, as outlined
in rolandmedia's [EFFECTS 101:
Chorus]("https://www.youtube.com/watch?v=zmN7fK3fKUE"). Like the hardware shown
in the video, our effect supports rate, amount, and mix/wetness, although most
of those parameters are named differently on the CH1. Multiple chorus effects
can be combined via parallel effect to introduce multiple voices.

To support delay, we've implemented a circular loop that holds the past input
signals. This loop resizes itself if the delay is changed.

#### Parameters
The rate controls the warbling of the effect. Higher values increase the
frequency of the sine wave controlling the effect. The valid range is (0, inf).
The sine wave only affects the past samples in the circular loop.

The amount controls the amplitude of the sine wave, and determines how prominent
the effect is. The valid range is (0, inf).

The phase parameter controls the initial phase of the sine wave. Any number is
valid for this parameter.

The mix/wetness parameter controls how much of the effect is present in the
final output. 0 makes the output based entirely on they input, and 1 makes the
output based entirely on past inputs. The valid range is [0, 1].

The delay controls how far back in time audio samples are selected from the
loop, in seconds. The valid range is [0, inf).

### Flanging
#### Description
Flanging is very similar to chorus, except it is more often used to create a
distorted, pronounced effect. Specifically, the flanger uses feedback, which
controls how much of the calculated output is placed in the circular loop.

#### Parameters
All the parameters are the same as they are in the chorus effect. However, the
flanger lacks the delay parameter, which is instead calculated using the
amplitude, as the hardware I based this off of lacks such a control.

Instead, it has a feedback parameter, which is outlined above in the
description. The valid range is [0, 1].

### Parallel and Sequential Effects
#### Description
Parallel and sequential effects are achieved by using special effects that
contain references to other effects. In the XML file, these effects are
represented by storing the child effects as leaves under the parallel/sequential
effects. This allows us to specify any combination of parallel and sequential
effects, and even allows us to nest parallel and sequential effects within other
parallel and sequential effects.

### Effects Send
#### Description
Since the effects were stored as their own components separated from the notes
and instruments, it was easiest to give each effect an ID and allow notes to
reference that ID in order to choose specific effects.

