#include "model.h"

//--------------------------------------------------------------
int animationPosition  = 0;
void ModelShop::setup(int nModels){
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofBackground(50, 0);

    ofDisableArbTex(); // we need GL_TEXTURE_2D for our models coords.

    model.loadModel("lemon.obj", false);
    model.setPosition(0, 0 , 0);
    model.setScale(0.1, 0.1, 0.1);
    //model.disableColors();
    if(!bAnimate) {
        model.setPausedForAllAnimations(true);
    }
}

//--------------------------------------------------------------
void ModelShop::update(){
    model.update();
    model.setPositionForAllAnimations(animationPosition);
}

//--------------------------------------------------------------
void ModelShop::draw(){
//    ofSetBackgroundColor(ofColor::aqua);
//    cout << model.getSceneMax() << endl;
    float Xres = 21;
    float Yres = 13;
    float xPos = (ofGetWidth()/Xres);
    float yPos = (ofGetHeight()/Yres);
    for(int x = 0; x < Xres; x++){
        for(int y = 0; y < Yres; y++){
            ofPushMatrix();
            ofTranslate((xPos * x) + (xPos * 0.5), (yPos * y) + (yPos * 0.5), 0);
            ofRotateRad(TWO_PI * ofNoise(x * 0.1, y* 0.1), float(1./ofGetWidth()) * ofGetMouseX(), float(1./ofGetHeight()) * ofGetMouseY(), float(1./ofGetWidth()) * ofGetMouseX());
            model.drawFaces();
            ofPopMatrix();
        }
    }
}


//--------------------------------------------------------------
void ModelShop::drawMesh(){
    model.drawWireframe();
}
