#ifndef BMS_CHECKERS_H
#define BMS_CHECKERS_H

/* Necessary includes */
#include <stdio.h>

/* Macros */
#define TEMPERATURE_MIN 0
#define TEMPERATURE_MAX 45
#define SOC_MIN 20
#define SOC_MAX 80
#define CHARGE_RATE_MIN 0.0
#define CHARGE_RATE_MAX 0.8

/* Declarations */
float temperatureCheck(float temperature);
float statusOfCharge(float soc);
float rateOfCharge(float chargeRate);

#endif /* BMS_CHECKERS_H */
