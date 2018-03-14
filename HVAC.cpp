/* ************* HEADER FILES DECLARATION ************* */

#include "FanModule.h"
#include "TemperatureControl.h"
#include "Vents.h"
#include<iostream>
using namespace std;

/* Class HVAC is the main class that controls the operations of HVAC system*/
class HVAC:public TemperatureControl,virtual public FanModule,public Vents
{
public:
    int acmode,hvacinput,tempinput,ventinput,speed;

    /* Function fanspeed() is used to control the speed of the fan */
    virtual int fanspeed()
    {
        while(1)
        {
            cout<<"1.Level 1(Enter 1)\n2.Level 2(Enter 2)\n3.Level 3(Enter 3)\n4.Level 4(Enter 4)\n5.Previous Menu(Enter 5)\nEnter your choice:"<<endl;
            cin>>speed;
            try
            {
                if(speed == 1)
                {
                    cout<< "Speed level 1\n"<<endl;
                    cout<< "--------------------\n"<<endl;
                }
                else if(speed == 2)
                {
                    cout<< "Speed level 2\n"<<endl;
                    cout<< "--------------------\n--------------------\n"<<endl;
                }
                else if(speed == 3)
                {
                    cout<< "Speed level 3\n"<<endl;
                    cout<< "--------------------\n--------------------\n--------------------\n"<<endl;
                }
                else if(speed == 4)
                {
                    cout<< "Speed level 4\n"<<endl;
                    cout<< "--------------------\n--------------------\n--------------------\n--------------------\n"<<endl;
                }
                else if(speed == 5)
                    break;
                else
                {
                    throw "Invalid input.Please try again!";
                }
            }
            catch(const char* msg)
            {
                cout<<msg<<endl;
            }
        }
    }

    /* Function HeaterModule() controls the heater systems of the HVAC*/
  void HeaterModule()
    {
        int heaterlevel;
        while(1)
        {
            cout<<"1.Level 1(Enter 1)\n2.Level 2(Enter 2)\n3.Level 3(Enter 3)\n4.Level 4(Enter 4)\nPrevious Menu(Enter 5)\nEnter your choice:"<<endl;
            cin>>heaterlevel;
            try{
                if(heaterlevel == 1)
                {
                    cout<< "It's at Heater level 1 with "<<HEATERLEVEL1<<" degree celsius\n"<<endl;
                }
                else if(heaterlevel == 2)
                {
                    cout<< "It's at Heater level 2 with "<<HEATERLEVEL2<<" degree celsius\n"<<endl;
                }
                else if(heaterlevel == 3)
                {
                    cout<< "It's at Heater level 3 with "<<HEATERLEVEL3<<" degree celsius\n"<<endl;
                }
                else if(heaterlevel == 4)
                {
                    cout<< "It's at Heater level 4 with "<<HEATERLEVEL4<<" degree celsius\n"<<endl;
                }
                else if(heaterlevel == 5)
                    break;
                else
                {
                    throw "Invalid input.Please try again!";
                }
            }
            catch(const char* msg)
            {
                cout<<msg<<endl;
            }

            }
}

/* Function CoolerModule() controls the cooler systems of the HVAC*/
void  CoolerModule()
    {
        int coolerlevel;
        while(1)
        {
            cout<<"1.Level 1(Enter 1)\n2.Level 2(Enter 2)\n3.Level 3(Enter 3)\n4.Level 4(Enter 4)\n5.Previous Menu(Enter 5)\nEnter your choice:"<<endl;
            cin>>coolerlevel;
            try
            {
                if(coolerlevel == 1)
                {
                    cout<< "It's at Cooler level 1 with "<<COOLERLEVEL1<<" degree celsius\n"<<endl;
                }
                else if(coolerlevel == 2)
                {
                        cout<< "It's at Cooler level 2 with "<<COOLERLEVEL2<<" degree celsius\n"<<endl;
                }
                else if(coolerlevel == 3)
                {
                        cout<< "It's at Cooler level 3 with "<<COOLERLEVEL3<<" degree celsius\n"<<endl;
                }
                else if(coolerlevel == 4)
                {
                        cout<< "It's at Cooler level 4 with "<<COOLERLEVEL4<<" degree celsius\n"<<endl;
                }
                else if(coolerlevel == 5)
                    break;

                else
                {
                        throw "Invalid input.Please try again!";
                }
            }
            catch(const char* msg)
            {
                    cout<<msg<<endl;
            }
        }

    }
};










