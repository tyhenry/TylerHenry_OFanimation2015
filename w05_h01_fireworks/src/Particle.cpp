//
//  Particle.cpp
//  w05_h01_fireworks
//
//  Created by Tyler Henry on 3/7/15.
//
//

#include "Particle.h"

Particle::Particle(ofVec2f _pos, float _hue, float _span, float _radius){
    pos.set(_pos);
    vel.x = ofRandom(-_span,_span);
    vel.y = ofRandom(-_span,_span);
    lifespan = 360; //6 seconds @ 60fps
    
    hue = _hue;
    radius = _radius;
    
    lifecount = lifespan;
}

void Particle::resetForces(){
    acc *= 0;
    
}

void Particle::applyForce(ofVec2f force){
    acc += force;
}

void Particle::update(){
    vel += acc;
    pos += vel;
    
    if (lifecount > 0) lifecount--;
}

void Particle::draw(){
    float brightness = ofMap(lifecount,0,lifespan,0,255);
    
    ofSetColor(ofColor::fromHsb(hue, 255, brightness));
    
    ofCircle(pos, radius);
}