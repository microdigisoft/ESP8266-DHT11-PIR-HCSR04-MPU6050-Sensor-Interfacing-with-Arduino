#define trigPin D1 // Initialize pin9 for HC-SR04 Trigger
#define echoPin D2 // Initialize pin8 for HC-SR04 Echo
#define led D6 //Initialize pin12 for LED
void setup(){
Serial.begin (115200); //Begin serial monitor with baud rate 9600

pinMode(trigPin, OUTPUT);//Define Trigger pin as output
pinMode(echoPin, INPUT);//Define Echo pin as input
pinMode(led, OUTPUT); //Define LED pin as output
}
void loop()
{
  long duration, distance; // variable to hold the duration and distance value for HC-SR04
  digitalWrite(trigPin, LOW); // Write trigger pin is as low
  delayMicroseconds(2); // Delay for 2microseconds
  digitalWrite(trigPin, HIGH); //Write trigger pin is as high
  delayMicroseconds(10);// Delay for 10microseconds
  digitalWrite(trigPin, LOW); //Write trigger pin is as low
  duration = pulseIn(echoPin, HIGH);//Read the echo pin
  distance = (duration / 2) / 29.1; // calculate the distance
  if (distance <= 10)
  {
    Serial.print(distance);//print the distance value on serial port
    digitalWrite(led, HIGH);
    Serial.println("cm : LED is on ");
    delay(500);
  }
  else {
    Serial.print(distance);//print the distance value on serial port
    digitalWrite(led, LOW);
    Serial.println(" cm : LED is off ");
    delay(500);
  }
}
