#include "BmsCheckers.h"
#include "Data_Acquisition_Report.h"

unsigned int accumulateReportCnt;
extern accumulateRange_st dataRange;
void warningsGenerator(toleranceRange_st warningType)
{
  float convTemp = 0.0;
  char warnMessage[WARNING_MSG_CHAR];
  if(warningType.tempUnitConv == FAHR)
  {
	  convTemp = CELTOFAHR(warningType.inputParameter);
	  printf("Requested temperature in Fahrenheit %f \n",convTemp);
  }
  ParamToString(warnMessage,warningType);
  printf(" Breached value - %f \t %s \n",warningType.inputParameter, warnMessage);
}

unsigned int controllerAction()
{
	unsigned int retStatus = 1;
	accumulateRange_st cntrlrAction = dataRange;
	printf("\n\n\nBreached type - %d \n",cntrlrAction.parameterType);
	/* cntrlAction can be used for further action like - email alert, new feauture addition, etc */
	if(dataRange.retstatus < 1)
	{
		accumulateReportCnt++; /* increments when some breach has occured */
		retStatus = 0;
	}
	if(accumulateReportCnt>2)
	{
		accumulateReportCnt = 0;
	}	
	return retStatus;
}
