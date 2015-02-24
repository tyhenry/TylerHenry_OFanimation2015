//
//  worm.cpp
//  w02_h03_gaussianPopulation
//
//  Created by Tyler Henry on 2/15/15.
//
//

#include "worm.h"



void worm::setup(float _colorDev, float _lengthDev, ofVec2f _posDev){
    
    //color
    float hue = 10 * _colorDev + 10.0; //2 == standard dev
    if (hue < 0) hue = 0;
    color = ofColor::fromHsb(hue,130.0,247.0);
    
    //length
    length = 10 * _lengthDev + 40.0; //10 == standard dev
    
    //position
    pos.x = 120 * _posDev.x + ofGetWidth()/2;
    pos.y = 120 * _posDev.y + ofGetHeight()/2;
    
    //angle
    angle = ofRandom(360);
    
    //noiseOffset
    noiseOffset = ofRandom(10000);
    
}

void worm::update(){
    
    int randPos = ofRandom(4);
    
    if (randPos == 0) pos.x++;
    if (randPos == 1) pos.x--;
    if (randPos == 2) pos.y++;
    if (randPos == 3) pos.y--;
    
    pos.x += ofSignedNoise(ofGetElapsedTimef() + noiseOffset);
    pos.y += ofSignedNoise(ofGetElapsedTimef() + noiseOffset*2);
    
    
    int randAng = ofRandom(3);
    
    if (randPos < 2){
        if (noiseOffset > 5000){
            angle++;
        } else {
            angle--;
        }
    }
    
}

void worm::draw(){
    
    float noise1 = ofSignedNoise(ofGetElapsedTimef()*3.0 + noiseOffset)*10.0;
    float noise2 = ofSignedNoise(ofGetElapsedTimef()*5.0 + noiseOffset)*10.0;
    float noise3 = ofSignedNoise(ofGetElapsedTimef()*8.0 + noiseOffset)*10.0;
    
    ofColor color2 = color;
    ofColor color3 = color;
    color2.setBrightness(color.getBrightness()-20);
    color3.setBrightness(color.getBrightness()-40);
    
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotateZ(angle);

        ofSetColor(color3);
        ofEllipse(noise3, 0 + length*1.1, length*0.4, length*0.8);
    
        ofSetColor(color2);
        ofEllipse(noise2, 0 + length*0.6, length*0.45, length*0.9);
    
        ofSetColor(color);
        ofEllipse(noise1, 0, length*0.6, length);

    ofPopMatrix();
    
}