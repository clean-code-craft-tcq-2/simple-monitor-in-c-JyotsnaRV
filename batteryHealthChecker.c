#include "BmsCheckers.h"

/*
 **********************************************************************************************************************
 * Service name         : batteryIsOk
 * Syntax               : int batteryIsOk(float temperature, float soc, float chargeRate, enum MajorDomain domain, int temperatureSIUnit)
 * param[in]            : temperature
 * param[in]            : soc
 * param[in]            : chargeRate
 * return               : 0 - Battery is Not Ok
                          1 - Battery is Ok
 * Description          : Function which checks the battery health based on temperature, state of charge and charge rate
 ***********************************************************************************************************************
 */
int batteryIsOk(float temperature, float soc, float chargeRate, enum MajorDomain domain, int temperatureSIUnit) {
  return ( (IsTemperatureOk(temperature,domain,temperatureSIUnit)) && (statusOfCharge(soc)) && (rateOfCharge(chargeRate)) );
}
