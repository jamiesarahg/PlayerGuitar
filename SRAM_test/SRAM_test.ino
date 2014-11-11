//#include <avr/pgmspace.h>
#include <Boards.h>
#include <Firmata.h>
#include <stdlib.h> 

char a[] = "1";
char b[] = "b";
char c[] = "c";
char d[] = "d";
char e[] = "e";

const char *song_table[]=
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
  
  buffer = (char*)(&(a))
  Serial.println(buffer);
  
  
  
    strcpy(buffer, (char*)(&(a))); 
    Serial.println( buffer );
    strcpy(buffer, (char*)(&(b))); 
    Serial.println( buffer );
    strcpy(buffer, (char*)(&(c))); 
    Serial.println( buffer );
    strcpy(buffer, (char*)(&(d)));  
    Serial.println( buffer );
    strcpy(buffer, (char*)(&(e))); 
    Serial.println( buffer );
 
  for (int i = 0; i < 5; i++)
  {
    Serial.println("FUCK");
    strcpy(buffer, (char*)(&(song_table[i]))); // Necessary casts and dereferencing, just copy. 
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
