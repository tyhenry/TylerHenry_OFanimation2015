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
    
    void setup(float _initRadius, float _finalRadius);
    void update(float _pct);
    void draw();
    
    void updateRadius(float _radius);
    void flipRes();
    float easeOutElastic(float t, float b, float c, float d);
    float easeInOutElastic(float t, float b, float c, float d);
    
    float brightness;
    
    
private:
    
    ofVec2f pos;
    float pct;
    float radius, initRadius, finalRadius;
    float res, initRes, finalRes;
};
