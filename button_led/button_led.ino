#define legPinIn 10
#define legPinOut 5

bool isLightOn = false;
int preMode = HIGH;
int currMode = HIGH;

void setup() {
  Serial.begin(9600);
  pinMode(legPinIn, INPUT);
  pinMode(legPinOut, OUTPUT);
}

void loop() {
  isLightOn = getLightState();

  if (isLightOn) {
    digitalWrite(legPinOut, HIGH);
  } else {
    digitalWrite(legPinOut, LOW);
  }

  delay(100);
}

bool getLightState() {
  if (digitalRead(legPinIn) != currMode) {
    preMode = currMode;
    currMode = digitalRead(legPinIn);
    if (preMode == LOW && currMode == HIGH) {
      isLightOn = !isLightOn;
      Serial.print("isLightOn: ");
      Serial.println(isLightOn);
    }
  }

  return isLightOn;
}
