//
//  Particle.h
//  w10_03_flowField
//
//  Created by Tyler Henry on 3/31/15.
//
//

#pragma once
#include "ofMain.h"

class Particle {
public:
    
    void setup();
    void resetForces();
    void applyForce(ofVec2f force);
    void applyDampingForce(float damp);
    void update();
    void draw();
    
    ofVec2f pos, vel, acc;
    
};