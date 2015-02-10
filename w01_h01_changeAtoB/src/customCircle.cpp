//
//  customCircle.cpp
//  01_simpleCircle
//
//  Created by Tyler Henry on 2/3/15.
//
//

#include "customCircle.h"

customCircle::customCircle(){
    
}

void customCircle::setup(ofVec2f _initPos, ofVec2f _finalPos){
    initPos = _initPos;
    finalPos = _finalPos;
}

void customCircle::updateInit(ofVec2f _initPos){
    initPos = _initPos;
}

void customCircle::updateFinal(ofVec2f _finalPos){
    finalPos = _finalPos;
}

void customCircle::update(float _pct){
    pct = _pct;
    currentPos = initPos*(1-pct) + finalPos*pct;
}

void customCircle::updateX(float _pct){
    pct = _pct;
    currentPos.x = initPos.x*(1-pct) + finalPos.x*pct;
}

void customCircle::updateY(float _pct){
    pct = _pct;
    currentPos.y = initPos.y*(1-pct) + finalPos.y*pct;
}

void customCircle::linear(float _pct){
    pct = _pct;
    currentPos = initPos*(1-pct) + finalPos*pct;
    //moves from initPos --> finalPos
    //(initPos*1 + finalPos*0) --> (initPos*0 + finalPos*1)
}

void customCircle::easeIn(float _pct){
    pct = powf(_pct, 2); // == _pct * _pct
    currentPos = initPos*(1-pct) + finalPos*pct;
}

void customCircle::easeOut(float _pct){
    pct = _pct*(2-_pct);
    currentPos = initPos*(1-pct) + finalPos*pct;
}

float customCircle::easeInElastic(float t, float b, float c, float d){
    
    if (t==0) return b;  if ((t/=d)==1) return b+c;
    float p=d*.3f;
    float a=c;
    float s=p/4;
    float postFix =a*pow(2,10*(t-=1)); // this is a fix, again, with post-increment operators
    return -(postFix * sin((t*d-s)*(2*PI)/p )) + b;
}

float customCircle::easeOutElastic(float t, float b, float c, float d){
    
    if (t==0) return b;  if ((t/=d)==1) return b+c;
    float p=d*.3f;
    float a=c;
    float s=p/4;
    return (a*pow(2,-10*t) * sin( (t*d-s)*(2*PI)/p ) + c + b);
}

float customCircle::easeInOutElastic(float t, float b, float c, float d){
    
    if (t==0) return b;  if ((t/=d/2)==2) return b+c;
    float p=d*(.3f*1.5f);
    float a=c;
    float s=p/4;
    
    if (t < 1) {
        float postFix =a*pow(2,10*(t-=1)); // postIncrement is evil
        return -.5f*(postFix* sin( (t*d-s)*(2*PI)/p )) + b;
    }
    float postFix =  a*pow(2,-10*(t-=1)); // postIncrement is evil
    return postFix * sin( (t*d-s)*(2*PI)/p )*.5f + c + b;
}

void customCircle::draw() {
    ofLine(initPos, finalPos);
    ofCircle(currentPos, 30);
}

void customCircle::setNewPosition(ofVec2f _newPos){
    initPos = currentPos;
    finalPos = _newPos;
}