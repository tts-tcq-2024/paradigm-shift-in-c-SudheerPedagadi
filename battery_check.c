#include "battery_check.h"
#include <stdio.h>
#include <assert.h>
#include "language_support.h"

#define TEMPERATURE_MIN 0
#define TEMPERATURE_MAX 45
#define SOC_MIN 20
#define SOC_MAX 80
#define CHARGE_RATE_MAX 0.8

// Global variable for language setting (0: English, 1: German)
int language = 0;

int checkAndPrintError(int condition, const char *errorMessage) {
    if (!condition) {
        printf("%s\n", translateMessage(errorMessage));
        return 0;
    }
    return 1;
}

int isTemperatureOk(float temperature) {
    return checkAndPrintError(temperature >= TEMPERATURE_MIN && temperature <= TEMPERATURE_MAX, "Temperature out of range!");
}

int isSocOk(float soc) {
    return checkAndPrintError(soc >= SOC_MIN && soc <= SOC_MAX, "State of Charge out of range!");
}

int isChargeRateOk(float chargeRate) {
    return checkAndPrintError(chargeRate <= CHARGE_RATE_MAX, "Charge Rate out of range!");
}

void checkAndPrintWarning(float temperature, float soc, float chargeRate) {
    float socWarningLower = SOC_MIN + 0.05 * SOC_MAX;
    float socWarningUpper = SOC_MAX - 0.05 * SOC_MAX;
    float tempWarningLower = TEMPERATURE_MIN + 0.05 * TEMPERATURE_MAX;
    float tempWarningUpper = TEMPERATURE_MAX - 0.05 * TEMPERATURE_MAX;

    if (temperature <= tempWarningLower) {
        printf("%s\n", translateMessage("Approaching discharge"));
    } else if (temperature >= tempWarningUpper) {
        printf("%s\n", translateMessage("Approaching charge-peak"));
    }

    if (soc <= socWarningLower) {
        printf("%s\n", translateMessage("Approaching discharge"));
    } else if (soc >= socWarningUpper) {
        printf("%s\n", translateMessage("Approaching charge-peak"));
    }
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    int tempOk = isTemperatureOk(temperature);
    int socOk = isSocOk(soc);
    int chargeRateOk = isChargeRateOk(chargeRate);
    checkAndPrintWarning(temperature, soc, chargeRate);
    return tempOk && socOk && chargeRateOk;
}
