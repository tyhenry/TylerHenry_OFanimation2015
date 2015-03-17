//
//  Cycloid.h
//  midterm_particlestest
//
//  Created by Tyler Henry on 3/17/15.
//
//

#pragma once
#include "ofMain.h"

class Cycloid{
public:
    
    void setup(ofVec2f _pos, float _radius, float _wheelRadius);
    
    void resetForces();
    void applyForce(ofVec2f force);
    void rotate(float _angle);
    
    void update();
    void draw();
    
    
    ofVec2f pos, vel, acc;
    float radius, wheelRadius;
    
    ofPolyline trace;
    
    bool dead; //track life of cycloid
    
};
