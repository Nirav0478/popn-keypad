int y1 = 1, b1 = 2, b2 = 5, y2 = 6;
int w1 = 11, g1 = 10, r = 9, g2 = 8, w2 = 7;


struct Button {
  int pin;
  char key;
  bool lastState;
};

Button buttons[] = {
  { w1, 'c', HIGH },
  { y1, 'f', HIGH },
  { g1, 'v', HIGH },
  { b1, 'g', HIGH },
  { r,  'b', HIGH },
  { b2, 'h', HIGH },
  { g2, 'n', HIGH },
  { y2, 'j', HIGH },
  { w2, 'm', HIGH }
};

const int buttonCount = sizeof(buttons) / sizeof(buttons[0]);

void setup() {
  Keyboard.begin();
  for (int i = 0; i < buttonCount; i++) {
    pinMode(buttons[i].pin, INPUT_PULLUP);
  }
}

void loop() {
  for (int i = 0; i < buttonCount; i++) {
    bool currentState = digitalRead(buttons[i].pin);

    if (currentState == LOW && buttons[i].lastState == HIGH) {
      Keyboard.press(buttons[i].key);

    } else if (currentState == HIGH && buttons[i].lastState == LOW) {
      Keyboard.release(buttons[i].key);
    }

    buttons[i].lastState = currentState;
  }
  delay(5);
}
