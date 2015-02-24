#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    for (int i=0; i<200; i++){
        LittleGuy _guy;
        _guy.setup();
        littleGuys.push_back(_guy);
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i=0; i<littleGuys.size(); i++){
        littleGuys[i].update(ofGetMouseX(),ofGetMouseY());
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i=0; i<littleGuys.size(); i++){
        littleGuys[i].draw();
    }

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
