const int soundSensorPin = A0;
const int ledPin = 2;

int countPalm = 0;

void setup() {  
  pinMode(soundSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(true) {
    int sound = digitalRead(soundSensorPin);
    if(sound == HIGH) {
      if(countPalm == 2) {
        digitalWrite(ledPin, !digitalRead(ledPin));
        countPalm = 0;
      } else {
        while(digitalRead(soundSensorPin)) {
          delay(200);
        }
        
        countPalm++;
      }
    }
  }
}
