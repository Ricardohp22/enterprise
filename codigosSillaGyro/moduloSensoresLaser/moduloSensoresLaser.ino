
#define sd1 5
#define sd2 4
#define sd3 3
#define sd4 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(sd1, INPUT);
  pinMode(sd2, INPUT);
  pinMode(sd3, INPUT);
  pinMode(sd4, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(A1));
}
