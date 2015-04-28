//
//  FlowField.cpp
//  w10_03_flowField
//
//  Created by Tyler Henry on 3/31/15.
//
//

#include "FlowField.h"

FlowField::FlowField() {
    
}

void FlowField::setup(float w, float h, float res){
    width = w;
    height = h;
    resolution = res;

    internalWidth = ceil(width/resolution); //ceil rounds float up
    internalHeight = ceil(height/resolution);
    
    fieldSize = internalWidth * internalHeight;
    
    for (int i = 0; i < fieldSize; i++){
        ofVec2f flow;
        flow.set(0.0, 0.0); //set flow to 0 for starters
        field.push_back(flow);
    }
}

void FlowField::followMouse(float mX, float mY){
    
    ofVec2f mousePos;
    mousePos.set(mX, mY);
    
    for (int y = 0; y < internalHeight; y++){
        for (int x = 0; x < internalWidth; x++){
            int index = (y * internalWidth) + x;
            
            //get index's position
            ofVec2f indexPos;
            float pX = x * resolution;
            float pY = y * resolution;
            indexPos.set(pX,pY);
            //get difference between index pos and mouse pos
            ofVec2f diff = mousePos - indexPos;
            
            if (diff.length() < 100){  //ROTATE
                
                float rot = atan2(diff.y,diff.x); //finds angle between two positions
                ofVec2f mouseFlow;
                mouseFlow.set(ofVec2f(cos(rot)*2.0, sin(rot)*2.0));
                
                /*weighted average original flow with mouse flow
                float avgX = (mouseFlow.x + 9 * field[index].x)/10;
                float avgY = (mouseFlow.y + 9 * field[index].y)/10;
                
                field[index].set(avgX, avgY);*/
                
                //add flows
                field[index].set(mouseFlow.x/3 + field[index].x, mouseFlow.y/3 + field[index].y);
            }
            
        }
    }
}

void FlowField::setRandom(float scale){
    
    for (int i = 0; i < fieldSize; i++){
        float x = ofRandom(-1,1) * scale;
        float y = ofRandom(-1,1) * scale;
        field[i].set(x,y);
    }

}

void FlowField::setNoise(){
    
    for (int y = 0; y < internalHeight; y++){
        for (int x = 0; x < internalWidth; x++){
            int index = (y * internalWidth) + x;
            float noise = ofNoise(x*0.05, y*0.05);
            //define an angle based on noise
            noise = ofMap(noise, 0, 1, 0, TWO_PI);
            
            field[index].set(ofVec2f(cos(noise)*2.0, sin(noise)*2.0));
            
        }
    }
}

ofVec2f FlowField::getForceAt(float x, float y){
    ofVec2f force;
    force.set(0.0, 0.0);
    
    float xPct = x/width; //determine pct of point within FlowField
    float yPct = y/height;
    
    if (xPct < 0 || xPct > 1 || yPct < 0 || yPct > 1){
        return force;
    }
    
    int internalPosX = xPct * internalWidth; //calc position in array
    int internalPosY = yPct * internalHeight; //percentage within internal dims
    
    int pos = internalPosY * internalWidth + internalPosX;
    
    force.set(field[pos].x*0.01, field[pos].y*0.01);
    
    return force;
    
}

void FlowField::draw(){
    for (int y = 0; y < internalHeight; y++){
        for (int x = 0; x < internalWidth; x++){
            
            int index = (y * internalWidth) + x; //2d field -> 1d array
            
            float px = x * resolution;
            float py = y * resolution;
            float px2 = px + (field[index].x * 5);
            float py2 = py + (field[index].y * 5);
            
            ofLine (px, py, px2, py2);
            ofCircle(px, py, 2);
        }
    }
}