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

void FlowField::setup(float w, float h, float d, float res){
    width = w;
    height = h;
    depth = d;
    resolution = res;

    internalWidth = ceil(width/resolution);
    //ceil rounds float up
    internalHeight = ceil(height/resolution);
    internalDepth = ceil(depth/resolution);
    
    cout << "internal width: " << internalWidth << ", height: " << internalHeight << ", depth: " << internalDepth;
    
    fieldArea = internalWidth * internalHeight * internalDepth;
    
    for (int i = 0; i < fieldArea; i++){
        ofVec3f flow;
        flow.set(0.0, 0.0, 0.0);
        //set flow to 0 for starters
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
            
            if (diff.length() < 100){
                //ROTATE towards mouse
                
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
    
    for (int i = 0; i < fieldArea; i++){
        float x = ofRandom(-1,1) * scale;
        float y = ofRandom(-1,1) * scale;
        float z = ofRandom(-1,1) * scale;
        field[i].set(x,y,z);
    }

}

/*
void FlowField::setNoise(){
 
    
    for (int z = 0; z < internalDepth; z++){
        for (int y = 0; y < internalHeight; y++){
            for (int x = 0; x < internalWidth; x++){
 
                int index = x + internalWidth * (y + internalHeight * z);
 
                float noise = ofNoise(x*0.05, y*0.05, z*0.05);
                //define an angle based on noise
                noise = ofMap(noise, 0, 1, 0, TWO_PI);
                
                field[index].set(ofVec3f(cos(noise)*2.0, sin(noise)*2.0),);

                
                diff = pointAt - pos;
                ofVec3f norm = diff.normalize();
                
                float noise = ofNoise(x*0.05, y*0.05, z*0.05);
                
                rotX = atan2(norm.y, sqrt(1 - norm.y * norm.y));
                rotY = atan2(diff.x, diff.z);
                
                rotX = ofRadToDeg(rotX);
                rotY = ofRadToDeg(rotY);
                
                index++;
            }
        }
    }
}
 */

ofVec3f FlowField::getForceAt(float x, float y, float z){
    
    ofVec3f force;
    force.set(0.0, 0.0, 0.0);
    
    float xPct = x/width; //determine pct of point within FlowField
    float yPct = y/height;
    float zPct = z/depth;
    
    if (xPct < 0 || xPct > 1 || yPct < 0 || yPct > 1 || zPct < 0 || zPct > 1){
        return force;
        //return blank force
    }
    
    int internalPosX = xPct * internalWidth; //calc position in array
    int internalPosY = yPct * internalHeight; //percentage within internal dims
    int internalPosZ = zPct * internalDepth;
    
    int index = internalPosX + internalWidth * (internalPosY + internalHeight * internalPosZ);
    
    force.set(field[index].x*0.1, field[index].y*0.1, field[index].z*0.1);
    
    return force;

    
}

void FlowField::draw(){
    
    for (int z = 0; z < internalDepth; z++){
        for (int y = 0; y < internalHeight; y++){
            for (int x = 0; x < internalWidth; x++){
                
                //3d field -> 1d array
                int index = x + internalWidth * (y + internalHeight * z);
                
                float px = x * resolution;
                float py = y * resolution;
                float pz = z * resolution;
                float px2 = px + (field[index].x * 5); //exaggerate magnitude
                float py2 = py + (field[index].y * 5);
                float pz2 = pz + (field[index].z * 5);
                
                //cout << "point x: " << x << ", y: " << y << ", z: " << z << endl;
                //cout << "force x: " << px2 << ", y: " << py2 << ", z: " << pz2 << endl;
                
                cout << "force x: " << field[index].x << ", y: " << field[index].y << ", z: " << field[index].z << endl;
                
                //ofCircle(px, py, pz, 2); //origin dot
                //ofLine (px, py, pz, px2, py2, pz2); //vector line
            }
        }
    }
}