int sw2 = 2;
int led9 = 9;
int led10 = 10;
void setup(){
  pinMode(sw2, INPUT);
  pinMode(led9,OUTPUT);
  pinMode(led10, OUTPUT);
  
  attachInterrupt(0, isr, CHANGE);
}
void loop(){
  digitalWrite(led9, !digitalRead(led9));
  delay(500);
}
void isr(){
  digitalWrite(led10, !digitalRead(led10));
}
