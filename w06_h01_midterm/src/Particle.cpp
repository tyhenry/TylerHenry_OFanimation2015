//
//  Particle.cpp
//  midterm_particlestest
//
//  Created by Tyler Henry on 3/17/15.
//
//

#include "Particle.h"

Particle::Particle(ofVec2f _pos, float _vel, float _radius, float _hue){
    
    pos.set(_pos);
    radius = _radius;
    hue = _hue;
    
    //set random triangle points
    p1.set(ofRandom(-1*radius,radius), ofRandom(-2*radius,0));
    p2.set(ofRandom(-1*radius,radius), ofRandom(2*radius,0));
    p3.set(ofRandom(radius,2*radius), ofRandom(-1*radius,radius));
    
    /*set initial velocity based on vel
    vel.x = ofRandom(-1*_vel, _vel);
    vel.y = ofRandom(-1*_vel, _vel);
     
    lifespan = 90; //3 seconds @ 60fps
    countdown = lifespan;
    
    dead = false;
    */
    
    timeOffset = ofRandom(10);

}

void Particle::resetForces(){
    acc *= 0;
}

void Particle::applyForce(ofVec2f force){
    acc += force;
}

void Particle::applyDampingForce(float damping){
    acc -= vel.getNormalized() * damping;
}

void Particle::update(ofVec2f handOnePos, ofVec2f handTwoPos, ofVec2f oPos){
    vel += acc;
    pos += vel;
    
    /*if (countdown > 0){
        countdown--;
    } else {
        dead = true;
        //cout << "dead particle" << endl;
    }*/
    
    ofVec2f diffOne;
    diffOne = handOnePos - pos;
    
    ofVec2f diffTwo;
    diffTwo = handTwoPos - pos;
    
    if (diffOne.length() >= diffTwo.length()){
        //ROTATE BASED ON handOne
        rot = atan2(diffOne.y,diffOne.x); //finds angle between two points
        rot = ofRadToDeg(rot); //converts radians to degrees
    } else {
        //ROTATE BASED ON handTwo
        rot = atan2(diffTwo.y,diffTwo.x); //finds angle between two points
        rot = ofRadToDeg(rot); //converts radians to degrees
    }
    
    /*MOVE
    float dist = sqrt(diff.x * diff.x + diff.y * diff.y);
    
    //move away
    if (dist <=100){
        
        ofVec2f newPos;
        newPos.set(pos.x+diff.x,pos.y+diff.y);
        
        pos = 0.90*pos + 0.1*newPos;
    }
    */
    
    //move back
    //if ((diffOne.length() > 150) && (diffTwo.length() > 150)){
        pos = 0.98*pos + 0.02*oPos;
    //}
    
}

void Particle::draw(){
    //float alpha = ofMap(countdown,0,lifespan,0,255);
    
    //ofSetColor(ofColor::fromHsb(hue, 0, brightness));
    
    ofSetColor(255); //white
    
    float posChange = sin(ofGetElapsedTimef()+timeOffset)*3;
    
    ofPushMatrix();
    ofTranslate(pos.x+posChange, pos.y+posChange);
    ofRotate(rot);
    ofTriangle(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
    ofPopMatrix();

}