#include <assert.h>
#include <iostream>
#include <string.h>
using namespace std;

const float tempLowerLimit = 0.0F;
const float tempUpperrLimit = 45.0F;
const float socLowerLimit = 20.0F;
const float socUpperLimit = 80.0F;
const float chargeRateLowerLimit = 0.0F;
const float chargeRateUpperrLimit = 0.8F;

void printOnConsole(string str)
{
    std::cout<<str;
}

bool checkIfValueisWithinThreshold(string parameterName, float lowerLimit, float upperLimit, float value)
{
    if(value < lowerLimit)
    {
        printOnConsole(parameterName+" value is less than lower limit "+to_string(lowerLimit));
        return false;
    }
    else if(value > upperLimit)
    {
        printOnConsole(parameterName+" value is more than upper limit "+to_string(upperLimit));
        return false;
    }
    return true;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    string parameterName[3] = {"Temperature", "SOC", "Charge Rate"};
    return checkIfValueisWithinThreshold("Temperature", tempLowerLimit, tempUpperrLimit, temperature) 
                && checkIfValueisWithinThreshold("SOC", socLowerLimit, socUpperLimit, soc)
                && checkIfValueisWithinThreshold("chargeRate", chargeRateLowerLimit, chargeRateUpperrLimit, chargeRate);
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
