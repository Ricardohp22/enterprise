int var = 0;
int signo = 1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  var = signo*(var *124 -154 +2);
  if (var > 20000){

    signo = -1;
  }
  Serial.println(var);
  delay(1);
}
