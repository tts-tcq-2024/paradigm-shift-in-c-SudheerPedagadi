#include <stdio.h>
#include <assert.h>

// Function to print error message and return 0
int checkAndPrintError(int condition, const char *errorMessage) 
{
    if (!condition)
    {
      printf("%s\n", errorMessage);
      return 0;
    }
    return 1;
}

int isTemperatureOk(float temperature)
{
  return checkAndPrintError(temperature >= 0 && temperature <= 45, "Temperature out of range!");
}

int isSocOk(float soc) 
{
  return checkAndPrintError(soc >= 20 && soc <= 80, "State of Charge out of range!");
}

int isChargeRateOk(float chargeRate)
{
  return checkAndPrintError(chargeRate <= 0.8, "Charge Rate out of range!");
}

int batteryIsOk(float temperature, float soc, float chargeRate)
{
  int tempOk = isTemperatureOk(temperature);
  int socOk = isSocOk(soc);
  int chargeRateOk = isChargeRateOk(chargeRate);
  return tempOk && socOk && chargeRateOk;
}

// Struct to hold test case data
typedef struct
{
  float temperature;
  float soc;
  float chargeRate;
} TestCase;

// Array of test cases
TestCase testCases[] = 
{
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

int main()
{
  size_t numTestCases = sizeof(testCases) / sizeof(testCases[0]);
  for (size_t i = 0; i < numTestCases; ++i)
  {
    float temperature = testCases[i].temperature;
    float soc = testCases[i].soc;
    float chargeRate = testCases[i].chargeRate;
    assert(batteryIsOk(temperature, soc, chargeRate));
    assert(!batteryIsOk(temperature, soc, chargeRate));
  }
}

