#include "BmsCheckers.h"

int temperatureMax[]= {TEMPERATURE_RESIDENTIAL_MAX, TEMPERATURE_CONSUMER_MAX, TEMPERATURE_EV_MAX};
/*
 **********************************************************************************************************************
 * Service name         : temperatureSectorStatus
 * Syntax               : int temperatureSectorStatus(float temperature, enum MajorDomain domainType, int temperatureSIUnit) 
 * param[in]            : temperature
 * param[in]            : domainType
 * param[in]            : temperatureSIUnit
 * return               : 0 - out of range, 1 - within range
 * Description          : Function that verifies the requested domain validity and its maximum range
 **********************************************************************************************************************
 */
int temperatureSectorStatus(float temperature, enum MajorDomain domainType, int temperatureSIUnit) 
{
	int retStatus = 1;
	/* choose respective domain */
	if( domainType < ( (int)MAXNUMBEROFSECTORS ) )
	{
		retStatus = temperatureStatus(temperature, (float)temperatureMax[domainType], temperatureSIUnit);
	}
	else
	{
		printf("The requested domain is invalid\n\n");
		retStatus = 0;
	}
	/* Return the domain and its temperature status */
	return retStatus;
}
