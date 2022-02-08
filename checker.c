#include <stdio.h>
#include <assert.h>
#include "batteryHealthChecker.h"

/* Drive functions to test the battery health based on the given parameters */
int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
