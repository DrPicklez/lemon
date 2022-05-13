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
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    fbo2.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    mask.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);



    _model.loadModel("lemon.obj", false);
//    _model.loadModel("lemon.obj", false);
    shader.load("shaders_gl3/mirror");

    for(int i = 0; i < nModels; i ++){
        for(int j= 0; j < nModels; j ++){
            _model.setScale(0.2, 0.2, 0.2);
            _model.setPosition((nX * i) + (nX * 0.5),(nY * j) + (nY * 0.5), 0);
            lemons.push_back(_model);       //bang model in shader FFS
        }
    }

    for(int i = 0; i < nModels; i ++){
        for(int j= 0; j < nModels; j ++){
            _model.setScale(0.2, 0.2, 0.2);
            _model.setPosition((nX * i) + (nX * 0.5),(nY * j) + (nY * 0.5), 0);
            lemons2.push_back(_model);
        }
    }

    //for(int i = 0; i < nLeaf; i ++){
    //    for(int j= 0; j < nLeaf; j ++){
    //        _model.setScale(0.05, 0.05, 0.05);
    //        _model.setPosition((xX * i) + (xX * 0.5),(xY * j) + (xY * 0.5), 0);
    //        limes.push_back(_model);
    //    }
    //}
    ofSetBackgroundAuto(false);

}

//--------------------------------------------------------------
bool init = true;
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
            x ++;
        }
    }

    mask.begin();       //  To strech kinect image across width/height
    ofPixels _pix = kinect.grayImage.getPixels();
    _pix.resize(mask.getWidth(), mask.getHeight(), OF_INTERPOLATE_NEAREST_NEIGHBOR);
    ofImage _image;
    _image.setFromPixels(_pix);
    _image.mirror(0, 1);
    _image.draw(0, 0, mask.getWidth(), mask.getHeight());
    mask.end();


    if((ofGetFrameNum() < 150) || (kinect.notConnected)){
        fbo.begin();
        ofSetColor(ofColor::aqua);
        ofPushStyle();
        ofSetLineWidth(5);
        for(int i = 0; i < lemons.size(); i++){
            lemons[i].drawWireframe();
        }
        ofPopStyle();

        ofPushStyle();
        ofSetLineWidth(3);
        ofSetColor(ofColor::yellow);
        for(int i = 0; i < lemons.size(); i++){
            lemons2[i].drawWireframe();
        }
        ofPopStyle();
        init = !init;
        fbo.end();
    }
    else{
        fbo2.begin();
        ofSetColor(ofColor::aqua);
        ofPushStyle();
        ofSetLineWidth(5);
        for(int i = 0; i < lemons.size(); i++){
            lemons[i].drawWireframe();
        }
        ofPopStyle();
        ofPushStyle();
        ofSetLineWidth(3);
        ofSetColor(ofColor::yellow);
        for(int i = 0; i < lemons.size(); i++){
            lemons2[i].drawWireframe();
        }
        ofPopStyle();
        fbo2.end();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofTexture tex2 = fbo.getTexture();
    ofTexture tex = fbo2.getTexture();

    ofTexture _mask = mask.getTexture();
    _mask.setSwizzle(GL_TEXTURE_SWIZZLE_A, GL_RED);
//    ofDisableSmoothing();
    if(!init){
        tex2.draw(0, 0, ofGetWidth(), ofGetHeight());
    }

    ofPushStyle();
    tex.setAlphaMask(_mask);                    //DO THIS IN SHADER FOR FUCK SAKE!
//    ofSetColor(255, 255, 255, 45);
    tex.draw(0, 0, ofGetWidth(), ofGetHeight());
//     ofSetColor(255, 255, 255, 240);
    tex.draw(0, 0, ofGetWidth(), ofGetHeight());
    ofPopStyle();

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
