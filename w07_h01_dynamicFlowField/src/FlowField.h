//
//  FlowField.h
//  w10_03_flowField
//
//  Created by Tyler Henry on 3/31/15.
//
//

#pragma once
#include "ofMain.h"

class FlowField{
public:
    
    FlowField();
    
    void setup(float w, float h, float res); //width, height, resolution
    void followMouse(float mX, float mY);
    void setRandom(float scale);
    void setNoise();
    ofVec2f getForceAt(float x, float y);
    
    void draw();
    
    vector<ofVec2f> field;
    
    int width; //screen real-estate
    int height;
    int depth;
    
    int internalWidth; //number of flow points
    int internalHeight;
    
    float resolution;
    int fieldSize;
    
};
