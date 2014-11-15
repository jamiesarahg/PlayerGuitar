import mido
#mid = mido.MidiFile('Tamacun_POE_Octave.mid')
mid = mido.MidiFile('TestMIDI.mid')
j=0
for i, track in enumerate(mid.tracks):
    print('Track {}: {}'.format(i, track.name))
    for message in track:
    	if j< 50:
	        print(message)
	        j+=1
