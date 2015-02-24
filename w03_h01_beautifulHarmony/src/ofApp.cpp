#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    //ofNoFill();
    
    ofSetCircleResolution(60);
    
    circCenter = ofVec3f(ofGetWidth()/2,ofGetHeight()/2,0);
    sqCenter = ofVec3f(ofGetWidth()/2,ofGetHeight()/2,0);
    triCenter = ofVec3f(ofGetWidth()/2,ofGetHeight()/2,0);
    
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    time = ofGetElapsedTimef();
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    i=2.4;
    
    //draw square
    ofPushMatrix();
    ofTranslate(sqCenter.x,sqCenter.y,sqCenter.z);
        sqDeg = sin(time*i);
        ofRotateX(sqDeg*360);
        ofRotateY(sqDeg*360);
        
        ofSetColor(0,255,0,122);
        ofRect(-200,-200,400,400);
    ofPopMatrix();
    
    i/=2;
    
    //draw circle
    ofPushMatrix();
    ofTranslate(circCenter.x,circCenter.y,circCenter.z);
        circDeg = sin(time*i);
        ofRotateX(circDeg*360);
        ofRotateY(circDeg*360);
    
        ofSetColor(255,0,0,122);
        ofCircle(0,0,200);

    ofPopMatrix();
    
    i/=2;
    
    //draw triangle
    ofPushMatrix();
    ofTranslate(triCenter.x,triCenter.y,triCenter.z);
        triDeg = sin(time*i);
        ofRotateX(triDeg*360);
        ofRotateY(triDeg*360);
    
        ofSetColor(0,0,255,122);
        ofTriangle(0,-200,-200,200,200,200);
    ofPopMatrix();
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
