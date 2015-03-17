//
//  Cycloid.cpp
//  midterm_particlestest
//
//  Created by Tyler Henry on 3/17/15.
//
//

#include "Cycloid.h"

void Cycloid::setup(ofVec2f _pos, float _radius, float _wheelRadius){
    pos.set(_pos);
    radius = _radius;
    wheelRadius = _wheelRadius;
    
    //construct trace points
    float x, y;
    float angle = 0;
    while (angle < TWO_PI*18){
        
        //epicycloid equation from http://mathworld.wolfram.com/Epicycloid.html
        
        x = ofGetWidth()/2 + (radius + wheelRadius)*cos(angle)-wheelRadius*cos(((radius+wheelRadius)/wheelRadius)*angle);
        y = ofGetHeight()/2 + (radius + wheelRadius)*sin(angle)-wheelRadius*sin(((radius+wheelRadius)/wheelRadius)*angle);
        
        trace.addVertex(ofVec2f(x,y));

        //i increment from http://openframeworks.cc/documentation/graphics/ofPolyline.html
        
        angle+=0.1*HALF_PI*0.5;
    }
    
}

void Cycloid::resetForces(){
    acc *=0;
    //reset forces on trace points
}

void Cycloid::applyForce(ofVec2f force){
    acc += force;
    //apply force on trace points

}

void Cycloid::rotate(float angle){
    
    //rotate each point in the polyline by specified angle
    for (int i=0; i<trace.size(); i++){
        trace[i].rotate(angle, ofVec3f(ofGetWidth()/2, ofGetHeight()/2, 0), ofVec3f(0,0,1));
    }
    
}

void Cycloid::update(){
    vel += acc;
    pos += vel;
    
    //update pos of trace points
    
}

void Cycloid::draw(){
    
    //ofPushMatrix();
    //ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        trace.draw();
    //ofPopMatrix();
    
}





