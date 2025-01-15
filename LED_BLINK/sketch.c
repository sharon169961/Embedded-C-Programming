
#define LED_PIN 13

void setup(){
  pinMode(LED_PIN, OUTPUT);
}


void loop(){

  digitalWrite(LED_PIN, HIGH);
  //wait for 1000 seconds
  delay(1000);

  digitalWrite(LED_PIN,LOW);
  delay(1000);
}
