/******************************************************************
** Código creado en Electrónica 5Hz                              **
** www.5hz-electronica.com                                       **
** Por:                                                          **
**                                                               **
** Descripción del código:                                       **
**                                                               **
** Ejemplo para el Multiplexor Análogo HP4067,                   **
** conectando 16 LEDs a las salidas del multiplexor              **
*******************************************************************
Conexiones:
UNO   HP4067

5V    VCC
GND   GND
A0    S0
A1    S1
A2    S2
A3    S3
A4    SIG
*/

//--------------------------------------------definiciones de pines
int s0 = A0;
int s1 = A1;
int s2 = A2;
int s3 = A3;
int SIG_pin = A4;

int controlPin[] = {s0, s1, s2, s3};

int muxChannel[16][4]={
    {0,0,0,0}, //canal 0
    {1,0,0,0}, //canal 1
    {0,1,0,0}, //canal 2
    {1,1,0,0}, //canal 3
    {0,0,1,0}, //canal 4
    {1,0,1,0}, //canal 5
    {0,1,1,0}, //canal 6
    {1,1,1,0}, //canal 7
    {0,0,0,1}, //canal 8
    {1,0,0,1}, //canal 9
    {0,1,0,1}, //canal 10
    {1,1,0,1}, //canal 11
    {0,0,1,1}, //canal 12
    {1,0,1,1}, //canal 13
    {0,1,1,1}, //canal 14
    {1,1,1,1}  //canal 15
  };
  
void muxWrite(int sig, int channel, boolean state);

//----------------------------------------------------configuracion
void setup()
{
  pinMode(s0, OUTPUT); 
  pinMode(s1, OUTPUT); 
  pinMode(s2, OUTPUT); 
  pinMode(s3, OUTPUT); 

  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);

  Serial.begin(9600);
  Serial.println("Programa de ejemplo para el multiplexor HP4067");
}

//##################################################ciclo principal

void loop()
{
  for(int  i = 0; i<16; i++)
  {
    muxWrite(SIG_pin, i, HIGH);
    Serial.print("canal: "); Serial.println(i);
    delay(800);
  }
}

//#########################################fin del ciclo principal

//-------------------------------------------------------funciones

void muxWrite(int sig, int channel, boolean state)
{
  pinMode(sig, OUTPUT);
  for(int i = 0; i < 4; i ++)
  digitalWrite(controlPin[i], muxChannel[channel][i]);
  digitalWrite(sig, state);
}
