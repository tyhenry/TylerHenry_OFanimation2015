//
//  customCircle.cpp
//  02_xeno
//
//  Created by Tyler Henry on 2/3/15.
//
//

#include "customCircle.h"

void customCircle::setup(){
    pos.set(100,100);
    c = ofColor(ofRandom(50, 255), ofRandom(50, 255), ofRandom(50, 255));
    rate = ofRandom(0.01,0.2);
    radius = ofMap(rate, 0.01, 0.2, 30, 10);
}

void customCircle::update(ofVec2f _finalPos){
    pos = pos * (1-rate) + _finalPos * rate; //xeno's paradox interpolation
}

void customCircle::draw(){
    ofSetColor(c);
    ofCircle(pos, radius);
}