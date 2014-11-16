#include <iostream>     // std::cout, std::ostream, std::hex
#include <sstream>      // std::stringbuf
#include <string>       // std::string

//Hot Rod Lincoln
char hrl[] = "-----2-----.-----.-----.-----.-----.-----.-----.-----0-----0-----4-----4----2-----2-----4-----2-----5-----2-----4-----5-----4-----2------3-----4----0-----0-----4-----4----2-----2-----4-----2-----5-----2-----4-----5-----4-----2------3-----4-----2-----2----1-----1-----4-----4----1------4----2------4----1-----2-----1------4-----0-----1-----2-----2------4-----2----2-----2------4-----2----2------4-----2----2-----.-----.--001220......----20----..----..----..----..----..----..----..----..----..----..----..----..----..----..----..----..----..----..----..----..----..----..----..----..";
int hrlTime = 200;

//Tamacun
//char* tamacun = new char[3000];

char tamacun[]= "....1..22--2.-1...0..00--0.-0...3...1..02--0.-1...3...1...0..2-1...-1..22--2.-1...0..00--0.-0...3...1..02--0.-1...3...1...-0..3-0...1..22--2.-1...0..00--0.-0...3...1..02--0.-1...3...1...0..2-1...-1..22--2.-1...0..00--0.-0...3...1..02--0.-1...3.2.-0.-1.3...-0..1-.22--2.-1...0..00--0.-0...3...1..02--0.-1...3...1...0..2-1...-1..22--2.-1...0..00--0.-0...3...1..02--0.-1...3...1...-0..3-0...1..22--2.-1...0..00--0.-0...3...1..02--0.-1...3...1...0..2-1...-1..22--2.-1...0..00--0.-0...3...1..02--0.-1...3...1.02-1..2-..-......0..1-.2-..-0...1...3...1...-.2...-2...-1...0.1.0..2-..1...-.....0..1-.2-..-0...1...3...-0...-.0...-.3...1...0..3-..1..2-..-.....0..1-.2-..-0...1...3...1...-.2...-2...-1...0.1.0..2-..1..2-..-2...-1...-0..3-..1...0...-3.0.-.-.1.0.-.-.0.0.-.-3.31-..2...-.....0..1-.2-..-0...1...3...1...-.2...-2...-1...0.1.0..2-..1...-.....0..1-.2-..-0...1...3...-0...-.0...-.3...1...0..3-..1..2-..-.....0..1-.2-..-0...1...3...1...-.2...-2...-1...0.1.0..2-..1..2-..-2...-1...-0..3-..1...0...-3.0.-.-.1.0.-.-.0.0.-.-3.31-..2...-..20201.--20---...3.3.0.-.3.-.-...20201.--20---...3.3.0.-.3.-.-...20201.--20---...3.3.0.-.3.-.-...20201.--20---....10100.--10---..20201.--20---...3.3.0.-.3.-.-...20201.--20---...3.3.0.-.3.-.-...20201.--20---...3.3.0.-.3.-.-...20201.--20---10101010100.....2--.........0.............3.-.........-2...............-2...........0.............3.-.........-2...............-2...........0.............3.-.........-2...............-2...........0.............3.-.........-2...............3.-.0.3.-0.1.1...1...0...0.0..3-3.3...1.1.1...0.1.3.1.02-13-2.0.2.-.0...1.3...1.132--0.......0.4.-2.-0.2.3.-.0.3.1.02-1.02-03--..0.3...3.3...1.1.1.-0...0.0..3-3.3.-1...1.1...0.0.0.4...3.1...3.010...0.1.3.1.0.1.0..3--0.1.03--03-..1.3.-03-1.3.0.......-.......123--2.-1.3.1...123--2.-1.-01-..123--2.-1.3.2.-.3.-02--.1.3.1...012--1.-0.1.0...012--1.-0.3.0...012--1.-0.1.2.-.1.3.2.-.0.1.0..23-0.3.-2.-02-..23-0.3.-2.-12-..23-0.3.-2.-020--.0.1.0.-.1.3.2.-1.2.12--2.-022--.0.1.2.-.1.3.2.-..0000000011111111333333334.......-...0..1-.2-..-0...1...3...1...-.2...-2...-1...0.1.0..2-..1...-.....0..1-.2-..-0...1...3...-0...-.0...-.3...1...0..3-..1..2-..-.....0..1-.2-..-0...1...3...1...-.2...-2...-1...0.1.0..2-..1..2-..-2...-1...-0..3-..1...0...-3.0.-.-.1.0.-.-.0.0.-.-3.31-..2...-.....0..1-.2-..-0...1...3...1...-.2...-2...-1...0.1.0..2-..1...-.....0..1-.2-..-0...1...3...-0...-.0...-.3...1...0..3-..1..2-..-.....0..1-.2-..-0...1...3...1...-.2...-2...-1...0.1.0..2-..1..2-..-2...-1...-0..3-..1...0...-3.0.-.-.1.0.-.-.0.0.-.-3.31-..2...2.------";

