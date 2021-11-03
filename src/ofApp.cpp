#include "ofApp.h"

//--------------------------------------------------------------
int nModels = 10;
void ofApp::setup(){
    int nX = ofGetWidth() / nModels;
    int nY = ofGetHeight() / nModels;
    int nLeaf = 5;
    int xX = ofGetWidth() / nLeaf;
    int xY = ofGetHeight() / nLeaf;
    ofxAssimpModelLoader _model;
    kinect.setup();
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGB);
    mask.allocate(ofGetWidth(), ofGetHeight(), GL_RGB);

    _model.loadModel("lemon.obj", false);
//    _model.loadModel("lemon.obj", false);
    shader.load("shaders_gl3/mirror");

    for(int i = 0; i < nModels; i ++){
        for(int j= 0; j < nModels; j ++){
            _model.setScale(0.2, 0.2, 0.2);
            _model.setPosition((nX * i) + (nX * 0.5),(nY * j) + (nY * 0.5), 0);
            lemons.push_back(_model);
        }
    }

    for(int i = 0; i < nModels; i ++){
        for(int j= 0; j < nModels; j ++){
            _model.setScale(0.2, 0.2, 0.2);
            _model.setPosition((nX * i) + (nX * 0.5),(nY * j) + (nY * 0.5), 0);
            lemons2.push_back(_model);
        }
    }

    for(int i = 0; i < nLeaf; i ++){
        for(int j= 0; j < nLeaf; j ++){
            _model.setScale(0.05, 0.05, 0.05);
            _model.setPosition((xX * i) + (xX * 0.5),(xY * j) + (xY * 0.5), 0);
            limes.push_back(_model);
        }
    }



    ofSetBackgroundAuto(false);

}

//--------------------------------------------------------------

void ofApp::update(){
    kinect.update();
    float rider = ofGetElapsedTimeMillis() * 0.09;
    int x = 0;
    for(int i = 0; i < nModels; i ++){
        for(int j = 0; j < nModels; j ++){
            int nRider = (i * nModels) + j;
            float tang = rider * 0.001;

            lemons[x].setRotation(1, rider + ((j+1) * (i+1) * 20), ofNoise(j + tang), ofNoise(i + tang +30), ofNoise(j + tang));
            lemons2[x].setRotation(1,rider + ((j+1) * (i+1) * 20), ofNoise(i + tang + 50), ofNoise(j + tang), ofNoise(i + tang+ 70));

            if(x < limes.size()){
                limes[x].setRotation(1,rider + ((j+1) * (i+1) * 20), ofNoise(i + tang + 50), ofNoise(j + tang), ofNoise(i + tang+ 70));
            }

//            tang = rider * 0.01;
            //limes[x].setPosition(ofNoise(i + tang + 50) * xX, ofNoise(j + tang) * xY, ofNoise(i + tang + 70));
//            lemons[x].setRotation(1, rider + ((j+3) * (i+ 5) * 20), ofNoise(j + tang), ofNoise(i + tang + 3), ofNoise(j + tang + 4));
//            lemons2[x].setRotation(1, rider + ((j * i * 50)), ofNoise(i + tang + 7), ofNoise(j + tang + 2), ofNoise(i + tang + 10));
            x ++;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    fbo.begin();

    ofSetColor(ofColor::aqua);
    for(int i = 0; i < lemons.size(); i++){
        lemons2[i].drawWireframe();
    }
    ofSetColor(ofColor::yellow);
    for(int i = 0; i < lemons.size(); i++){
        lemons[i].drawWireframe();
    }

    fbo.end();

    mask.begin();       //  To strech kinect image across width/height
    kinect.colorImg.draw(0, 0, ofGetWidth(), ofGetHeight());
    mask.end();

    ofTexture tex = fbo.getTexture();
    tex.setAlphaMask(mask.getTextureReference());                    //DO THIS IN SHADER FOR FUCK SAKE!

    tex.draw(0, 0, ofGetWidth(), ofGetHeight());

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}