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
}
