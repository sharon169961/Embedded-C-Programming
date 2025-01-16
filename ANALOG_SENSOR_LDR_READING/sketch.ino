// Reference https://docs.wokwi.com/parts/wokwi-photoresistor-sensor

// Using Arduino board as there is memory overflow when using STM32 for analogRead and Serial

#define sensorPin A0

// These constants should match the photoresistor's "gamma" and "rl10" attributes
const float GAMMA = 0.7;
const float RL10 = 50;

void setup() {
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Convert the analog value into lux value:
  int analogValue = analogRead(sensorPin);
  float voltage = analogValue / 1024. * 5;
  float resistance = 2000 * voltage / (1 - voltage / 5);
  float lux = pow(RL10 * 1e3 * pow(10, GAMMA) / resistance, (1 / GAMMA));
  Serial.print("Lux: ");
  Serial.println(lux);

  delay(50); // this speeds up the simulation
}
