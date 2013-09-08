int ENA=2;//connected to Arduino's port 2
int IN1=3;//connected to Arduino's port 3
int IN2=4;//connected to Arduino's port 4
int ENB=5;//connected to Arduino's port 5
int IN3=6;//connected to Arduino's port 6
int IN4=7;//connected to Arduino's port 7
 
void setup()
{
 pinMode(ENA,OUTPUT);
 pinMode(ENB,OUTPUT);
 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT);
 pinMode(IN3,OUTPUT);
 pinMode(IN4,OUTPUT);
 digitalWrite(ENA,HIGH);//enablae motorA
 digitalWrite(ENB,HIGH);//enable motorB
}
void loop()
{
// girar izquierda  
// digitalWrite(IN1,HIGH);
// digitalWrite(IN2,LOW);
// digitalWrite(IN3,LOW);
// digitalWrite(IN4,HIGH);
// delay(1000);

//girar derecha
// digitalWrite(IN1,LOW);
// digitalWrite(IN2,HIGH);
// digitalWrite(IN3,HIGH);
// digitalWrite(IN4,LOW);
// delay(1000);

// adelante
// digitalWrite(IN1,HIGH);
// digitalWrite(IN2,LOW);
// digitalWrite(IN3,HIGH);
// digitalWrite(IN4,LOW);
// delay(10);

// atras
// digitalWrite(IN1,LOW);
// digitalWrite(IN2,HIGH);
// digitalWrite(IN3,LOW);
// digitalWrite(IN4,HIGH);
// delay(10);


 }
