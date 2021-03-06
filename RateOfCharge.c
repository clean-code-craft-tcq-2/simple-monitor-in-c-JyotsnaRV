#include "BmsCheckers.h"
#include "Data_Acquisition_Report.h"

extern accumulateRange_st dataRange;
/*
 **********************************************************************************************************************
 * Service name         : rateOfCharge
 * Syntax               : int rateOfCharge(float chargeRate) 
 * param[in]            : chargeRate
 * return               : 0 - out of range, 1 - in range
 * Description          : Program to verify if Charge Rate is out of range
 **********************************************************************************************************************
 */
int rateOfCharge(float chargeRate)
{
  int retStatus = 1;
  toleranceRange_st rocRange;
  if(chargeRate > CHARGE_RATE_MAX)
  {
    printf("Charge Rate(%f) is more than the expected range (%f)!\n",chargeRate,CHARGE_RATE_MAX);
    retStatus = 0;
    rocRange.minTolerance = CHARGE_RATE_MAX + (float)0.1;
    rocRange.maxTolerance = 2.0;
    rocRange.paramType = ROC;
    rocRange.inputParameter = chargeRate;
    rocRange.tempUnitConv = 0;
    rocRange = checkTolerance(rocRange);
    dataRange.rocInputParam = rocRange.inputParameter;
    dataRange.rocMinBreach = rocRange.minTolerance;
    dataRange.rocMaxBreach = rocRange.maxTolerance;
    dataAcquisition(rocRange);
  }
  dataRange.retstatus = retStatus;
  return retStatus;
}
