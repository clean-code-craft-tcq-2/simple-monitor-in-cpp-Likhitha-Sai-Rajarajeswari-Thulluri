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
    std::cout<<str<<endl;
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

void testBatteryIsOk(float temperature, float soc, float chargeRate, bool expectedResult)
{
    assert(batteryIsOk(temperature, soc, chargeRate) == expectedResult);
}

int main() {
    testBatteryIsOk(25, 70, 0.7, true);
    testBatteryIsOk(50, 85, 0, false);
    testBatteryIsOk(-2, 75, 0, false);
    testBatteryIsOk(34, 85, 0, false);
    testBatteryIsOk(34, 15, 0, false);
    testBatteryIsOk(34, 25, 1, false);
    testBatteryIsOk(34, 25, -0.1, false);
}
