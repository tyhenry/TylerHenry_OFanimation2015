//
//  worm.h
//  w02_h03_gaussianPopulation
//
//  Created by Tyler Henry on 2/15/15.
//
//

#pragma once
#include "ofMain.h"

class worm {
public:
        
    void setup(float _colorDev, float _sizeDev, ofVec2f _posDev);
    void update();
    void draw();
    
private:
    
    ofVec2f pos;
    ofColor color;
    float length;
    float angle;
    float noiseOffset;
};