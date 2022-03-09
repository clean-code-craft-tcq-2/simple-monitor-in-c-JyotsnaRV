#include <stdio.h>
#include <assert.h>
#include "batteryHealthChecker.h"

/* Drive functions to test the battery health based on the given parameters */
int main() {
  /* Positive Testcase - common */
  assert(batteryIsOk(25, 70, 0.7));
  /* Negative Testcases */
  assert(!batteryIsOk(-0.5, 75, 0.9));
  assert(!batteryIsOk(45.5, 15, 0.6));
  assert(!batteryIsOk(25, 85, 0));
  assert(!batteryIsOk(25, 15, 0));
  assert(!batteryIsOk(25, 65, 0));
  assert(!batteryIsOk(25, 85, 0.9));
  
  /* Positive test case - BMS Passed (Temperature, Soc and Charge rate is within expected range) */
  assert(!batteryHealth(80, 85, 0,RESIDENTIAL,FAHR));
  assert(!batteryHealth(190, 85, 0,CONSUMER,CEL));
  assert(!batteryHealth(140, 85, 0,EV,FAHR));
  
  /* Function verification */
  batteryHealth(25, 70, 0,RESIDENTIAL,CEL);   /* Temperature in range */
  batteryHealth(55, 85, 0,RESIDENTIAL,FAHR);  /* soc out of range */
  batteryHealth(55, 70, 0.9,CONSUMER,CEL);    /* charge rate not in range */
  batteryHealth(45, 70, 0,EV,FAHR);           /* everything in range */
  batteryHealth(45, 70, 0,(int)5,CEL);        /* domain out of range */
}
