#include <avr/pgmspace.h>
#include <Boards.h>
#include <Firmata.h>
#include <stdlib.h> 

prog_char a[] PROGMEM = "1";
prog_char b[] PROGMEM = "b";
prog_char c[] PROGMEM = "c";
prog_char d[] PROGMEM = "d";
prog_char e[] PROGMEM = "e";

PROGMEM const char *song_table[]=
{
  a,
  b,
  c,
  d,
  e
};

char buffer[10];
void setup(){
  Serial.begin(9600);
}

void loop(){
//    strcpy_P(buffer, (char*)pgm_read_word(&(a))); // Necessary casts and dereferencing, just copy. 
//    Serial.println( buffer );
//    strcpy_P(buffer, (char*)pgm_read_word(&(b))); // Necessary casts and dereferencing, just copy. 
//    Serial.println( buffer );
//    strcpy_P(buffer, (char*)pgm_read_word(&(c))); // Necessary casts and dereferencing, just copy. 
//    Serial.println( buffer );
//    strcpy_P(buffer, (char*)pgm_read_word(&(d))); // Necessary casts and dereferencing, just copy. 
//    Serial.println( buffer );
//    strcpy_P(buffer, (char*)pgm_read_word(&(e))); // Necessary casts and dereferencing, just copy. 
//    Serial.println( buffer );
 
  for (int i = 0; i < 5; i++)
  {
    Serial.println("FUCK");
    strcpy_P(buffer, (char*)pgm_read_word(&(song_table[i]))); // Necessary casts and dereferencing, just copy. 
    Serial.println("after");
    Serial.println( buffer );
    delay( 500 );
  }
}
//
//    strcpy_P(buffer, (char*)pgm_read_word(&(song_table[2]))); // Necessary casts and dereferencing, just copy. 
//    Serial.println( buffer );
//    }
//    
