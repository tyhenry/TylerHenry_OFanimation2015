//
//  customCircle.h
//  01_simpleCircle
//
//  Created by Tyler Henry on 2/3/15.
//
//

#pragma once
#include "ofMain.h"

class customCircle {
public:
    customCircle();
    void setup(ofVec2f _initPos, ofVec2f _finalPos);
    
    void update(float _pct);
    void updateX(float _pct);
    void updateY(float _pct);
    
    //simple ease functions
    void linear(float _pct);
    void easeIn(float _pct);
    void easeOut(float _pct);
    
    //penner ease functions
    float easeInElastic(float t, float b, float c, float d);
    float easeOutElastic(float t, float b, float c, float d);
    float easeInOutElastic(float t, float b, float c, float d);
    
    void draw();
    void setNewPosition(ofVec2f _newPos);
    
    void updateInit(ofVec2f _initPos);
    void updateFinal(ofVec2f _initPos);
    
private:
    ofVec2f initPos, finalPos, currentPos;
    float pct;
};
