# Effects
Component created by Ryan Chang

## Components
### Noise Gate
A noise gate reduces audible noise in the signal by essencially muting the
signal once it falls below a certain point. This can reduce the buzz from
electronic audio equiptment, for example.

Our noise gate features attack, open, and release stages, to allow for
maximal control over the effect, and to avoid the click that can be produced
when suddenly muting the signal.

The effect can be controlled via the threshold, attack, hold, and release
parameters defined as attributes on the noise gate's XML tag. The threshold
controls the volumn at which the noise gate starts to close. The other
parameters control the duration, in seconds, of the attack, open, and release
stages.

### Compression/Limiting

### Chorus

### Flanging

### Parallel and Sequencial Effects
Parallel and sequencial effects are achieved by using special effects that
contain references to other effects. In the XML file, these effects are
represented by storing the child effects as leaves under the
parallel/sequencial effects. This allows us to specify any combination of
parallel and sequencial effects, and even allows us to nest parallel and
sequencial effects within other parallel and sequencial effects.

### Effects Send
Since the effects were stored as their own components seperated from the notes
and instruments, it was easist to give each effect an ID and allow notes to
referrence that ID in order to choose specific effects.

