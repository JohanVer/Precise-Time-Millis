/*
   PreciseTiming.pde
   example code illustrating Time library with Real Time Clock.

*/
#include <TimeLib.h>



#include <Wire.h>
//#include <DS1307RTC.h>  // a basic DS1307 library that returns time as a time_t

void setup()  {
  Serial.begin(115200);
  //initTimer(int Timer, in Source, int InterruptPin);
  //Timer= 0,1 (Timer0, Timer1)
  //Source= 0 MainClock, 1 InputTrigger T0/T1
  //InterruptPin 0(INT0),1(INT1),8 (ICP1),99 (own Triggerpin with resetTimer())
  //resetTimer();
  //Set CountVars to 0;
  initTimer(2, 0, 2);
  //resetTimer();
  unsigned long tmpcheck = F_CPU / 256;
  Serial.println(tmpcheck);
  double millifracs = (double)1000.0f / tmpcheck;


  delay(2000);
}
int lastprecmillis = 0;
int lastmillis = 0;
int sync = 0;
void loop()
{

  long mymillis = millis();
  long myprecmillis = precmillis();
  Serial.println(precmillis());
  Serial.println( myprecmillis - mymillis - sync);


  delay(1000);
  if (sync == 0)
    sync = myprecmillis - mymillis;
}

