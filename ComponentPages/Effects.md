# Effects
Component created by Ryan Chang

## Components
### Noise Gate

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

