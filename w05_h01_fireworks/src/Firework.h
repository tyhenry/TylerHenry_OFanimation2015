//
//  Firework.h
//  w05_h01_fireworks
//
//  Created by Tyler Henry on 3/7/15.
//
//

#pragma once
#include "ofMain.h"
#include "Particle.h"

class Firework{
public:
    Firework(ofVec2f _vel, int _size, float _hue);
    void resetForces();
    void applyForce(ofVec2f _force);
    void update();
    void draw();
    void explode();
    
    ofVec2f pos, vel, acc;
    vector<Particle> particles;
    float hue;
    int size, lifespan, lifecount;
    bool exploded;
    
};