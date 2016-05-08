const int LED_A = 9; // LED is connected to 9-pin
const int LED = 13; // LED is connected to 13-pin
const int BUTTON = 7; // BUTTON is connected to 7-pin
const int B_NONE = 255; // PWM Low

int i = 0;
int val = 0; // current BUTTON value
int old_val = 0; // previous BUTTON value
int state = 0; // ON: 1, OFF:0

int brightness = B_NONE;
unsigned long startTime = 0;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    //pinMode(LED, OUTPUT); // Set LED pin to output mode
    pinMode(LED_A, OUTPUT); // Set LED pin to output mode
    pinMode(BUTTON, INPUT); // Set BUTTON pin to input mode
    Serial.println("finish setup");
}

void loop() {
    // put your main code here, to run repeatedly:
    val = digitalRead(BUTTON);
    if ((val == HIGH) && (old_val == LOW)) {
        // OFF->ON
        Serial.println("OFF->ON");
        state = 1 - state;
        startTime = millis();
        delay(10); // for debouncing
    }

    if ((val == HIGH) && (old_val == HIGH)) {
        // ON->ON
        Serial.println("ON->ON");
        if (state == 1 && (millis() - startTime) > 500) {
            set_brightness_up(1);
            Serial.print("brightness = ");
            Serial.println(brightness);
            delay(10); // to suppress incresing too much
        }
    }

    old_val = val;
    if (state == 1) {
        on_brightness();
        digitalWrite(LED, HIGH);
    } else {
        off_brightness();
        digitalWrite(LED, LOW);
    }
}

void set_brightness_up(int num) {
    brightness -= num;
    if (brightness < 0) {
        brightness = B_NONE;
    }
}

void off_brightness() {
    brightness = B_NONE;
    on_brightness();
}

void on_brightness() {
    analogWrite(LED_A, brightness);
}

