#include "BmsCheckers.h"
#include "Data_Acquisition_Report.h"

const char* MinToleranceNames[] = {"Low_Temperature", "Approaching_discharge", "LOW_ROC"};
const char* MaxToleranceNames[] = {"High_Temperature_Charging_Paused", "Approaching_charge_peak", "HIGH_ROC"};
extern accumulateRange_st dataRange;
toleranceRange_st checkTolerance(toleranceRange_st range)
{
  range.minTolerance += CALCTOLERANCE(range.minTolerance);
  range.maxTolerance -= CALCTOLERANCE(range.maxTolerance);
  if(range.inputParameter <= range.minTolerance)
  {
	  range.dataVal = BINARY_MIN;
	  dataRange.breachMinType = range.dataVal;
  }
  if(range.inputParameter >= range.maxTolerance)
  {
	  range.dataVal = BINARY_MAX;
	  dataRange.breachMaxType = range.dataVal;
  }
  return range;
}

void ParamToString(char* buffer, toleranceRange_st inputDetails)
{
  switch(inputDetails.dataVal)
  {
    case BINARY_MIN:
      {
        sprintf(buffer, "%s ",
        MinToleranceNames[inputDetails.paramType]);
      }
      break;
    case BINARY_MAX:
      {
        sprintf(buffer, "%s ",
        MaxToleranceNames[inputDetails.paramType]);
      }
      break;
    default:/* do nothing */ break;
  }
}
