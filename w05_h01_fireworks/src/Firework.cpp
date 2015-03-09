//
//  Firework.cpp
//  w05_h01_fireworks
//
//  Created by Tyler Henry on 3/7/15.
//
//

#include "Firework.h"

Firework::Firework(ofVec2f _vel, int _size, float _hue){
    vel = _vel; //direction
    size = _size; //size of firework (# of particles)
    hue = _hue; //0-255 in HSB
    
    //start at center bottom of frame
    pos = ofVec2f(ofGetWidth()/2, ofGetHeight());
    
    exploded = false;
    
}

void Firework::resetForces(){
    if (!exploded){
        acc *= 0;
    } else {
        for (int i=0; i<particles.size(); i++){
            particles[i].resetForces();
        }
    }
}

void Firework::applyForce(ofVec2f _force){
    if (!exploded){
        acc += _force;
    } else {
        for (int i=0; i<particles.size(); i++){
            particles[i].update();
        }
    }
    
    
}

void Firework::update(){
    if (!exploded){
        vel += acc;
        pos += vel;
        if (lifecount > 0)
            lifecount--; //countdown to explosion
        else
            explode();
        
    } else {
        for (int i=0; i<particles.size(); i++){
            particles[i].update();
        }
    }
}

void Firework::draw(){
    if (!exploded){
        //draw stream
    } else {
        for (int i=0; i<particles.size(); i++){
            particles[i].draw();
        }
    }
}

void Firework::explode(){
    hue = ofRandom(255);
    for (int i=0;i<size;i++){
        Particle particle(pos, hue, size, 5);
    }
    exploded = true;
}

