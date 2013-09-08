                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          #define echoPin 9 
#define trigPin 11
#define LEDPin 13 

int ENA=2;
int IN1=3;
int IN2=4;
int ENB=5;
int IN3=6;
int IN4=7;

int maximumRange = 80; // Maximum range needed
int minimumRange = 10; // Minimum range needed
long duration, distance; // Duration used to calculate distance

void setup() {
   Serial.begin (9600);
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
   pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
 
   pinMode(ENA,OUTPUT);
   pinMode(ENB,OUTPUT);
   pinMode(IN1,OUTPUT);
   pinMode(IN2,OUTPUT);
   pinMode(IN3,OUTPUT);
   pinMode(IN4,OUTPUT);
   digitalWrite(ENA,HIGH);//enablae motorA
   digitalWrite(ENB,HIGH);//enable motorB
 
}

void loop() {
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 distance = duration/58.2;
 if (distance >= maximumRange || distance <= minimumRange){  
   Serial.println("girar  otro lado");
   digitalWrite(LEDPin, HIGH); 
   
   digitalWrite(IN1,LOW);
   digitalWrite(IN2,LOW);
   digitalWrite(IN3,LOW);
   digitalWrite(IN4,LOW);
   
 } else {
   Serial.println(distance);
   digitalWrite(LEDPin, LOW); 
   
   digitalWrite(IN1,HIGH);
   digitalWrite(IN2,LOW);
   digitalWrite(IN3,HIGH);
   digitalWrite(IN4,LOW);
 }
 
 //Delay 50ms before next reading.
  delay(60);
}
