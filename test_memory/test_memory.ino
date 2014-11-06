#include <avr/pgmspace.h>
#include <Boards.h>
#include <Firmata.h>
#include <stdlib.h> 

prog_char a PROGMEM = "1"
prog_char b PROGMEM = "2"
prog_char c PROGMEM = "3"
prog_char d PROGMEM = "4"
prog_char e PROGMEM = "5"

PROGMEM const char *song_table[]=
{
  a,
  b,
  c,
  d,
  e
};

void setup(){
  Serial.begin(9600);
}

void loop(){
  
  for (int i = 0; i < 5; i++)
  {
    strcpy_P(buffer, (char*)pgm_read_word(&(song_table[i]))); // Necessary casts and dereferencing, just copy. 
    Serial.println( buffer );
    delay( 500 );
  }
}
}

