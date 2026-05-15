#define buttonPin 12

byte seven_seg_digits[10][7] = { { 0,0,0,0,0,0,1 },  // = 0
                                 { 1,0,0,1,1,1,1 },  // = 1
                                 { 0,0,1,0,0,1,0 },  // = 2
                                 { 0,0,0,0,1,1,0 },  // = 3
                                 { 1,0,0,1,1,0,0 },  // = 4
                                 { 0,1,0,0,1,0,0 },  // = 5
                                 { 0,1,0,0,0,0,0 },  // = 6
                                 { 0,0,0,1,1,1,1 },  // = 7
                                 { 0,0,0,0,0,0,0 },  // = 8
                                 { 0,0,0,1,1,0,0 }   // = 9
                             };

int buttonState = 0;
int num = 0;
bool buttonPressed, buttonHasReleased;

void setup() {      
  Serial.begin(9600);         
  pinMode(2, OUTPUT);  
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
 pinMode(9, OUTPUT);
  digitalWrite(9, 1);  // 關閉小數點
  pinMode(buttonPin,INPUT_PULLUP);
  buttonHasReleased = true;
}

void sevenSegWrite(byte digit) {
  byte pin = 2;
  for (byte seg = 0; seg < 7; ++seg) {
    digitalWrite(pin, seven_seg_digits[digit][seg]);
    ++pin;
  }
}

void loop() {
  buttonPressed = !digitalRead(buttonPin);

  if (buttonHasReleased && buttonPressed) {
    num++;
    if(num > 9)
      num = 0;
  }
  buttonHasReleased = !buttonPressed;

  sevenSegWrite(num);
  Serial.println(num); 
  delay(100);

}
