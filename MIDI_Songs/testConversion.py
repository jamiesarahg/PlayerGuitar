
from __future__ import division
import mido
k=0
mid = mido.MidiFile('Tamacun_POE_Octave.mid')
def mapToString(note):
    if note == 52:
        return (0,'0')
    if note == 53:
        return (0,'1')
    if note == 54:
        return (0,'2')
    if note == 55:
        return (0,'3')
    if note == 56:
        return (0,'4')
    if note == 57:
        return (1,'0')
    if note == 58:
        return (1,'1')
    if note == 59:
        return (1,'2')
    if note == 60:
        return (1,'3')
    if note == 61:
        return (1,'4')
    if note == 62:
        return (2,'0')
    if note == 63:
        return (2,'1')
    if note == 64:
        return (2,'2')
    if note == 65:
        return (2,'3')
    if note == 66:
        return (2,'4')
    if note == 67:
        return (3,'0')
    if note == 68:
        return (3,'1')
    if note == 69:
        return (3,'2')
    if note == 70:
        return (3,'3')
    if note == 71:
        return (4,'0')
    if note == 72:
        return (4,'1')
    if note == 73:
        return (4,'2')
    if note == 74:
        return (4,'3')
    if note == 75:
        return (4,'4')
    if note == 76:
        return (5,'0')
    if note == 77:
        return (5,'1')
    if note == 78:
        return (5,'2')
    if note == 79:
        return (5,'3')
    if note == 80:
        return (5,'4')
    if note == 81:
        return (5,'5')
import time
for i, track in enumerate(mid.tracks):
    smallest = 10000000
    total = 0
    for message in track:
        if message.time != 0 and message.time !=1:
            total = total+ message.time
            if message.time < smallest:
                smallest = message.time
                
        if message.type == "time_signature":
            notated32perBeat = message.notated_32nd_notes_per_beat
        if message.type == "set_tempo":
            tempo = message.tempo
            print "YES"
            

# print smallest
# print total
itemsInString = total//smallest *6
#print itemsInString


timer = tempo*(1/1000)*(8/notated32perBeat)*(smallest/256)



out = list("."*itemsInString)

j=0 #where we are in out

for i, track in enumerate(mid.tracks):
    #print('Track {}: {}'.format(i, track.name))
    for message in track:
		if message.type == "note_off" or message.type == "note_on":
			note = message.note
			if message.type == "note_off":
				j = message.time//smallest + j
				x,y = mapToString(message.note)
				out[j+x] = "-"
			if message.type == "note_on":
				j = message.time//smallest + j
				print message
				print message.note
				x,y = mapToString(message.note)
				out[j+x] = y

			
		
outStr = ''.join(out)
print outStr
print timer
