#ifndef BATTERY_CHECK_H
#define BATTERY_CHECK_H

int checkAndPrintError(int condition, const char *errorMessage);
int isTemperatureOk(float temperature);
int isSocOk(float soc);
int isChargeRateOk(float chargeRate);
int batteryIsOk(float temperature, float soc, float chargeRate);
void checkAndPrintWarning(float temperature, float soc, float chargeRate);

#endif // BATTERY_CHECK_H
