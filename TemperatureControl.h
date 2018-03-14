/* ************* HEADER FILES DECLARATION ************* */

#include<iostream>

using namespace std;

/* ************* GLOBAL VARIABLES INITIALIZATION ************* */
#define HEATERLEVEL1 26
#define HEATERLEVEL2 28
#define HEATERLEVEL3 30
#define HEATERLEVEL4 32
#define COOLERLEVEL1 22
#define COOLERLEVEL2 20
#define COOLERLEVEL3 18
#define COOLERLEVEL4 16

/* Class TemperatureControl contains HeaterModule and CoolerModule are friend functions which can access the private variable roomtemp*/
class TemperatureControl
{
private:
    int roomtemp;

public:
        TemperatureControl()
        {
            roomtemp=24;
        }
        friend void HeaterModule();
        friend void CoolerModule();
};







