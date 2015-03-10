//
//  Rocket.h
//  w05_h01_fireworks
//
//  Created by Tyler Henry on 3/10/15.
//
//

#pragma once
#include "ofMain.h"

class Rocket{
public:
    Rocket(ofVec2f _vel, float _size, float _hue);
    void resetForces();
    void applyForce(ofVec2f force);
    void update();
    void draw();
    
    ofVec2f pos, vel, acc;
    float size, hue;
    float lifespan, countdown;
    bool explode;
};

