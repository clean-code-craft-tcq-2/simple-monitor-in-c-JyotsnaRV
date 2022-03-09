#ifndef BATTERY_HEALTH_CHECKER_H
#define BATTERY_HEALTH_CHECKER_H

/* Declarations */
int batteryIsOk(float temperature, float soc, float chargeRate, enum MajorDomain domain, int temperatureSIUnit);

#endif /* BATTERY_HEALTH_CHECKER_H */
