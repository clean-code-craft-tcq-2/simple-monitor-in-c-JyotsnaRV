#include "BmsCheckers.h"
#include "Data_Acquisition_Report.h"

accumulateRange_st dataRange;
/*
 **********************************************************************************************************************
 * Service name         : dataAccumulator
 * Syntax               : void dataAccumulator(toleranceRange_st range)
 * param[in]            : range
 * return               : None
 * Description          : Program to check and consolidate the required BMS data 
 **********************************************************************************************************************
 */

void dataAccumulator(toleranceRange_st range)
{
  warningsGenerator(range);
  (void)controllerAction();
}