int tamacunTime = 60;

const int MAX= 10;
 char *song_table[MAX]=
{
  hrl,
  tamacun,
};

int timer_table[MAX]=
{
  //200,
  hrlTime,
  tamacunTime,
};

char actuators[] = "000000";
int pins[6]= {};
char note;
int timer;
char * notesP;
//Pin connected to ST_CP of 74HC595
int latchPin = 7;
//Pin connected to SH_CP of 74HC595
int clockPin = 13;
////Pin connected to DS of 74HC595
int dataPin = 11;

int masterResetPin = 8;

int rhInPin0;
int rhOutPin0;
int rhInPin1;
int rhOutPin1;
int rhInPin2;
int rhOutPin2;
int rhInPin3;
int rhOutPin3;
int rhInPin4;
int rhOutPin4;
int rhInPin5;
int rhOutPin5;




long time_start = 0;
unsigned long leftHand = 0;
unsigned int rh1; unsigned int rh2; unsigned int rh3; unsigned int rh4; unsigned int rh5; unsigned int rh6;

void setup() {
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(masterResetPin, OUTPUT);
  
  pinMode(rhInPin0, OUTPUT);
  pinMode(rhOutPin0, OUTPUT);
  pinMode(rhInPin1, OUTPUT);
  pinMode(rhOutPin1, OUTPUT);
  pinMode(rhInPin2, OUTPUT);
  pinMode(rhOutPin2, OUTPUT);
  pinMode(rhInPin3, OUTPUT);
  pinMode(rhOutPin3, OUTPUT);
  pinMode(rhInPin4, OUTPUT);
  pinMode(rhOutPin4, OUTPUT);
  pinMode(rhInPin5, OUTPUT);
  pinMode(rhOutPin5, OUTPUT);
  
}


  bool input = true;
void loop()
{
//USERINPUT to assign notes
  //static note =silent;

  char note;
  long int time;
  if (input){
    int i;
    i=0;
   notesP = song_table[i];
  time = timer_table[i];
  input = false;
  
  // SET ACTUATORS TO ALL 0
  //Serial.println("hi");
  }

  note = *notesP;
 
  if(timetodostuff(time))// && note !='\0')
  {
    playNote();
    time_start = millis();
    getnextnote(leftHand);
   
   }
}    


bool timetodostuff(int timer){
  if (millis() - time_start < timer){return false;}
  else{return true;}
}

