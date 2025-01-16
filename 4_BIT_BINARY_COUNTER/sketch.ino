
int ledPin[] = {13, 12, 11,10};
int ledDelay[]={8000, 4000,2000, 1000};//delays for each LED
unsigned long lastChangeTime[4];//last toggle time for each LED
int ledState[4]={LOW,LOW,LOW,LOW};//Current state for each LED
// declare other required variables
int currTime;

void setup() {
  
  for(int i=0;i<4;i++){
    // initialize lastChangeTimes
    pinMode(ledPin[i],OUTPUT);
    lastChangeTime[i]=0;
    
    // set pin mode for ledPins
    
  }
}


void loop() {
  // implement the toggling logic

  unsigned long currTime=millis();
  //Iterate through each LED and check if its time to toggle
  for(int i=0; i<4; i++){
    if (currTime-lastChangeTime[i] >= ledDelay[i]){
      ledState[i] = !ledState[i];
      digitalWrite(ledPin[i], ledState[i]);

      lastChangeTime[i]=currTime;
    }
  }

  
}
