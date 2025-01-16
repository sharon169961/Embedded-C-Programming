#define btnPin 12

int btnPrevDebounce;
bool btnState, btnReading;
bool btnValue, btnPrevValue;
int count;

void setup() {
  Serial.begin(9600);
  // Set the button pin mode to pull up
  btnPrevDebounce = 0;
  btnState = btnReading = false;
  btnValue = btnPrevValue = false;
  count = 0;
}

void loop() {
  // Read the pin value

  btnReading=digitalRead(btnPin);

  if (btnReading != btnState) {
    btnPrevDebounce = millis();
    btnState = btnReading;
  }

  // Check if the different between current time and prevDebounce is greater than 50
  if ((millis()-btnPrevDebounce) >50 ) { 
    btnPrevValue = btnValue;
    btnValue = btnState;
  }

  // If button value changed from LOW to HIGH increment counter and print 
  if (btnValue==HIGH && btnPrevValue==LOW){
    count++;
    Serial.print("Count:");
    Serial.println(count);
  }
}
