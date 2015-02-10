#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    totalIter = 100;
    currentIter = 0;
    
    circleOne.setup(100.0, 200.0);

}

//--------------------------------------------------------------
void ofApp::update(){

    
    //increment interpolation iteration
    if (currentIter < totalIter){
        currentIter++;
    }
    
    //use easeInOutElastic to update circleOne pct
    circleOne.update(easeOutElastic(currentIter, 0.0, 1.0, totalIter));
}

//--------------------------------------------------------------
void ofApp::draw(){
    circleOne.draw();

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
    
    //get distance
    ofPoint mouse(x, y);
    ofPoint center(ofGetWidth()/2, ofGetHeight()/2);
    
    ofPoint delta = center - mouse;
    radius = sqrt(delta.x * delta.x + delta.y * delta.y);
    
    circleOne.updateRadius(radius);
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

float ofApp::easeOutElastic(float t,float b , float c, float d) {
    if (t==0) return b;  if ((t/=d)==1) return b+c;
    float p=d*.3f;
    float a=c;
    float s=p/4;
    return (a*pow(2,-10*t) * sin( (t*d-s)*(2*PI)/p ) + c + b);
    
}


float ofApp::easeInOutElastic(float t, float b, float c, float d){
    
    if (t==0) return b;  if ((t/=d/2)==2) return b+c;
    float p=d*(.3f*1.5f);
    float a=c;
    float s=p/4;
    
    if (t < 1) {
        float postFix =a*pow(2,10*(t-=1)); // postIncrement is evil
        return -.5f*(postFix* sin( (t*d-s)*(2*PI)/p )) + b;
    }
    float postFix =  a*pow(2,-10*(t-=1)); // postIncrement is evil
    return postFix * sin( (t*d-s)*(2*PI)/p )*.5f + c + b;
}
