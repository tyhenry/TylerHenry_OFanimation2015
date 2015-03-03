//
//  Mover.cpp
//  w04_h01_throwMeAround
//
//  Created by Tyler Henry on 3/3/15.
//
//

#include "Mover.h"

void Mover::setup(float x, float y, float _mass) {
    pos.set(x, y);
    mass = _mass;
    hue = ofRandom(255);

}

void Mover::resetForces(){
    acc *= 0;
}

void Mover::applyForce(ofVec2f force){
    //force = mass * acc
    acc += force/mass; //+= because multiple accelerations
}

void Mover::applyDampingForce(float damping) {
    acc -= vel.getNormalized() * damping;
    //why getNormalized again?
}

void Mover::update() {
    vel += acc;
    pos += vel;
    
    if (pos.x < 0) {
        pos.x = 0;
        vel.x *= -1;
    }
    
    if (pos.x > ofGetWidth()) {
        pos.x = ofGetWidth();
        vel.x *= -1;
    }
    
    if (pos.y < 0) {
        pos.y = 0;
        vel.y *= -1;
    }
    
    if (pos.y > ofGetHeight()) {
        pos.y = ofGetHeight();
        vel.y *= -1;
    }
}

void Mover::draw() {
    //set color of vertex based on y
    float sat = ofMap(vel.x+vel.y, 0, 10, 155, 255);
    ofSetColor(ofColor::fromHsb(hue,sat,255));
    ofCircle(pos, 10 * mass);
}
