#include "BmsCheckers.h"

float temperatureCheck(float temperature)
{
  if(temperature < TEMPERATURE_MIN || temperature > TEMPERATURE_MAX)
  {
    printf("Temperature %.2f out of range!\n", temperature);
    return 0;
  }
  else
  {
    printf("Temperature %.2f OK\n", temperature);
    return 1;
  }
}

float statusOfCharge(float soc)
{
  if(soc < SOC_MIN || soc > SOC_MAX)
  {
    printf("State of Charge %.2f out of range!\n", soc);
    return 0;
  }
  else
  {
    printf("State of Charge %.2f OK\n", soc);
    return 1;
  }
}

float rateOfCharge(float chargeRate)
{
  if(chargeRate <= CHARGE_RATE_MIN || chargeRate > CHARGE_RATE_MAX)
  {
    printf("Charge Rate %.2f out of range!\n", chargeRate);
    return 0;
  }
  else
  {
    printf("Charge Rate %.2f OK\n", chargeRate);
    return 1;
  }
}
