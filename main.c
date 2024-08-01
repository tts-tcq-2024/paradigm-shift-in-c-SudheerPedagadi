#include <stdio.h>
#include <assert.h>
#include "battery_check.h"

// Struct to hold test case data
typedef struct {
    float temperature;
    float soc;
    float chargeRate;
} TestCase;

// Array of test cases
TestCase testCases[] = {
    { 25, 70, 0.7 },
    { 0, 20, 0.8 },
    { 45, 80, 0.8 },
    { 50, 85, 0 },
    { -5, 70, 0.7 },
    { 25, 15, 0.7 },
    { 25, 85, 0.7 },
    { 25, 70, 0.85 },
    { 0, 70, 0.7 },
    { 25, 19, 0.7 },
    { 25, 70, 0.81 },
    { 0, 0, 0 },
    { 25, 70, -0.5 },
};

int main() {
    size_t numTestCases = sizeof(testCases) / sizeof(testCases[0]);
    for (size_t i = 0; i < numTestCases; ++i) {
        float temperature = testCases[i].temperature;
        float soc = testCases[i].soc;
        float chargeRate = testCases[i].chargeRate;
        assert(batteryIsOk(temperature, soc, chargeRate));
        assert(!batteryIsOk(temperature, soc, chargeRate));
    }
}
