#define LED1 13
#define LED2 9
#define BUTTON1 12 // Internal pull-up mode
#define BUTTON2 8  // Internal pull-up mode

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BUTTON1, INPUT_PULLUP); // Enable internal pull-up resistor
  pinMode(BUTTON2, INPUT_PULLUP); // Enable internal pull-up resistor
}

void loop() {
  // Read button states
  int buttonstate1 = digitalRead(BUTTON1); // LOW when pressed
  int buttonstate2 = digitalRead(BUTTON2); // LOW when pressed

  // Control LED1 for BUTTON1
  if (buttonstate1 == LOW) {
    digitalWrite(LED1, HIGH); // Turn LED1 ON
  } else {
    digitalWrite(LED1, LOW); // Turn LED1 OFF
  }

  // Control LED2 for BUTTON2 (invert logic since it's now pull-up)
  if (buttonstate2 == LOW) { // Button pressed
    digitalWrite(LED2, HIGH); // Turn LED2 ON
  } else {
    digitalWrite(LED2, LOW); // Turn LED2 OFF
  }
}
