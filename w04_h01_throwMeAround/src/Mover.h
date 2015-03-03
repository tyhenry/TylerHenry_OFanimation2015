//
//  Mover.h
//  w04_h01_throwMeAround
//
//  Created by Tyler Henry on 3/3/15.
//
//

#pragma once
#include "ofMain.h"

class Mover {
public:
    
    void setup(float x, float y, float _mass);
    void update();
    void resetForces();
    void applyForce(ofVec2f force);
    void applyDampingForce(float damping);
    void draw();
    
    ofVec3f pos, vel, acc;
    float mass;
    float hue;
};