#include <Servo.h>
int Variable_v = 0;
Servo servo_6;
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}
void setup()
{
  servo_6.attach(6, 500, 2500);
}
void loop()
{
  servo_6.write(90);
  Variable_v = 0.01723 * readUltrasonicDistance(7, 7);
  if (Variable_v <= 100) {
    servo_6.write(90);
    delay(2000); // Wait for 2000 millisecond(s)
    servo_6.write(90);
    delay(2000); // Wait for 2000 millisecond(s)
    servo_6.write(90);
  }
}