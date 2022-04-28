#ifndef BMS_CHECKERS_H
#define BMS_CHECKERS_H

/* Necessary includes */
#include <stdio.h>

/* Macros */
#define NUM_OF_DOMAINS 3
#define TEMPERATURE_MIN 0
#define TEMPERATURE_MAX 45
#define TEMPERATURE_RESIDENTIAL_MAX 80
#define TEMPERATURE_CONSUMER_MAX 200
#define TEMPERATURE_EV_MAX 150
#define SOC_MIN (float)20
#define SOC_MAX (float)80
#define CHARGE_RATE_MIN 0.0
#define CHARGE_RATE_MAX 0.8

#define BINARY_MIN 0
#define BINARY_MAX 1

#define WARNING_MSG_CHAR 40

/* Macros to perform extension-3: temperature unit conversion */
#define CALCTOLERANCE(x) (float)(x*(0.05))
#define CEL 0 /* celcius */
#define FAHR 1 /* Fahrenheit */
#define CELTOFAHR(Y) (float)((Y*(9/5))+32)

/* Enumerations */
enum MajorDomain {RESIDENTIAL, CONSUMER, EV};
typedef enum {TEMPERATURE, SOC, ROC} BmsParameter;

/* Structures */
typedef struct
{
	float inputParameter;
	float minTolerance;
	float maxTolerance;
	BmsParameter paramType;
	int dataVal;
	int tempUnitConv;
}toleranceRange_st;

/* Declarations */
int IsTemperatureOk(float temperature,enum MajorDomain domainType, int temperatureSIUnit);
int statusOfCharge(float soc);
int rateOfCharge(float chargeRate);
int temperatureStatus(float temperature, float compareTemp, int tempSIUnit) ;

toleranceRange_st checkTolerance(toleranceRange_st range);
void warningsGenerator(toleranceRange_st warningType);
void ParamToString(char* bffr, toleranceRange_st inputDetail);
void dataAcquisition(toleranceRange_st range);
unsigned int controllerAction(void);

#endif /* BMS_CHECKERS_H */
