//
//  Particle.h
//  midterm_particlestest
//
//  Created by Tyler Henry on 3/17/15.
//
//

#pragma once
#include "ofMain.h"

class Particle {
public:
    
    Particle(ofVec2f _pos, float _vel, float _radius, float _hue); //constructor
    void resetForces();
    void applyForce(ofVec2f force);
    void applyDampingForce(float damping);
    void update(ofVec2f handOnePos, ofVec2f handTwoPos, ofVec2f oPos);
    void draw();
    
    ofVec2f pos, vel, acc, p1, p2, p3;
    float lifespan, countdown; //in frames
    bool dead;
    
    float rot, span, radius, hue;

};