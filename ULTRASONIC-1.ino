const int trigpin=2;
const int echopin=3;
const int led1=4;
const int led2=5;
const int led3=6;
float duration;
float distance;

void setup() {
  // put your setup code here, to run once:

  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(trigpin,LOW);
  delay(1000);

  digitalWrite(trigpin,HIGH);
  delay(1000);

  digitalWrite(trigpin,LOW);
  duration=pulseIn(echopin,HIGH);
  distance=0.034*duration/2.0;
  Serial.println("DISTANCE:");
  Serial.println(distance);

  if(distance>=3 && distance<=30)
  {
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);

    Serial.print("led1 is now on");
    delay(1000);
    
  }

  else if(distance>=50 && distance<=100)
  {
    digitalWrite(led2,HIGH);
    digitalWrite(led1,LOW);
    digitalWrite(led3,LOW);

    Serial.println("led2 is now on");
    delay(1000);
    
  }

  else if(distance>=150 && distance<=250)
  {
    digitalWrite(led3,HIGH);
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);

    Serial.println("led3 is now on");
    delay(1000);
    digitalWrite(led3,LOW);
  }
  
 }
