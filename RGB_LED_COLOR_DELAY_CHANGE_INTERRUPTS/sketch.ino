#define colorBtn 6
#define durationBtn 7

#define redPin 13
#define yellowPin 12
#define bluePin 11


bool colors[][3] = {
  {1,1,1} , {1,0,0},{0,1,0},{0,0,1},  // wrgb
  {0,1,1} , {1,1,0},{1,0,1},{0,0,0} // cymk
};
char* colorNames[] = {
  "white","red","green","blue",
  "cyan","yellow","megenta","black" // black is just off so do not need to toggle to black
};

int delays[] = {
  1000, 800, 600, 400, 200
};

volatile int lastColorPress=0;
volatile int lastDurationPress=0;

volatile int currentColorIndex=0;
volatile int currentDurationIndex=0;

unsigned long prevTime=0;
bool ledState=false;

void setup() {

  pinMode(redPin, OUTPUT);
  pinMode(yellowPin,OUTPUT);
  pinMode(bluePin,OUTPUT);

  pinMode(colorBtn, INPUT_PULLUP);
  pinMode(durationBtn, INPUT_PULLUP);

  //attach interrupts

  attachInterrupt(digitalPinToInterrupt(colorBtn),changeClr,FALLING);
  attachInterrupt(digitalPinToInterrupt(durationBtn),changeDuration,FALLING);

  Serial.begin(9600);
  Serial.print("RGB LED CONTROLLER INITIALIZED");
  Serial.print("Color:");
  Serial.println(colorNames[currentColorIndex]);
  Serial.print("duration:");
  Serial.println(delays[currentDurationIndex]);





  
}

void loop() {

  unsigned long currentmillis=millis();
  if(currentmillis-prevTime >= delays[currentDurationIndex]){
    prevTime=currentmillis;
    ledState= !ledState;
    updateLed();
  }


}


void changeClr(){

  unsigned long currentmillis=millis();
  if(currentmillis-lastColorPress>200){
    //debounce checker
    lastColorPress=currentmillis;
  

  currentColorIndex=(currentColorIndex+1)%7;
  Serial.print("Color: ");
  Serial.println(colorNames[currentColorIndex]);
  updateLed();

  }



}


void changeDuration(){
  unsigned long currentmillis=millis();
  if(currentmillis-lastDurationPress>200){
    //debounce check

    lastDurationPress=currentmillis;
    currentDurationIndex=(currentDurationIndex+1)%3;
    Serial.print("Duration:");
    Serial.println(delays[currentDurationIndex]);
  }
}

void updateLed(){
  //If LED is on, set it to current color else turn it off

  if(ledState){
    digitalWrite(redPin,colors[currentColorIndex][0]);
    digitalWrite(yellowPin,colors[currentColorIndex][1]);
    digitalWrite(bluePin,colors[currentColorIndex][2]);
  }

  else{
    digitalWrite(redPin,LOW);
    digitalWrite(yellowPin,LOW);
    digitalWrite(bluePin,LOW);
  }
}
