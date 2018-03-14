
using namespace std;

/* Class SunroofOperation is an abstract class which contains openRoof and closeRoof functions as pure virtual functions.
    These functions are also overloaded to meet the needs of Manual mode and Automatic mode */
class SunroofOperation
{
public:
    virtual void openRoof(int) = 0;
    virtual void openRoof(int,int) = 0;
    virtual void closeRoof(int,int) = 0;
    virtual void closeRoof(int) = 0;
};


