
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
float s1_,s2_,s3_,s4_,s5_,s6_;//sensor 1 al 6 valor bruto
int s1,s2,s3,s4,s5,s6;//sensor 1 al 6
int cont_s6[]={0,0};
void loop() {
  // put your main code here, to run repeatedly:
  s1_=analogRead(A5);
  s2_=analogRead(A4);
  s3_=analogRead(A3);
  s4_=analogRead(A2);
  s5_=analogRead(A1);
  s6_=analogRead(A0);

  (s6_ < 200)?s6_=200:s6_=s6_;
  s6_ = map(s6_,200,1024,100,0);
  cont_s6[0]++;
  cont_s6[1]+=s6_;
  if(cont_s6[0] >= 5){
    s6_ = cont_s6[1]/5;
    s6 = s6_;
    cont_s6[0]=0;
    cont_s6[1]=0;
  }

  Serial.println(s6);
  
}
