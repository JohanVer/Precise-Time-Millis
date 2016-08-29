Readme file for Arduino Time Library

This is a Fork from PaulStoffregens Time Library

Whats the Difference?

The Library Counts the Internal "Time Library" Seconds with PPS(PulsPerSecond) from DS3231 or GPS.
That Means the Original Time Library Calculate the Theoretical Time From SystemMillis affected by Clock Accuracy.


It Adds a free to choose Interrupt to Update Seconds from GPS-PPS or DS3231 1Hz Squarewave.

The Theory 1, GPS Based PPS Signal accuracy long time compensated 30ns Drift
The Theory 2, DS3231 TCXO, Temperature compensated Crystal 1-3ppm Longtime Drift.
The Theory 3, Millis aligned between two PPS Signals and synchronized with 32768hz or Internal Clock for same Accuracy from Theory1/2.

3 Chooseable Timers to Count Millis synced to PPS(PulsPerSecond).
3 Chooseable Inputs to Count Timers, T0,T1, InternalClock 
(Arduino Reserved T0,choose with my T2 Millis Arduino Variant to switch Timer0 and Timer2 in Core)
3 Chooseable Interrupts, ICP1,INT0,INT1, or own Event with ResetTimer() Function for PPS 

Calibration Function to Calibrate Millis Factor to Precise Timing eg 15.9599999 Crystal precision.


So we can measure over hours in Millisecond Precision with Round about 32768Hz 1-2ppm.

To Choose the Timer Edit Time.ccp Line to Timer Number:
Example Timer 1:
```#Define TIMERVAR 1```  
Same to Reserve Pin D8 for T1:
```#Define Pin8 1```

Codeexample:
Setup(): 
initTimer(2,0,2); //Standard Settings init (Timer2, Internal clock,INT0(Pin2) DS3231 SQWPin 1Hz->INT0

Loop() Overwiew:  
 CalibrateNow();
 Serial.println("New Calculation Frequency for PrecMillis()");
 Serial.println(recalculateF_CPU()); 
 Serial.println(precmillis());
 Serial.println( myprecmillis - mymillis - sync);
  
Output: (Good Measurement, The Coremillis Drifts 2-4ms/Second) The Real Delay(1000) maybe ca. 1060ms
New Calculation Frequency for PrecMillis()
11993117
14591
39
15658
42
16725
45
17793
50
18860
55
19927
58
20995
63
22061
65
23129
71
24196
75
25263




