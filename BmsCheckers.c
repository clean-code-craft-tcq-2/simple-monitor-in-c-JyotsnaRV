#include "BmsCheckers.h"

float temperatureCheck(float temperature)
{
  if(temperature < TEMPERATURE_MIN || temperature > TEMPERATURE_MAX)
  {
    printf("Temperature %f out of range!\n", temperature);
    return 0;
  }
  else
  {
    printf("Temperature %f OK\n", temperature);
    return 1;
  }
}

float statusOfCharge(float soc)
{
  if(soc < SOC_MIN || soc > SOC_MAX)
  {
    printf("State of Charge %f out of range!\n", soc);
    return 0;
  }
  else
  {
    printf("State of Charge %f OK\n", soc);
    return 1;
  }
}

float rateOfCharge(float chargeRate)
{
  if(chargeRate <= CHARGE_RATE_MIN || chargeRate > CHARGE_RATE_MAX)
  {
    printf("Charge Rate %f out of range!\n", chargeRate);
    return 0;
  }
  else
  {
    printf("Charge Rate %f OK\n", chargeRate);
    return 1;
  }
}
