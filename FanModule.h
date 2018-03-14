using namespace std;

/* Class FanModule is an abstract class that contains fanspeed() as a pure virtual function*/
class FanModule
{
int speed;
    public:

        FanModule()
        {
            speed = 0;
        }

        virtual int fanspeed()=0;
};



