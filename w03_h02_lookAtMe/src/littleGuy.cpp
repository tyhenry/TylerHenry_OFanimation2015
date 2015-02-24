//
//  littleGuy.cpp
//  w03_h02_lookAtMe
//
//  Created by Tyler Henry on 2/24/15.
//
//

#include "littleGuy.h"

void LittleGuy::setup(){
    oPos.set(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()));
    pos = oPos;
    
    p1.set(ofRandom(-10,10), ofRandom(-20,0));
    p2.set(ofRandom(-10,10), ofRandom(20,0));
    p3.set(ofRandom(10,20), ofRandom(-10,10));
    
    c.r = ofRandom(20,255);
    c.g = ofRandom(20,255);
    c.b = ofRandom(20,255);
    
    newC = c;
}

void LittleGuy::update(float _mX, float _mY){
    
    ofVec2f mousePos;
    mousePos.set(_mX, _mY);
    
    ofVec2f diff;
    diff = mousePos - pos;
    
    //ROTATE
    rot = atan2(diff.y,diff.x); //finds angle between two positions
    rot = ofRadToDeg(rot); //converts radians to degrees
    
    
    //MOVE
    float dist = sqrt(diff.x * diff.x + diff.y * diff.y);
    
    //move away
    if (dist <=100){
     
        //get newPos at 200px distance using rotation
        ofVec2f newPos;
        newPos.set(pos.x+diff.x,pos.y+diff.y);
     
        pos = 0.95*pos + 0.05*newPos;
    }
    //move back
    else if (dist > 100){
        pos = 0.95*pos + 0.05*oPos;
    }
    
    
}

void LittleGuy::draw(){
    
    float x1 = 0;
    float y1 = -10;
    
    float x2 = 0;
    float y2 = 10;
    
    float x3 = 30;
    float y3 = 0;
    
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(pos);
    ofRotate(rot);
    ofSetColor(newC);
        ofTriangle(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
    ofPopMatrix();
    ofPopStyle();
    
    
}