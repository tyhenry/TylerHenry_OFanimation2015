//
//  Particle.cpp
//  w05_h01_fireworks
//
//  Created by Tyler Henry on 3/7/15.
//
//

#include "Particle.h"

Particle::Particle(ofVec2f _pos, float _span, float _radius, float _hue){
    
    pos.set(_pos);
    span = _span;
    radius = _radius;
    hue = _hue;
    
    vel.x = ofRandom(-2*(_span),2*_span);
    vel.y = ofRandom(-3*(_span),_span);
    
    lifespan = 180; //3 seconds @ 60fps
    countdown = lifespan;
    
    dead = false;
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
    
    if (countdown > 0){
        countdown--;
    } else {
        dead = true;
        cout << "dead particle" << endl;
    }
}

void Particle::draw(){
    float brightness = ofMap(countdown,0,lifespan,0,255);
    
    ofSetColor(ofColor::fromHsb(hue, 255, brightness));
    
    ofCircle(pos, radius);
}