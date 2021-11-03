#ifndef LIGHTING_H
#define LIGHTING_H
#include "ofMain.h"

class Lighting{

        public:
            void setup();
            void update();
            void beginDraw();
            void endDraw();
        private:
            ofLight light;
};

#endif // LIGHTING_H
