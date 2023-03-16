unsigned long prev_time = 0;
unsigned long current_time = 0;
long time_inter = 10000;
int led_sec = 2;

int reset_button = 9;
int button_state = 0;

void setup() {
  // put your setup code here, to run once:
  for (int x = 2; x <= 7; x++) {
    pinMode(x, OUTPUT);
    digitalWrite(x, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  current_time = millis();


  if (current_time - prev_time >= time_inter) {
    prev_time = current_time;
    digitalWrite(led_sec, HIGH);
    led_sec += 1;
  }

  button_state = digitalRead(reset_button);
  delay(10);

  if (button_state == HIGH) {
    led_sec = 2;
    for (int x = 2; x <= 7; x++) {
      digitalWrite(x, LOW);
    }
    prev_time = current_time;
  }
}
