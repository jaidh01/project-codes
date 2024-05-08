#define m11 8
#define m12 9
#define m21 10
#define m22 11
#define D3 3
#define D4 4
#define D5 5
#define D6 6
void forward()
{
  digitalWrite(m11, HIGH);
  digitalWrite(m12, LOW);
  digitalWrite(m21, HIGH);
  digitalWrite(m22, LOW);
  delay(60);
  digitalWrite(m11, LOW);
  digitalWrite(m12, LOW);
  digitalWrite(m21, LOW);
  digitalWrite(m22, LOW);
  delay(40);
}
void backward()
{
  digitalWrite(m11, LOW);
  digitalWrite(m12, HIGH);
  digitalWrite(m21, LOW);
  digitalWrite(m22, HIGH);
  delay(60);
  digitalWrite(m11, LOW);
  digitalWrite(m12, LOW);
  digitalWrite(m21, LOW);
  digitalWrite(m22, LOW);
  delay(40);
}
void left()
{
  digitalWrite(m11, HIGH);
  digitalWrite(m12, LOW);
  digitalWrite(m21, LOW);
  digitalWrite(m22, HIGH);
  delay(70);
  digitalWrite(m11, LOW);
  digitalWrite(m12, LOW);
  digitalWrite(m21, LOW);
  digitalWrite(m22, LOW);
  delay(30);
}
void right()
{
  digitalWrite(m11, LOW);
  digitalWrite(m12, HIGH);
  digitalWrite(m21, HIGH);
  digitalWrite(m22, LOW);
  delay(70);
  digitalWrite(m11, LOW);
  digitalWrite(m12, LOW);
  digitalWrite(m21, LOW);
  digitalWrite(m22, LOW);
  delay(30);
}
void Stop()
{
  digitalWrite(m11, LOW);
  digitalWrite(m12, LOW);
  digitalWrite(m21, LOW);
  digitalWrite(m22, LOW);
}
void setup()
{
  pinMode(D3, INPUT);
  pinMode(D4, INPUT);
  pinMode(D5, INPUT);
  pinMode(D6, INPUT);
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  int temp1 = digitalRead(D3);
  int temp2 = digitalRead(D4);
  int temp3 = digitalRead(D5);
  int temp4 = digitalRead(D6);
  Serial.print(temp1);
  Serial.print(temp2);
  Serial.print(temp3);
  Serial.println(temp4);
  if ((temp1 == 0) && (temp2 == 1) && (temp3 == 0) && (temp4 == 0)) {
    forward();
    Serial.println("Forward");
  } else if ((temp1 == 0) && (temp2 == 0) && (temp3 == 1) && (temp4 == 0)) {
    left();
    Serial.println("Left");
  } else if ((temp1 == 0) && (temp2 == 1) && (temp3 == 1) && (temp4 == 0)) {
    right();
    Serial.println("Right");
  } else if ((temp1 == 0) && (temp2 == 0) && (temp3 == 0) && (temp4 == 1)) {
    backward();
    Serial.println("Back");
  } else if ((temp1 == 1) && (temp2 == 0) && (temp3 == 1) && (temp4 == 0)) {
    Stop();
    Serial.println("Stop");
  }
}