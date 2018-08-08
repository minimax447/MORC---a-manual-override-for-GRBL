
/*zdrive V1. Tom Sheppard 31/7/2018.
   The program sends pulses to the stepper driver to set up the z axis
   the speed is regulated on A0


   V1.1 1/8/2018

   Low active enable
   further improvements will be to put a L-R-I-O driver into this to give a full manual override.
   the idea being to ensure that z can be clear or stepped into place on the workpiece before zeroing the
   UGS program
   
   v1.2 3/8/2018
   LRIO controls now tested. All outputs go into OR gates save for the enable which is AND.
   This allows MORC and GRBL to coexist


*/
int leftpin = 0;
int rightpin = 1;
int inpin = 2;
int outpin = 3;
int uppin = 4;
int downpin = 5;
int enpin = 6;
int dirpinz = 7;
int steppinz = 8;
int dirpinx = 9;
int steppinx = 10;
int dirpiny = 11;
int steppiny = 12;
int pulse = 500;
int rate = A0;

void Speed()
{
  pulse = analogRead(rate); // speed cannot be changed while button is pressed.
  pulse = ((pulse * 5) + 500);
}
void Stepz()
{
  Speed();
  digitalWrite (steppinz, HIGH);
  delayMicroseconds(pulse);
  digitalWrite (steppinz, LOW);
  delayMicroseconds(pulse);
}
void Stepx()
{
  Speed();
  digitalWrite (steppinx, HIGH);
  delayMicroseconds(pulse);
  digitalWrite (steppinx, LOW);
  delayMicroseconds(pulse);
}
void Stepy()
{
  Speed();
  digitalWrite (steppiny, HIGH);
  delayMicroseconds(pulse);
  digitalWrite (steppiny, LOW);
  delayMicroseconds(pulse);
}
void setup()
{
  pinMode (uppin, INPUT_PULLUP);
  pinMode (downpin, INPUT_PULLUP);
  pinMode (inpin, INPUT_PULLUP);
  pinMode (outpin, INPUT_PULLUP);
  pinMode (leftpin, INPUT_PULLUP);
  pinMode (rightpin, INPUT_PULLUP);

  pinMode (enpin, OUTPUT);
  pinMode (dirpinz, OUTPUT);
  pinMode (steppinz, OUTPUT);
  pinMode (dirpinx, OUTPUT);
  pinMode (steppinx, OUTPUT);
  pinMode (dirpiny, OUTPUT);
  pinMode (steppiny, OUTPUT);
  digitalWrite (enpin, HIGH);
  digitalWrite (dirpinz, LOW);
  digitalWrite (steppinz, LOW);
  digitalWrite (dirpinx, LOW);
  digitalWrite (steppinx, LOW);
  digitalWrite (dirpiny, LOW);
  digitalWrite (steppiny, LOW);
}
void loop()
{
  while (digitalRead(leftpin) == LOW)
  {
    digitalWrite(enpin, LOW);
    digitalWrite(dirpinx, LOW);
    Stepx();
  }
  while (digitalRead(rightpin) == LOW)
  {
    digitalWrite(enpin, LOW);
    digitalWrite(dirpinx, HIGH);
    Stepx();
  }
  while (digitalRead(inpin) == LOW)
  {
    digitalWrite(enpin, LOW);
    digitalWrite(dirpiny, LOW);
    Stepy();
  }
  while (digitalRead(outpin) == LOW)
  {
    digitalWrite(enpin, LOW);
    digitalWrite(dirpiny, HIGH);
    Stepy();
  }
  while (digitalRead(uppin) == LOW)
  {
    digitalWrite(enpin, LOW);
    digitalWrite(dirpiny, LOW);
    Stepz();
  }
  while (digitalRead(downpin) == LOW)
  {
    digitalWrite(enpin, LOW);
    digitalWrite(dirpinz, HIGH);
    Stepz();
  }
  digitalWrite (enpin, HIGH);
  digitalWrite (dirpinz, LOW);
  digitalWrite (steppinz, LOW);
  digitalWrite (dirpinx, LOW);
  digitalWrite (steppinx, LOW);
  digitalWrite (dirpiny, LOW);
  digitalWrite (steppiny, LOW);
}



