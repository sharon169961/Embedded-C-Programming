// Reference https://docs.wokwi.com/parts/wokwi-ntc-temperature-sensor

#define sensorPin A0
#define BETA 3950

int ledArray[] = {4,5,6,7,8,9,10,11,12,13};
float minTemp= -24.0;
float maxTemp= 80.0;

void setup() {
    // initialize LEDs and sensor pin

    for (int i=0; i<10; i++){
      pinMode(ledArray[i],OUTPUT);
    }
    
}

void loop() {
  // Read the sensor value , calculate the temperature, light up the leds

  float temp=analogRead(sensorPin);
  float resistance = (1023.0 / temp - 1.0) * 10000; // Assuming a 10k pull-up resistor
  float temperature = 1.0 / (log(resistance / 10000.0) / BETA + 1.0 / 298.15) - 273.15;

  int numLed=map(temperature,minTemp,maxTemp,0,10 );
  numLed=constrain(numLed, 0,10);

  for(int i=0;i<10;i++){
    if(i<numLed){
      digitalWrite(ledArray[i],LOW);

    }

    else{
      digitalWrite(ledArray[i],HIGH);
    }
  }
  
  delay(100); // this speeds up the simulation
}
