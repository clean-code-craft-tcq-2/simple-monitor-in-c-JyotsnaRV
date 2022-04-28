#include "BmsCheckers.h"
#include "Data_Acquisition_Report.h"

accumulateRange_st dataRange;
/*
 **********************************************************************************************************************
 * Service name         : dataAccumalator
 * Syntax               : void dataAcquisition(toleranceRange_st range)
 * param[in]            : range
 * return               : None
 * Description          : Program to check and accumalte the required BMS data 
 **********************************************************************************************************************
 */

void dataAcquisition(toleranceRange_st range)
{
  warningsGenerator(range);
  (void)controllerAction();
}
