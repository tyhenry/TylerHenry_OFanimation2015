#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    //pct = 0.0;
    
    totalIter = 100;
    currentIter = 0;
    
    circleOne.setup(ofVec2f(0, 500), ofVec2f(800, 50));
    //circleTwo.setup(ofVec2f(0, 500), ofVec2f(800, 50));
    //circleThree.setup(ofVec2f(0, 500), ofVec2f(800, 50));
    
    ofNoFill();
    
    circleA = true;

}

//--------------------------------------------------------------
void ofApp::update(){

    if (currentIter < totalIter){
        currentIter++;
    }
    
    //pct = circleOne.easeInOutElastic(currentIter, 0.0, 1.0, totalIter);
    circleOne.updateX(circleOne.easeInOutElastic(currentIter, 0.0, 1.0, totalIter));
    circleOne.updateY(circleOne.easeInOutElastic(currentIter, 0.0, 1.0, totalIter));
    
    /*
     if (pct < 0.99){
     pct += 0.01;
     }
     */
    
    //circleOne.linear(pct);
    //circleTwo.easeIn(pct);
    //circleThree.easeOut(pct);
}

//--------------------------------------------------------------
void ofApp::draw(){
    circleOne.draw();
    //circleTwo.draw();
    //circleThree.draw();
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
    //change final position to mouse
    
    //circleOne.setNewPosition(ofVec2f(x, y));
    
    //circleTwo.setNewPosition(ofVec2f(x, y));
    //circleThree.setNewPosition(ofVec2f(x, y));
    //pct = 0.0; //reset percentage
    
    if (circleA){
        circleOne.updateInit(ofVec2f(x, y));
    } else {
        circleOne.updateFinal(ofVec2f(x, y));
    }
    circleA = !circleA;
    
    currentIter = 0;
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
