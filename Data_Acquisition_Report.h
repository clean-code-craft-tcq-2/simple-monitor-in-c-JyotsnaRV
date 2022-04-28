#ifndef DATA_ACQUISITION_REPORT_H
#define DATA_ACQUISITION_REPORT_H

#include <stdio.h>
#include <assert.h>

/* Structure */
typedef struct
{
	int parameterType;
	float tempInputParam;
	float tempMinBreach;
	float tempMaxBreach;
	float socInputParam;
	float socMinBreach;
	float socMaxBreach;
	float rocInputParam;
	float rocMinBreach;
	float rocMaxBreach;
	int breachMinType; /* can be maintained as 1 byte integer in future update */
	int breachMaxType; /* can be maintained as 1 byte integer in future update */
	int retstatus;
}accumulateRange_st;

#endif /* DATA_ACQUISITION_REPORT_H */
