/* ************* HEADER FILES DECLARATION ************* */

#include<windows.h>
#include<iostream>

using namespace std;

/* Class Vents is used to control the vent.
    Based on the input, the vent is directed towards the face or feet or face and feet or in windshield defogger mode
*/
class Vents
{
public:
    int ventmode;
    int venttypes(int ventmode)
    {
        try
        {
            if(ventmode== 1)
            {
                cout<< "Face vents\n";
                for (int i=0;i<5;i++)
                {
                    cout<<"->\t";
                    Sleep(1000);
                }
                cout<<"\n";
            }
            else if(ventmode == 2)
            {
                cout<< "Foot vents\n";
                for (int i=0;i<5;i++)
                {
                    cout<<"\n|\n^\n";
                    Sleep(1000);
                }
            }
            else if(ventmode == 4)
            {
                cout<< "Defogging\n";
                for (int i=0;i<5;i++)
                {
                    cout<<" . \t\n";
                    cout<<"o.o\t\n";
                    cout<<" . \t\n";

                    Sleep(1000);
                }
                cout<< "\n";
            }
            else
            {
                throw "invalid vent mode\n";
            }
        }
        catch(const char* msg)
        {
                cout<<msg<<endl;
        }

    }

    int venttypes(int ventmode,char b)
    {
        cout<< "Face and foot vents\n";
        try
        {
            if(ventmode== 3)
            {
                for (int i=0;i<5;i++)
                {
                    cout<<"->\t";
                    Sleep(1000);

                }
                for (int i=0;i<5;i++)
                {
                    cout<<"\n|\n^\n\t\n";
                    Sleep(1000);

                }
            }
            else
            {
                 throw "Invalid. Please try again!\n";
            }
        }
        catch(const char* msg)
        {
                cout<<msg<<endl;
        }
    }
};


