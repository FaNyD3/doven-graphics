int pot1 = A0;
int pot2 = A1;
int pot3 = A2;
int pot4 = A3;
int pot5 = A4;

void setup() {
  Serial.begin(9600);
  pinMode(pot1, INPUT);
  pinMode(pot2, INPUT);
  pinMode(pot3, INPUT);
  pinMode(pot4, INPUT);
  pinMode(pot5, INPUT);
}

void loop() {
  int v=analogRead(pot1);
  delay(500);
  int a=analogRead(pot2);
  delay(500);
  int b=analogRead(pot3);
  delay(500);
  int c=analogRead(pot4);
  delay(500);
  int d=analogRead(pot5);
  delay(500);
  int mapping1=map(v, 0, 1023, 0, 255);
  // Serial.println("v1: ");
  Serial.println(v);
  int mapping2=map(a, 0, 1023, 0, 255);
  // Serial.println("v2: ");
  Serial.println(a);
  int mapping3=map(b, 0, 1023, 0, 255);
  // Serial.println("v3: ");
  Serial.println(b);
  int mapping4=map(c, 0, 1023, 0, 255);
  // Serial.println("v4: ");
  Serial.println(c);
  int mapping5=map(d, 0, 1023, 0, 255);
  // Serial.println("v5: ");
  Serial.println(d);
}
