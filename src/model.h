#ifndef MODEL_H
#define MODEL_H
#include "ofxAssimpModelLoader.h"
#include "ofMain.h"

class  ModelShop
{
    public:
        void setup(int nModels);
        void update();
        void draw();
        void rotate(ofVec3f rotate);
        int seed;
        void drawMesh();

        ofxAssimpModelLoader model;
        ofMesh mesh;

        bool bHelpText;
        bool bAnimate;
        bool bAnimateMouse;
        float animationPosition;


};

#endif // MODEL_H
