//
//  customCircle.h
//  02_xeno
//
//  Created by Tyler Henry on 2/3/15.
//
//

#pragma once
#include "ofMain.h"

class customCircle {
public:
    void setup();
    void update(ofVec2f _finalPos);
    void draw();
    
    ofVec2f pos, finalPos;
    
    ofColor c;
    float radius, rate;
};
