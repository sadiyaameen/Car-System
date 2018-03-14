/* ************* HEADER FILES DECLARATION ************* */
//#include <windows.h>
#include <iostream>
#include <stdio.h>
#define MAX_LEVEL 5
#define MIN_LEVEL 0
#define COUNT_OPEN 0
#define RAIN_THRESHOLD 10
#include "SunroofOperation.h"
#include "RainIntensity.h"
#include "ObjectDetection.h"

using namespace std;

/* Class Sunroof is the main class that controls the operations of sunroof*/
class Sunroof:virtual public SunroofOperation,virtual public RainIntensity,public ObjectDetection
{

    int levelOfSunroof;
public:
     Sunroof();
    //void openRoof();
    void openRoof(int);
    void openRoof(int,int);
    void closeRoof(int,int);
    void closeRoof(int);
    void automaticMode();
    void rainIntensityDetect();
    void manualMode();
    //void objectDetected(int);
    int getlevelOfSunroof() const{return levelOfSunroof;}
    void setlevelOfSunroof(int level)
    {
        levelOfSunroof = level;
    }

};

/* Function to control the operations of Automatic Mode */
inline void Sunroof:: automaticMode()
{
    int inputChoice;
    cout<<"IN AUTOMATIC MODE"<<endl;
    cout<<"1.Open Sunroof Completely(Enter 1)\n2.Close Sunroof Completely(Enter 2)\n3.RainIntensity(Enter 3)"<<endl;
    cout<<"Note - Enter 4 to switch to Manual Mode"<<endl;
    cout<<"Enter 5 to exit"<<endl;

    while(1)
    {
        cout<<"Enter you choice:"<<endl;
        cin>>inputChoice;
        try{
        if(inputChoice == 4)
        {
            manualMode();
            break;
        }
        else if(inputChoice == 1)
        {
            if((getlevelOfSunroof()<=MAX_LEVEL) && (getlevelOfSunroof()>MIN_LEVEL))
                openRoof(getlevelOfSunroof(),MIN_LEVEL);
            else
                cout<<"Sunroof completely opened!"<<endl;
        }
        else if(inputChoice == 2)
        {
            bool objectIndicator;
            ObjectDetection o;
            int level = getlevelOfSunroof();
            if((level>=MIN_LEVEL) &&(level<MAX_LEVEL))
            {
                objectIndicator = objectDetected(level);
                if(objectIndicator == 1)
                {
                    cout<<"Object detected at level : "<<getlevelOfObject()<<endl;
                    cout<<"Opening the Sunroof completely"<<endl;
                    openRoof(getlevelOfObject(),MIN_LEVEL);
                    setlevelOfSunroof(MIN_LEVEL);
                }
                else
                {
                    setlevelOfSunroof(MAX_LEVEL);
                }
            }
            else cout<<"Sunroof completely closed!"<<endl;
        }
        else if(inputChoice == 3)
        {
            rainIntensityDetect();
        }
        else if(inputChoice == 5)
            exit(1);
        else
            throw "Invalid Input.Please enter the correct input";

        }
        catch(const char *msg)
        {
            cout<<msg<<endl;
        }
    }
}

/* Function to detect if the rain intensity is above the threshold and close the sunroof if it is open */
inline void Sunroof::rainIntensityDetect()
{
    int senseValue;
    cout<<"Enter the sensor value: "<<endl;
    cin>>senseValue;
    setrainIntensity(senseValue);
    try
    {
        if(senseValue>RAIN_THRESHOLD)
        {
            if(getlevelOfSunroof()<5)
            {
                closeRoof(getlevelOfSunroof(),MAX_LEVEL);
            }
            else
                throw "Sunroof is already closed!";
        }
        else
        throw "Rain is less than the threshold";
    }
    catch(const char *msg)
    {
        cout<<msg<<endl;
    }
}

/* Function to control the operations of Manual Mode */
inline void Sunroof:: manualMode()
{
    int inputChoice;
    cout<<"IN MANUAL MODE"<<endl;
    cout<<"1.Open Sunroof(Enter 1)\n2.Close Sunroof(Enter 2)\n3.Exit(Enter 3)"<<endl;
    cout<<"Note - If at any time you want to switch to Automatic Mode Enter 4"<<endl;
    while(1)
    {
        cout<<"Enter your choice :"<<endl;
        cin>>inputChoice;
        if(inputChoice==4)
        {
            automaticMode();
            break;
        }
        else if(inputChoice==1)
        {
            if(getlevelOfSunroof() == MIN_LEVEL)
                cout<<"Sunroof is completely open!"<<endl;
            else
                openRoof((getlevelOfSunroof()-1));
        }
        else if(inputChoice == 2)
        {
            if(getlevelOfSunroof() == MAX_LEVEL)
                cout<<"Sunroof is completely closed!"<<endl;
            else
                closeRoof(getlevelOfSunroof()+1);
        }
        else if(inputChoice == 3)
            exit(1);
        else
            cout<<"Invalid Input. Please enter a value between 1-2 and enter 4 if you want to switch to manual mode."<<endl;

    }
}

/* Sunroof Default Constructor */
inline Sunroof::Sunroof()
{
    levelOfSunroof = MAX_LEVEL;
}

/* Function to close the sunroof completely if the sunroof is already open in any level between 1-4(Used in Automatic mode) */
inline void Sunroof::closeRoof(int levelOfSunroof, int level)
{
    for(int i=0;i<levelOfSunroof;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<"|\t";
        }
        cout<<"\n";
    }
    for(int i = levelOfSunroof;i<level;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<"|\t";
        }
        Sleep(1000);
        cout<<"\n";
    }
    setlevelOfSunroof(level);
    cout<<endl;
}

/* Function to close the sunroof by one level(used in Manual mode) */
inline void Sunroof::closeRoof(int levelOfSunroof)
{
    for(int i=0;i<levelOfSunroof;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<"|\t";
        }
        Sleep(1000);
        cout<<"\n";
    }
    setlevelOfSunroof(levelOfSunroof);
    cout<<endl;
}

/* Function to open the sunroof completely if the sunroof is already closed in any level between 1-4(Used in Automatic mode) */
inline void Sunroof::openRoof(int levelOfSunroof,int level)
{
    cout<<"\n";
    for (int i=levelOfSunroof; i>level; i--)
    {
        for(int j=0; j<i; j++ )
        {
            cout << "|\t";
        }
        cout << endl;
    }
    setlevelOfSunroof(level);
}

/* Function to open the sunroof by one level(Used in Manual mode) */
inline void Sunroof::openRoof(int level)
{
    cout<<"\n";
    for (int i=level; i>level-1; i--)
    {
        for(int j=0; j<i; j++ )
        {
            cout << "|\t";
        }
        cout << endl;
    }
    setlevelOfSunroof(level);
}





