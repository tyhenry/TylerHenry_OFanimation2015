#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    /*
    for (int i = 0; i < line.getVertices().size(); i++){
        line.getVertices()[i].x += ofRandom(-1,1);
        line.getVertices()[i].y += ofRandom(-1,1);
    }
    */
    
    int numVerts = line.getVertices().size();
    
    while (numVerts > offsets.size()){
        offsets.push_back(ofVec2f(ofRandom(0,100000),ofRandom(0,100000)));
    }
    
    for (int i=0; i < numVerts; ++i) {
        
        float time = ofGetElapsedTimef();
        float timeScale = 1.0;
        float displacementScale = 1.0;
        ofVec2f timeOffset = offsets[i];
        
        // A typical design pattern for using Perlin noise uses a couple parameters:
        // ofSignedNoise(time*timeScale+timeOffset)*displacementScale
        //     ofSignedNoise(time) gives us noise values that change smoothly over time
        //     ofSignedNoise(time*timeScale) allows us to control the smoothness of our noise (smaller timeScale, smoother values)
        //     ofSignedNoise(time+timeOffset) allows us to use the same Perlin noise function to control multiple things and have them look as if they are moving independently
        //     ofSignedNoise(time)*displacementScale allows us to change the bounds of the noise from [-1, 1] to whatever we want
        // Combine all of those parameters together, and you've got some nice control over your noise
        
        line.getVertices()[i].x += (ofSignedNoise(time*timeScale+offsets[i].x)) * displacementScale;
        line.getVertices()[i].y += (ofSignedNoise(time*timeScale+offsets[i].y)) * displacementScale;
    }
    
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    line.draw();
    

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
    
    // first, make a point
    ofPoint pt;
    pt.set(x,y);
    
    // then add it to the line.
    line.addVertex(pt);
    
    /*stores time offsets for each vertex of line (for perlin noise)
    offsets.push_back(ofVec3f(ofRandom(0,100000), ofRandom(0,100000)));*/

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
     line.clear();
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
