/* ************* HEADER FILES DECLARATION ************* */
#include <iostream>

using namespace std;

/* Class RainIntensity is an abstract class that contains rainIntensityDetect() as a pure virtual function*/
class RainIntensity
{
    float rainIntensity;
public:
    RainIntensity()
    {
        rainIntensity = 0;
    }
    setrainIntensity(float rain)
    {
        rainIntensity = rain;
    }
    virtual void rainIntensityDetect() = 0;

};

