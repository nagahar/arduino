const int LED = 13; // LED is connected to 13-pin
const int BUTTON = 7; // PUSH button is connected to 13-pin

int val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT); // Set LED pin to output mode
  pinMode(BUTTON, INPUT); // Set BUTTON pin to input mode
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(BUTTON);
  if (val == HIGH) {
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
    delay(1000);
  } else {
    digitalWrite(LED, LOW);
  }
}
