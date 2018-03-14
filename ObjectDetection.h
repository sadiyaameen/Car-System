
using namespace std;

/* Class ObjectDetection contains objectDetected() which detects the object and stores the level at which the object is detected*/
class ObjectDetection
{

    bool isObjectDetected;
    int levelOfObject;
public:
    bool objectDetected(int level);
    ObjectDetection()
    {
        isObjectDetected = 0;
    }
    int getlevelOfObject()const{return levelOfObject;}
};

/* Function to detect the object and store at which level the object is detected, returns if the object is detected or not*/
inline bool ObjectDetection::objectDetected(int level)
{
    char object;
   for (int i=level; i<=MAX_LEVEL; i++)
    {
        for(int j=0; j<i; j++ )
        {
        cout << "|\t";
        }
        scanf("%c",&object);
        if(int(object)!=10)
        {
            isObjectDetected = 1;
            levelOfObject = i;
            break;
        }
    }
   return isObjectDetected;
}



