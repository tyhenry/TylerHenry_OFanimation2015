//
//  Particle.cpp
//  w10_03_flowField
//
//  Created by Tyler Henry on 3/31/15.
//
//

#include "Particle.h"

void Particle::setup(){
    
    pos.x = ofRandomWidth();
    pos.y = ofRandomHeight();
    
}

void Particle::resetForces(){
    acc *= 0;
    
}

void Particle::applyForce(ofVec2f force){
    acc += force;
    
}

void Particle::applyDampingForce(float damp){
    acc -= vel.getNormalized() * damp;
    
}

void Particle::update(){
    vel += acc;
    pos += vel;
    
    if (pos.x < 0){
        pos.x = 0;
        vel.set(-vel.x, vel.y);
    }
    if (pos.x > ofGetWidth()){
        pos.x = ofGetWidth();
        vel.set(-vel.x, vel.y);
    }
    if (pos.y < 0){
        pos.y = 0;
        vel.set(vel.x, -vel.y);
    }
    if (pos.y > ofGetHeight()){
        pos.x = ofGetHeight();
        vel.set(vel.x, -vel.y);
    }
    
}

void Particle::draw(){
    ofPushStyle();
        ofVec2f hueVec = vel.limit(20); //limit length
        float hue = ofMap(hueVec.length(),0,15, 180,255);
        ofColor c = ofColor::fromHsb(hue,255,255);
        ofSetColor(c);
        ofCircle(pos, 2);
    ofPopStyle();
    
}