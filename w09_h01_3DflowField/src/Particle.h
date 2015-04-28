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
    
    void setup(float depth);
    void resetForces();
    void applyForce(ofVec3f force);
    void applyDampingForce(float damp);
    void update();
    void draw();
    
    ofVec3f pos, vel, acc;
    
};