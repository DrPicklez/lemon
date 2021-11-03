#pragma once

#include "ofMain.h"
#include "model.h"
#include "lighting.h"
#include "kinect.h"
#include "ofxOpenCv.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    vector <ofxAssimpModelLoader> lemons, lemons2, limes;
    ofFbo fbo, mask;
    Kinect kinect;
    ofShader shader;

};
