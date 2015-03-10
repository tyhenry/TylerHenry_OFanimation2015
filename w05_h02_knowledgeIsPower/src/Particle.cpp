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
    
    vel.x = ofRandom(-1*(_span),1*_span);
    vel.y = ofRandom(-1*(_span),1*_span);
    
    lifespan = 360; //3 seconds @ 60fps
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
    
    //check edges
    if (pos.x < 0){
        pos.x = 0;
        vel.set(-1*vel.x, vel.y);
    }
    else if (pos.x > ofGetWidth()){
        pos.x = ofGetWidth();
        vel.set(-1*vel.x, vel.y);
    }
    else if (pos.y < 0){
        pos.y = 0;
        vel.set(vel.x, -1*vel.y);
    }
    else if (pos.y > ofGetHeight()){
        pos.y = ofGetHeight();
        vel.set(vel.x, -1*vel.y);
    }
    
    
    if (countdown > 0){
        countdown--;
    } else {
        dead = true;
        cout << "dead particle" << endl;
    }
}

void Particle::draw(){
    
    time = ofGetElapsedTimef();
    
    float brightness = ofMap(sin(time*3), -1, 1, 100, ofMap(countdown,0,lifespan,0,255));
    
    ofSetColor(ofColor::fromHsb(hue, 255, brightness));
    
    float rad = ofMap(sin(time*3), -1, 1, radius - 5, radius + 5);
    
    ofCircle(pos, rad);
}