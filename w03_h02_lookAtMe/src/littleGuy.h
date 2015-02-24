//
//  littleGuy.h
//  w03_h02_lookAtMe
//
//  Created by Tyler Henry on 2/24/15.
//
//

#pragma once
#include "ofMain.h"

class LittleGuy {
public:
    
    void setup();
    void update(float _mX, float _mY);
    void draw();
    
    ofVec2f oPos, pos, p1, p2, p3;
    float rot;
    ofColor c, newC;
};
