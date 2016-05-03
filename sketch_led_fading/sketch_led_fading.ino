const int LED = 9; // LED is connected to 13-pin
int i = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT); // Set LED pin to output mode
}

void loop() {
  // put your main code here, to run repeatedly:
  for (i = 0; i < 255; i++) {
    analogWrite(LED, i);
    delay(10);
  }
  for (i = 255; i > 0; i--) {
    analogWrite(LED, i);
    delay(10);
  }
}
