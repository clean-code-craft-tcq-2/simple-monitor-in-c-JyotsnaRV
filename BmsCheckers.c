#include "BmsCheckers.h"

float IsTemperatureOk(float temperature)
{
  if(temperature < TEMPERATURE_MIN)
  {
    printf("Temperature %.2f crossed minimum threshold value! Increase the temperature of the system.\n", temperature);
    return 0;
  }
  else if(temperature > TEMPERATURE_MAX)
  {
    printf("Temperature %.2f crossed maximum threshold value! Reduce the temperature of the system.\n", temperature);
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
  if(soc < SOC_MIN)
  {
    printf("State of Charge %.2f crossed minimum threshold value! Increase the SoC of the system!\n", soc);
    return 0;
  }
  else if(soc > SOC_MAX)
  {
    printf("State of Charge %.2f crossed maximum threshold value! Reduce the SoC of the system!\n", soc);
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
  if(chargeRate <= CHARGE_RATE_MIN)
  {
    printf("Charge Rate %.2f is too low! Increase the Rate of Charge of the system.\n", chargeRate);
    return 0;
  }
  else if(chargeRate > CHARGE_RATE_MAX)
  {
    printf("Charge Rate %.2f is too high! Decrease the Rate of Charge of the system.\n", chargeRate);
    return 0;
  }
  else
  {
    printf("Charge Rate %.2f OK\n", chargeRate);
    return 1;
  }
}
