//
//  Explosion.h
//  w05_h01_fireworks
//
//  Created by Tyler Henry on 3/10/15.
//
//

#pragma once
#include "ofMain.h"
#include "Particle.h"

class Explosion{
public:
    
    Explosion(ofVec2f _pos, int size, float hue);
    void resetForces();
    void applyForce(ofVec2f _force);
    void update();
    void draw();
    
    ofVec2f pos;
    int size;
    float hue;
    vector<Particle> particles;
    
    bool dead; //track life of explosion
};