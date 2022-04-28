#include "BmsCheckers.h"
#include "Data_Acquisition_Report.h"

extern accumulateRange_st dataRange;
/*
 **********************************************************************************************************************
 * Service name         : statusOfCharge
 * Syntax               : int statusOfCharge(float soc)
 * param[in]            : soc
 * return               : 0 - out of range, 1 - in range
 * Description          : Program to check if Charge Rate is out of range
 **********************************************************************************************************************
 */
int statusOfCharge(float soc)
{
  int retStatus = 1;
  toleranceRange_st socRange;
  if(soc < SOC_MIN || soc > SOC_MAX)
  {
    printf("State of Charge(%f) is not with the expected range(%f - %f)!\n\n", soc, SOC_MIN, SOC_MAX);
    retStatus = 0;
    socRange.minTolerance = SOC_MIN;
    socRange.maxTolerance = SOC_MAX;
    socRange.paramType = SOC;
    socRange.inputParameter = soc;
    socRange.tempUnitConv = 0;
    socRange = checkTolerance(socRange);
    dataRange.socInputParam = socRange.inputParameter;
    dataRange.socMinBreach = socRange.minTolerance;
    dataRange.socMaxBreach = socRange.maxTolerance;
    dataAcquisition(socRange);
  }
  dataRange.retstatus = retStatus;
 return retStatus;
}
