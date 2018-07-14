#include"InvFireDetector.h"

using namespace std;

/*
The comment section here is for the interface function to be used by the main program, that is, the rewriting of the main function of our own program.
Parameter description: int width, int height, int nChannel, uchar* pData
    Image width, channel number, data pointer (hopefully BGR channel data, otherwise you need to notify us to modify);
    bool &invAlarm, bool &fireAlarm
 
These are the signals of intrusion detection and fire detection, respectively. If one of the types of events occurs, this signal is true;
In addition: The following two external variables
    InvFireDetector test;
    IplImage* pFrame = NULL;
It is better to define it in the function above your level;
There is also a resource recycling function that will be executed after the image processing has finished:
    test.release();
To call this interface function, you need to include all *.cpp and *.h of this project in the project, including #include "InvFireDetector.h" in the CPP you need to call;
Then you need to do the correct OpenCV configuration to run;

InvFireDetector test;
IplImage* pFrame = NULL;
void InvFireDetect(int width,int height,int nChannel,uchar* pData,bool &invAlarm,bool &fireAlarm)
{
        static int counter=0;
        counter++;
        if(counter ==1)
        {
                pFrame = cvCreateImage(cvSize(width,height),IPL_DEPTH_8U,nChannel);
                pFrame->imageData = (char*)pData;
                test.init(pFrame,WAVE_NAME);
        }
        else
        {
                pFrame->imageData = (char*)pData;
                test.update(pFrame);
                test.show();
                cvWaitKey(10);
        }

        invAlarm = test.invAlarm;
        fireAlarm = test.fireAlarm;
}

 */

int main(int argc, char** argv) {
    /*statistical data*/
    int invTotleNum = 0;
    int fireTotleNum = 0;
    //**************

    IplImage* pFrame = NULL;
    CvCapture* pCapture = NULL;
    if (!(pCapture = cvCreateFileCapture(argv[1]))) {
        fprintf(stderr, "Can not open video file %s\n", argv[1]);
        return -2;
    }

    InvFireDetector test;

    if (pFrame = cvQueryFrame(pCapture)) {
        test.init(pFrame, WAVE_NAME);
        cvWaitKey(WAIT_TIME);
    }
    //***************************************************************************
    while (pFrame = cvQueryFrame(pCapture)) {
        test.update(pFrame);
        test.show();
        //test.keyMenu();
        invTotleNum += test.blockNum;
        fireTotleNum += test.fireBlockNum;
        int posFrames = (int) cvGetCaptureProperty(pCapture, CV_CAP_PROP_POS_FRAMES);
        int posMsecs = (double) cvGetCaptureProperty(pCapture, CV_CAP_PROP_POS_MSEC);
        cout << posFrames << "     " << posMsecs << "      " << "fireAlarm:" << test.fireAlarm << "  invAlarm:" << test.invAlarm << "  invTotle:" << \
 invTotleNum << "  fireTotle" << fireTotleNum << endl;
    }
    //***************************************************************************
    //Free up memory
    test.release();
    int temp;
    cin>>temp;
    return 0;
}