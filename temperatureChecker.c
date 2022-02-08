#include "commonDeclarations.h"

float temperatureCheck(float temperature)
{
  if(temperature < 0 || temperature > 45)
  {
    printf("Temperature out of range!\n");
    return 0;
  }
  else
  {
    printf("Temperature OK\n");
    return 1;
  }
}

float statusOfCharge(float soc)
{
  if(soc < 20 || soc > 80)
  {
    printf("State of Charge out of range!\n");
    return 0;
  }
  else
  {
    printf("State of Charge OK\n");
    return 1;
  }
}

float rateOfCharge(float chargeRate)
{
  if(chargeRate > 0.8)
  {
    printf("Charge Rate out of range!\n");
    return 0;
  }
  else
  {
    printf("Charge Rate OK\n");
    return 1;
  }
}
