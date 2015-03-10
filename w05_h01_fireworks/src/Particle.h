//
//  Particle.h
//  w05_h01_fireworks
//
//  Created by Tyler Henry on 3/7/15.
//
//

#pragma once
#include "ofMain.h"

class Particle {
public:
    
    Particle(ofVec2f _pos, float _hue, float _span, float _radius); //constructor
    void resetForces();
    void applyForce(ofVec2f force);
    
    void update();
    void draw();
    
    ofVec2f pos, vel, acc;
    float lifespan, countdown; //in frames
    bool dead;
    
    float span, radius, hue;
};
