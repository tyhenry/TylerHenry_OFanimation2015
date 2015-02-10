#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    circleOne.setup();
    circleTwo.setup();
    circleThree.setup();

}

//--------------------------------------------------------------
void ofApp::update(){
    circleOne.update(ofVec2f(ofGetMouseX(),ofGetMouseY()));
    circleTwo.update(ofVec2f(ofGetMouseX(),ofGetMouseY()));
    circleThree.update(ofVec2f(ofGetMouseX(),ofGetMouseY()));

}

//--------------------------------------------------------------
void ofApp::draw(){
    circleOne.draw();
    circleTwo.draw();
    circleThree.draw();

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
