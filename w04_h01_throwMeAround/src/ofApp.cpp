#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(40);
    
    gravity.set(0, 0.5);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    
    for (int i = 0; i < movers.size(); i++) {
        
        movers[i].resetForces();
        movers[i].applyForce(gravity*movers[i].mass);
        movers[i].applyDampingForce(0.05);
        movers[i].update();
        
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i < movers.size(); i++) {
        movers[i].draw();
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
    
    throwStart.set(ofGetMouseX(),ofGetMouseY());

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    throwEnd.set(ofGetMouseX(),ofGetMouseY());
    
    Mover mover;
    mover.setup(ofGetMouseX(), ofGetMouseY(), ofRandom(1.0,5.0));
    mover.vel.set((throwEnd-throwStart)/30);
    movers.push_back(mover);

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
