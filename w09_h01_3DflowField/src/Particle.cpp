//
//  Particle.cpp
//  w10_03_flowField
//
//  Created by Tyler Henry on 3/31/15.
//
//

#include "Particle.h"

void Particle::setup(float depth){
    
    pos.x = ofRandomWidth();
    pos.y = ofRandomHeight();
    pos.z = ofRandom(0,depth);
    
}

void Particle::resetForces(){
    acc *= 0;
    
}

void Particle::applyForce(ofVec3f force){
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
        vel.set(-vel.x, vel.y, vel.z);
    }
    if (pos.x > ofGetWidth()){
        pos.x = ofGetWidth();
        vel.set(-vel.x, vel.y, vel.z);
    }
    if (pos.y < 0){
        pos.y = 0;
        vel.set(vel.x, -vel.y, vel.z);
    }
    if (pos.y > ofGetHeight()){
        pos.x = ofGetHeight();
        vel.set(vel.x, -vel.y, vel.z);
    }
    if (pos.z < 0){
        pos.z = 0;
        vel.set(vel.x, vel.y, -vel.z);
    }
    if (pos.z > 500){
        pos.z = 500;
        vel.set(vel.x, vel.y, -vel.z);
    }
    
}

void Particle::draw(){
    ofPushStyle();
        ofVec3f hueVec = vel.limit(20); //limit length of velocity
        float hue = ofMap(hueVec.length(),0,15, 180,255);
        ofColor c = ofColor::fromHsb(hue,255,255);
        ofSetColor(c);
        ofDrawSphere(pos, 2);
    ofPopStyle();
    
}