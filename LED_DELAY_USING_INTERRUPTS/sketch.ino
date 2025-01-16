#include <utils.h>

#define ledPin 13
#define btnPin 12


int ledDelays[3] = {1000,500,200};
volatile int current=0;
volatile bool buttonPressed=false;

void setup() {
  // initialize pins, variables, interrupts and serial
  pinMode(ledPin, OUTPUT);
  pinMode(btnPin, INPUT_PULLUP);


//Attach an Interrupt to the push Button
  attachInterrupt(digitalPinToInterrupt(btnPin),btnPressHandler,FALLING);
  Serial.begin(9600);
  Serial.println("System Initialized");
  Serial.print("Blink duration:");
  Serial.print(ledDelays[current]);
}

void btnPressHandler(){
  // interrupt handler ISR also account for debouncing

  static unsigned long lastInterruptTime=0;
  unsigned long interruptTime = millis();
  if (interruptTime-lastInterruptTime > 200){
    current=(current+1)%3;
    buttonPressed=true;

  }

  lastInterruptTime=interruptTime;

  
  
}

void loop() {
  // code for led blinking with selected delay
  if (buttonPressed){
    Serial.print("Blink duration: ");
    Serial.print(ledDelays[current]);
    buttonPressed=false;
  }

  delay(10); 
  
  
digitalWrite(ledPin, HIGH);
delay(ledDelays[current]/2);
digitalWrite(ledPin, LOW);
delay(ledDelays[current]/2);// this speeds up the simulation
}
