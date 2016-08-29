/*
   PreciseTiming.pde
   example code illustrating Time library with Real Time Clock.

*/
#include <TimeLib.h>



#include <Wire.h>
//#include <DS1307RTC.h>  // a basic DS1307 library that returns time as a time_t

void setup()  {
  Serial.begin(115200);
  Serial.println(recalculateF_CPU());
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
int myloop = 0;

void loop()
{
  // Get Both Millis
    long mymillis = millis();
    long myprecmillis = precmillis();
  //this delay means 1060ms Realtime
  delay(1000);
  
  if (myloop == 2)
  {
    if (sync == 0)
      sync = myprecmillis - mymillis;
  } else if (myloop == 5)
  {
    CalibrateNow();
  }
  else if (myloop == 10)
  {
    //Update and Draws Real Frequency, best Result with Good GPS PPS Signal with 30ns Drift.
    Serial.println("New Calculation Frequency for PrecMillis()");
    Serial.println(recalculateF_CPU());
  } else if (myloop > 10)
  {

    if (sync != 0) {
      //Draws the Drift of Milliseconds from Millis  
      Serial.println(precmillis());
      Serial.println( myprecmillis - mymillis - sync);
    }
  }

  myloop++;
}

