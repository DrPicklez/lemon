#ifndef KINECT_H
#define KINECT_H

#include "ofxKinect.h"
#include "ofxOpenCv.h"
#include "ofMain.h"

class Kinect
{
public:
    void setup();
    void update();

    ofxKinect kinect;

    ofxCvColorImage colorImg;
    ofxCvGrayscaleImage grayImage;
    ofxCvGrayscaleImage grayThreshNear;
    ofxCvGrayscaleImage grayThreshFar;
    ofxCvGrayscaleImage greyAv, mult;

    int nearThreshold;
    int farThreshold;
    bool bThreshWithOpenCV;
    int angle;
};

#endif // KINECT_H
