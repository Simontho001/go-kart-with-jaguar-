int anPin, upPin, downPin;
int currentPosition, goalPosition;
boolean extending, retracting;

void setup() {
  anPin = A0;
  upPin = 4;
  downPin = 5;
  extending = false;
  retracting = false;

  pinMode(upPin, OUTPUT);
  pinMode(downPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  currentPosition = analogRead(anPin);
  //goalPosition = ///function to parse position from RC controller output///

  if(currentPosition < goalPosition) { //keep extending
    extending = true;
    retracting = false;
    digitalWrite(upPin, HIGH);
    digitalWrite(downPin, LOW);
  }
  else if(currentPosition > goalPosition) { //keep retracting
    extending = false;
    retracting = true;
    digitalWrite(upPin, LOW);
    digitalWrite(downPin, HIGH);
  }

  if(extending == true && currentPosition >= goalPosition) {
    extending = false;
    digitalWrite(upPin, LOW);
  }
  else if(retracting == true && currentPosition <= goalPosition) {
    retracting = false;
    digitalWrite(downPin, LOW);
  }

}
