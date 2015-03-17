//
//  Rocket.cpp
//  w05_h01_fireworks
//
//  Created by Tyler Henry on 3/10/15.
//
//

#include "Rocket.h"

Rocket::Rocket(ofVec2f _vel, float _size, float _hue){
    pos.set(ofGetWidth()/2, ofGetHeight()); //start at center bottom of screen
    
    vel.set(_vel);
    size = _size;
    hue = _hue;
    
    lifespan = 90; //1.5 sec @ 60 fps
    countdown = lifespan;
    
    explode = false; //tracks whether explosion is ready
}

void Rocket::resetForces(){
    acc *= 0;
}

void Rocket::applyForce(ofVec2f force){
    acc += force;
}

void Rocket::update(){
    vel += acc;
    pos += vel;
    
    if (countdown > 0){
        countdown--;
    } else {
        explode = true;
    }
}

void Rocket::draw(){
    ofSetColor(ofColor::fromHsb(hue,122,(ofMap(countdown, lifespan, 0, 150,255)))); //half sat, and gain brightness
    if (!explode){
        ofCircle(pos, ofMap(size, 50, 100, 3,7));
    }
}