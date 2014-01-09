//Mux control pins
int s0 = A0;
int s1 = A1;
int s2 = A2;
int s3 = A3;

int controlPin[] = {s0, s1, s2, s3};

  int muxChannel[16][4]={
    {0,0,0,0}, //channel 0
    {1,0,0,0}, //channel 1
    {0,1,0,0}, //channel 2
    {1,1,0,0}, //channel 3
    {0,0,1,0}, //channel 4
    {1,0,1,0}, //channel 5
    {0,1,1,0}, //channel 6
    {1,1,1,0}, //channel 7
    {0,0,0,1}, //channel 8
    {1,0,0,1}, //channel 9
    {0,1,0,1}, //channel 10
    {1,1,0,1}, //channel 11
    {0,0,1,1}, //channel 12
    {1,0,1,1}, //channel 13
    {0,1,1,1}, //channel 14
    {1,1,1,1}  //channel 15
  };

void muxWrite(int sig, int channel, boolean state);

//Mux in "SIG" pin
int SIG_pin = A7;


void setup(){
  pinMode(s0, OUTPUT); 
  pinMode(s1, OUTPUT); 
  pinMode(s2, OUTPUT); 
  pinMode(s3, OUTPUT); 

  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);

  Serial.begin(9600);
}


void loop(){
  for(int  i = 0; i<16; i++)
  {
    muxWrite(SIG_pin, i, HIGH);
    Serial.print("canal: "); Serial.println(i);
    delay(800);
  }
}

void muxWrite(int sig, int channel, boolean state)
{
  pinMode(sig, OUTPUT);
  for(int i = 0; i < 4; i ++)
  digitalWrite(controlPin[i], muxChannel[channel][i]);
  digitalWrite(sig, state);
}
