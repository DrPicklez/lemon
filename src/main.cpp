#include "ofMain.h"
#include "ofApp.h"
#include "ofUtils.h"
//========================================================================
int main( ){
   ofSetupOpenGL(1920, 1080, OF_FULLSCREEN);			// <-------- setup the GL context


    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:


   // ofGLFWWindowSettings settings;
   //
   //
   // settings.setGLVersion(4,6);
   // settings.setSize(1920, 1080);
   // settings.windowMode = OF_FULLSCREEN;
   // ofCreateWindow(settings);

    ofRunApp(new ofApp());


}
