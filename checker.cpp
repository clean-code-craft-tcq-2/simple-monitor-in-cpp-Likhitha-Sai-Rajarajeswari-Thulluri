#include <assert.h>
#include <iostream>
using namespace std;

float lowerLimit[3] = {0.0, 20.0, 0.0};
float upperLimit[3] = {45.0, 80.0, 0.8};

bool limitChecker(float value, float lowerLimit, float upperLimit)
{
    if((value < lowerLimit) || (value > upperLimit))
    {
        return false;
    }
    return true;
}


bool batteryIsOk(float temperature, float soc, float chargeRate) {
    string parameterName[3] = {"Temperature", "SOC", "Charge Rate"};
    float parameterValue[3] = {temperature, soc, chargeRate};
    for(int i=0; i<3; i++)
    {
        if(!limitChecker(parameterValue[i], lowerLimit[i], upperLimit[i]))
        {
            std::cout<<parameterName[i]<< " is out of range!"<<std::endl;
            return false;
        }
    }
    return true;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
