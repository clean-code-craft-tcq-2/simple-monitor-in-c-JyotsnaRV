#include <stdio.h>
#include <assert.h>
#include "BmsCheckers.h"

/* Drive functions to test the battery health based on the given parameters */
int main() {
  /* Positive Testcase - common */
  assert(batteryIsOk(25, 70, 0.7,RESIDENTIAL,CEL));
  /* Negative Testcases */
  assert(!batteryIsOk(-0.5, 75, 0.9,RESIDENTIAL,FAHR));
  assert(!batteryIsOk(45.5, 15, 0.6,CONSUMER,CEL));
  assert(!batteryIsOk(25, 85, 0,EV,FAHR));
  assert(!batteryIsOk(25, 15, 0,RESIDENTIAL,CEL));
  assert(!batteryIsOk(25, 65, 0,CONSUMER,CEL));
  assert(!batteryIsOk(25, 85, 0.9,CONSUMER,CEL));
  
  /* Positive test case - BMS Passed (Temperature, Soc and Charge rate is within expected range) */
  assert(!batteryIsOk(80, 85, 0,RESIDENTIAL,FAHR));
  assert(!batteryIsOk(190, 85, 0,CONSUMER,CEL));
  assert(!batteryIsOk(140, 85, 0,EV,FAHR));
  
  /* Function verification */
  batteryIsOk(25, 70, 0,RESIDENTIAL,CEL);   /* Temperature in range */
  batteryIsOk(55, 85, 0,RESIDENTIAL,FAHR);  /* soc out of range */
  batteryIsOk(55, 70, 0.9,CONSUMER,CEL);    /* charge rate not in range */
  batteryIsOk(45, 70, 0,EV,FAHR);           /* everything in range */
  batteryIsOk(45, 70, 0,(int)5,CEL);        /* domain out of range */
}
