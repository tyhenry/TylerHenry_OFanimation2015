//
//  Bloom.h
//  midterm_particlestest
//
//  Created by Tyler Henry on 3/17/15.
//
//

#pragma once
#include "ofMain.h"
#include "Particle.h"

class Bloom{
public:
    
    Bloom(ofVec2f _pos, int size, float hue);
    void resetForces();
    void applyForce(ofVec2f force);
    void applyDampingForce(float damping);
    void update(ofVec2f mousePos);
    void draw();
    
    ofVec2f pos;
    int size;
    float hue;
    vector<Particle> particles;
    
    bool dead; //track life of bloom
};
