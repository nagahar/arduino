const int LED = 13;
const int LED_A = 9;
int val = 0;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(LED, OUTPUT);
    pinMode(LED_A, OUTPUT);
    Serial.println("finish setup");
}

void loop() {
    // put your main code here, to run repeatedly:
    val = analogRead(0);
    set_brightness(val/4);
    delay(10);
}

void set_brightness(int brightness) {
    // if darker, LED_A is brighter
    int val = brightness;
    if (val < 0 || 255 < val) {
        val = 255;
    }

   analogWrite(LED_A, val);
}
