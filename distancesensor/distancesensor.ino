const int pinTrigger = 12;
const int pinEcho = 13;
const int pinLedBlue = 3;
const int pinLedYellow = 2;
const int pinLedRed = 4;

void setup(){
  Serial.begin(9600);
  pinMode(pinTrigger, OUTPUT);
  pinMode(pinEcho, INPUT);
  pinMode(pinLedBlue, OUTPUT);
  pinMode(pinLedYellow, OUTPUT);
  pinMode(pinLedRed, OUTPUT);
}

void loop(){
  digitalWrite(pinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrigger, LOW);
  //pulseIn(pinEcho, HIGH) = duration
  int distance = pulseIn(pinEcho, HIGH)/58;
  digitalWrite(pinLedBlue, LOW);
  digitalWrite(pinLedYellow, LOW);
  digitalWrite(pinLedRed, LOW);
  if(distance <= 20 && distance > 15){
    digitalWrite(pinLedBlue, HIGH);
  }else if(distance <= 15 && distance > 10){
    digitalWrite(pinLedYellow, HIGH);
  }else if(distance <= 10){
    digitalWrite(pinLedRed, HIGH);
  }
  Serial.print(distance);
  Serial.println(" cm");
  delay(500);
}
