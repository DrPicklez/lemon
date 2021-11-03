#include "lighting.h"

void Lighting::setup(){

}

void Lighting::update(){

    light.setPosition(ofGetMouseX(), ofGetMouseY(), 2000);
    light.setAmbientColor(ofColor::yellow);

}

void Lighting::beginDraw(){
    ofEnableDepthTest();
#ifndef TARGET_PROGRAMMABLE_GL
    glShadeModel(GL_SMOOTH); //some model / light stuff
#endif
    light.enable();
    ofEnableSeparateSpecularLight();
}

void Lighting::endDraw(){
    ofDisableDepthTest();
    light.disable();
    ofDisableLighting();
    ofDisableSeparateSpecularLight();
}