bool getnextnote(unsigned long &leftHand){//, unsigned int &rh1, unsigned int &rh2, unsigned int &rh3, unsigned int &rh4, unsigned int &rh5, unsigned int &rh6){
  char value1; char value2; char value3; char value4; char value5; char value6;
  unsigned int outs1; unsigned int outs2; unsigned int outs3; unsigned int outs4; unsigned int outs5; unsigned int outs6; unsigned int out1; unsigned int out2; unsigned int out3; unsigned int out4; unsigned int out5; unsigned int out6;

  value1 = *notesP;
  notesP = notesP+1;
  value2 = *notesP;
  notesP = notesP+1;
  value3 = *notesP;
  notesP = notesP+1;
  value4 = *notesP;
  notesP = notesP+1;
  value5 = *notesP;
  notesP = notesP+1;
  value6 = *notesP;
  notesP = notesP+1;

  
  out6 = pushdownfret(value6, outs6);
      outs6 = out6;
  out5 = pushdownfret(value5, outs5);
      outs5 = out5;
  out4 = pushdownfret(value4, outs4);
      outs4 = out4;
  out3 = pushdownfret(value3, outs3);
      outs3 = out3;
  out2 = pushdownfret(value2, outs2);
      outs2 = out2;
  out1 = pushdownfret(value1, outs1);
      outs1 = out1;
  leftHand =(out6 << 25) + (out5<<20) + (out4<<15) + (out3<<10) + (out2<<5) + out1;
  
  strum(value6, 5, rhInPin5, rhOutPin5);       
  strum(value5, 4, rhInPin4, rhOutPin4);         
  strum(value4, 3, rhInPin3, rhOutPin3);
  strum(value3, 2, rhInPin2, rhOutPin2);
  strum(value2, 1, rhInPin1, rhOutPin1);
  strum(value1, 0, rhInPin0, rhOutPin0);

  return true;
 
}
bool playNote(){
   unsigned long shiftreg1; unsigned long shiftreg2; unsigned long shiftreg3; unsigned long shiftreg4; unsigned long shiftreg5; unsigned long shiftreg6;
  
  
    shiftreg1 = leftHand >> 24;
    shiftreg2 = (leftHand - (shiftreg1<<24)) >>16;
    shiftreg3 = (leftHand - (shiftreg1<<24) - (shiftreg2<<16)) >>8;
    shiftreg4 = (leftHand - (shiftreg1<<24) - (shiftreg2<<16) - (shiftreg3<<8)); 
      
    digitalWrite(masterResetPin,HIGH);
    digitalWrite(latchPin,LOW); //Prepares latch
    
    shiftOut(dataPin, clockPin, LSBFIRST, shiftreg4);
    shiftOut(dataPin, clockPin, LSBFIRST, shiftreg3);
    shiftOut(dataPin, clockPin, LSBFIRST, shiftreg2);
    shiftOut(dataPin, clockPin, LSBFIRST, shiftreg1);
    
    digitalWrite(latchPin,HIGH); //Prepares latch
    Serial.println("newNote");
    for (int j=0; j<6; j++){
      if (pins[j] != 0){
        digitalWrite(pins[j],HIGH);
        digitalWrite(pins[j],LOW);
       // Serial.println(pins[j]);
     }    
    }
      digitalWrite(masterResetPin,LOW);
      pins[0]= 0;
      pins[1]= 0;
      pins[2]= 0;
      pins[3]= 0;
      pins[4]= 0;
      pins[5]= 0;

  }
   
unsigned int pushdownfret(char x, unsigned int out){

unsigned int dataout; 
  if(x == '.'){
    dataout = out;
  }    
  else if(x == '-'){
       dataout = B00000;  
  }   
  else if(x == '1'){
      dataout = B00001;  
  }
  else if(x == '2'){
      dataout = B00010;  
  }
  else if(x == '3'){
      dataout = B00100;     
  }
  else if(x == '4'){
      dataout = B01000;
   }
  else if(x == '5'){
      dataout = B10000;  
  }
  else if(x == '0'){
      dataout = B00000;
  }
  return dataout;
}


void strum(char x, int string, int in, int out){
  if (x=='0' || x=='1' || x=='2' || x=='3' || x=='4' || x=='5'){
    if (actuators[string] == 1){
      pins[string] = in;
      actuators[string] = 0;
    }
    else{
      pins[string] = out;
      actuators[string] = 1;
    }
  }

}
