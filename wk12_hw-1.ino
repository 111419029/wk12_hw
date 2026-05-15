#define PULL_UP_BUTTON 2
#define LED_OUTPUT 13

void setup() {
  Serial.begin(9600);
  pinMode(PULL_UP_BUTTON, INPUT_PULLUP);
  pinMode(LED_OUTPUT, OUTPUT);
}

void loop() {
  int buttonPressed = !digitalRead(PULL_UP_BUTTON);
  Serial.print(buttonPressed?'@':'_');

  if (buttonPressed) {
    digitalWrite(LED_OUTPUT, HIGH);
  } else {
    digitalWrite(LED_OUTPUT, LOW);
  }
  delay(100);
}
