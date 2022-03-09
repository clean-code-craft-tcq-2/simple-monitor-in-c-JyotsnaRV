#include "BmsCheckers.h"
#include "Data_Acquisition_Report.h"

extern acqRange_st dataRange;
/*
 **********************************************************************************************************************
 * Service name         : temperatureStatus
 * Syntax               : int temperatureStatus(float temperature, float compareTemp, int tempSIUnit) 
 * param[in]            : compareTemp
 * param[in]            : tempSIUnit
 * return               : 0 - out of range, 1 - in range
 * Description          : Program to verify whether requested temperature is out of threshold range
 **********************************************************************************************************************
 */
int temperatureStatus(float temperature, float compareTemp, int tempSIUnit) 
{
	int retStatus = 1;
	toleranceRange_st tempRange;
	/* Check if the temperature is out of range */
	if((temperature>(float)TEMP_MIN) && (temperature > cmprTemperature))
	{
		retStatus = 0;
                printf("temperature %f has breached the expected range(%d - %f)celcius!\n",temperature,TEMP_MIN,cmprTemperature);
		tempRange.minTolerance = (float)TEMP_MIN;
		tempRange.maxTolerance = cmprTemperature;
		tempRange.paramType = TEMPERATURE;
		tempRange.inputParam = temperature;
		tempRange.tempUnitConv = tempUnit;
		tempRange = checkTolerance(tempRange);
		dataRange.tempInputParam = tempRange.inputParam;
		dataRange.tempMinBreach = tempRange.minTolerance;
		dataRange.tempMaxBreach = tempRange.maxTolerance;
		dataAcquisition(tempRange);
	}
	dataRange.retstatus = retStatus;
	return retStatus;
}