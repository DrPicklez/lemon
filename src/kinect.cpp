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
    //grayImage.contrastStretch();
    nearThreshold = 250;
    farThreshold = 150;
    ofSetFrameRate(60);
    angle = 0;
    kinect.setCameraTiltAngle(90);
}
//--------------------------------------------------------------
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
}
