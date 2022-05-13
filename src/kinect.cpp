#include "kinect.h"
//--------------------------------------------------------------
void Kinect::setup(){
    kinect.init(false, false); //rid RGB for faster depth
    kinect.open();

    //Cv Setup
    colorImg.allocate(kinect.width, kinect.height);
    grayImage.allocate(kinect.width, kinect.height);
    grayThreshNear.allocate(kinect.width, kinect.height);
    grayThreshFar.allocate(kinect.width, kinect.height);
    mult.allocate(kinect.width, kinect.height);
    nearThreshold = 220;
    farThreshold = 130;
    ofSetFrameRate(60);
    angle = 0;
    //kinect.setCameraTiltAngle(90);
    mult.set(0.5);

}
//--------------------------------------------------------------
vector <ofxCvGrayscaleImage> buffer;

void Kinect::update(){
    kinect.update();
    if(kinect.isFrameNew()) {
        grayImage.setFromPixels(kinect.getDepthPixels());
        grayThreshNear = grayImage;
        grayThreshFar = grayImage;
        grayThreshNear.threshold(nearThreshold, true);
        grayThreshFar.threshold(farThreshold);
        cvAnd(grayThreshNear.getCvImage(), grayThreshFar.getCvImage(), grayImage.getCvImage(), NULL);
        grayImage.flagImageChanged();
    }
    notConnected = !kinect.isConnected();
}

