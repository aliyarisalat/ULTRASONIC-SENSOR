
# define trigpin 2
# define echopin 3
# define led 4
float duration;
float distance;

void setup() {
  // put your setup code here, to run once:

  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(led,OUTPUT);
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

  if(distance < 30.0)
  {
    digitalWrite(led,HIGH);
    delay(1000);
  }

  else
  {
    digitalWrite(led,LOW);
    delay(1000);
  }

}
