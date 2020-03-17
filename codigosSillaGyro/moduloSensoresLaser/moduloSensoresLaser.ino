
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
  delay(1000);
}
float s1_,s2_,s3_,s4_,s5_,s6_;//sensor 1 al 6 valor bruto
int s1,s2,s3,s4,s5,s6;//sensor 1 al 6
int cont_s6[]={0,0};
int cont_s5[]={0,0};
int cont_s4[]={0,0};
int cont_s3[]={0,0};
int cont_s2[]={0,0};
int cont_s1[]={0,0};
void loop() {
  // put your main code here, to run repeatedly:
  s1_=analogRead(A5);
  s2_=analogRead(A4);
  s3_=analogRead(A3);
  s4_=analogRead(A2);
  s5_=analogRead(A1);
  s6_=analogRead(A0);

  //lecturas de sensor
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
  //lecturas de sensor
  (s5_ < 200)?s5_=200:s5_=s5_;
  s5_ = map(s5_,200,1024,100,0);
  cont_s5[0]++;
  cont_s5[1]+=s5_;
  if(cont_s5[0] >= 5){
    s5_ = cont_s5[1]/5;
    s5 = s5_;
    cont_s5[0]=0;
    cont_s5[1]=0;
  }
  //lecturas de sensor
  (s4_ < 200)?s4_=200:s4_=s4_;
  s4_ = map(s4_,200,1024,100,0);
  cont_s4[0]++;
  cont_s4[1]+=s4_;
  if(cont_s4[0] >= 5){
    s4_ = cont_s4[1]/5;
    s4 = s4_;
    cont_s4[0]=0;
    cont_s4[1]=0;
  }
  //lecturas de sensor
  (s3_ < 200)?s3_=200:s3_=s3_;
  s3_ = map(s3_,200,1024,100,0);
  cont_s3[0]++;
  cont_s3[1]+=s3_;
  if(cont_s3[0] >= 5){
    s3_ = cont_s3[1]/5;
    s3 = s3_;
    cont_s3[0]=0;
    cont_s3[1]=0;
  }
  //lecturas de sensor
  (s2_ < 200)?s2_=200:s2_=s2_;
  s2_ = map(s2_,200,1024,100,0);
  cont_s2[0]++;
  cont_s2[1]+=s2_;
  if(cont_s2[0] >= 5){
    s2_ = cont_s2[1]/5;
    s2 = s2_;
    cont_s2[0]=0;
    cont_s2[1]=0;
  }
  //lecturas de sensor
  (s1_ < 200)?s1_=200:s1_=s1_;
  s1_ = map(s1_,200,1024,100,0);
  cont_s1[0]++;
  cont_s1[1]+=s1_;
  if(cont_s1[0] >= 5){
    s1_ = cont_s1[1]/5;
    s1 = s1_;
    cont_s1[0]=0;
    cont_s1[1]=0;
  }

  Serial.print(s1);
  Serial.print("/");
  Serial.print(s2);
  Serial.print("/");
  Serial.print(s3);
  Serial.print("/");
  Serial.print(s4);
  Serial.print("/");
  Serial.print(s5);
  Serial.print("/");
  Serial.print(s6);
  
  delay(50);
}
