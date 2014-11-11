

//Hot Rod Lincoln
char hrl[] = "-----2-----.-----.-----.-----.-----.-----.-----.-----0-----0-----4-----4----2-----2-----4-----2-----5-----2-----4-----5-----4-----2------3-----4----0-----0-----4-----4----2-----2-----4-----2-----5-----2-----4-----5-----4-----2------3-----4-----2-----2----1-----1-----4-----4----1------4----2------4----1-----2-----1------4-----0-----1-----2-----2------4-----2----2-----2------4-----2----2------4-----2----2-----.-----.--001220......----20----..----..----..----..----..----..----..----..----..----..----..----..----..----..----..----..----..----..----..----..----..----..----..----..\0";
int hrlTime = 200

const char *song_table[]=
{
  hrl,
  hrlTime,
}



//Pin connected to ST_CP of 74HC595
int latchPin = 7;
//Pin connected to SH_CP of 74HC595
int clockPin = 13;
////Pin connected to DS of 74HC595
int dataPin = 11;

int masterResetPin = 8;
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
int rhInPin6;
int rhOutPin6;



long time_start = 0
unsigned long leftHand = 0;
unsigned int rh1; unsigned int rh2; unsigned int rh3; unsigned int rh4; unsigned int rh5; unsigned int rh6;

void setup() {
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(masterResetPin, OUTPUT);
}

void loop()
{
//USERINPUT to assign notes
  //static note =silent;
  if (input){
  notes = (char*)(&(song_table[i]));
  timer = (int*)(&(song_table[i+1]));
  }
  if(timetodostuff(timer) && notes !="\0")
  {
    playnote();
    time_start = millis();
    getnextnote(leftHand, rh1, rh2, rh3, rh4, rh5, rh6);
    
  }
}    



bool timetodostuff(timer){
  if millis() - time_start < timer{return false}
  else{return true}
}

bool getnextnote(unsigned long & leftHand, unsigned int & rh1, unsigned int & rh2, unsigned int & rh3, unsigned int & rh4, unsigned int & rh5, unsigned int & rh6){
  value1 = notes[i]
  value2 = notes[i+1]
  value3 = notes[i+2]
  value4 = notes[i+3]
  value5 = notes[i+4]
  value6 = notes[i+5]
  
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
  
  state6 = strum(value6, states6, strum6Right, strum6Left);       
  state5 = strum(value5, states5, strum5Right, strum5Left);         
  state4 = strum(value4, states4, strum4Right, strum4Left);
  state3 = strum(value3, states3, strum3Right, strum3Left);
  state2 = strum(value2, states2, strum2Right, strum2Left);
  state1 = strum(value1, states1, strum1Right, strum1Left);
  
  
  return True
 
}
bool playNote(){
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
      
      digitalWrite(state6, HIGH)
      digitalWrite(state5, HIGH)
      digitalWrite(state4, HIGH)
      digitalWrite(state3, HIGH)
      digitalWrite(state2, HIGH)
      digitalWrite(state1, HIGH)
      digitalWrite(state6, LOW)
      digitalWrite(state6, LOW)
      digitalWrite(state5, LOW)
      digitalWrite(state4, LOW)
      digitalWrite(state3, LOW)
      digitalWrite(state2, LOW)
      digitalWrite(state1, LOW)
      
      digitalWrite(masterResetPin,LOW);
    }

unsigned int pushdownfret(String x, unsigned int out){

unsigned int dataout; 
  if(x == "."){
    dataout = out;
}
        
  else if(x == "-"){
       dataout = B00000;  
  }   
  else if(x == "1"){
      dataout = B00001;  
  }
  else if(x == "2"){
      dataout = B00010;  
  }
  else if(x == "3"){
      dataout = B00100;     
  }
  else if(x == "4"){
      dataout = B01000;
   }
  else if(x == "5"){
      dataout = B10000;  
  }

  else if(x == "0"){
 
      dataout = B00000;
  }

  return dataout;
}


unsigned int strum(String x, unsigned int states, int right, int left){
  unsigned int stateout;
  if (x=="0" || x=="1" || x=="2" || x=="3" || x=="4" || x=="5"){
    if (states == right){
      stateout= left;
    }
    else{
      stateout = right;
    }
  }
  else{
    stateout = states;
  }
   return stateout;
}
