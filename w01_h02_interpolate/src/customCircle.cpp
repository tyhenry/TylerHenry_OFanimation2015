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

void customCircle::setup(float _initRadius, float _finalRadius){
    pos = ofVec2f(ofGetWidth()/2,ofGetHeight()/2);
    initRadius = _initRadius;
    finalRadius = _finalRadius;
    initRes = 20.0;
    finalRes = 150.0;
    
    brightness = 255;
}


void customCircle::update(float _pct){
    pct = _pct;
    
    //update radius percentage
    radius = initRadius*(1-pct) + finalRadius*pct;
    res = initRes*(1-pct) + finalRes*pct;
    brightness = ofMap(radius, 0, ofGetWidth()/2, 20.0, 255.0);
    
    //limit resolution
    if (res < 10.0){
        res = 10.0;
    } else if (res > 200.0){
        res = 200.0;
    }
    
}

void customCircle::draw(){
    ofSetCircleResolution(int(res));
    ofSetColor(int(brightness));
    ofFill();
    ofCircle(pos, radius);
}

void customCircle::updateRadius(float _radius){
    initRadius = radius;
    finalRadius = _radius;
}

void customCircle::flipRes(){
    float tempRes = finalRes;
    finalRes = initRes;
    initRes = tempRes;
}

float customCircle::easeOutElastic(float t,float b , float c, float d) {
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