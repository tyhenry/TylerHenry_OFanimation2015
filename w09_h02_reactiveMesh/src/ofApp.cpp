#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //SOUNDS
    
    ofBackground(0);
    soundStream.listDevices();
    
    int bufferSize = 256;
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    
    smoothedVol     = 0.0;
    scaledVol		= 0.0;
    
    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    
    //SHAPES
    
    ofBackground(0);
    icoSphere.setRadius(200);
    origTriangles = icoSphere.getMesh().getUniqueFaces();
    
    ofSetSmoothLighting(true);
    
    extLight.setPointLight();
    extLight.setDiffuseColor(ofFloatColor(0,0.2,0.5));
    extLight.setPosition(ofGetWidth()/2,ofGetHeight()/2,500);


}
//--------------------------------------------------------------

void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    float curVol = 0.0;
    
    // samples are "interleaved"
    int numCounted = 0;
    
    //lets go through each sample and calculate the root mean square which is a rough way to calculate volume
    for (int i = 0; i < bufferSize; i++){
        left[i]		= input[i*2]*0.5;
        right[i]	= input[i*2+1]*0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted+=2;
    }
    
    //this is how we get the mean of rms :)
    curVol /= (float)numCounted;
    
    // this is how we get the root of rms :)
    curVol = sqrt( curVol );
    
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //SOUNDS
    
    //lets scale the vol up to a 0-1 range
    scaledVol = ofMap(smoothedVol, 0.0, 0.05, 0.0, 1000.0, true);
    
    //SHAPES
    
    //offset = ofMap(scaledVol,-1,1,0,300);
    
    triangles = icoSphere.getMesh().getUniqueFaces();
    ofVec3f faceNormal;
    
    for (int i=0; i<triangles.size(); i++){
        faceNormal = triangles[i].getFaceNormal();
        
        for (int j=0; j<3; j++){
            triangles[i].setVertex(j, origTriangles[i].getVertex(j)-faceNormal*scaledVol);
        }
    }
    
    icoSphere.getMesh().setFromTriangles(triangles);
    
    float hue = ofMap(scaledVol, 0, 500.0, 170, 255);
    cout << hue << endl;
    extLight.setDiffuseColor(ofColor::fromHsb(hue,255,255));

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetDepthTest(true);
    
    ofEnableLighting();
    extLight.enable();
    
    cam.begin();
    icoSphere.draw();
    cam.end();
    
    ofDisableLighting();
    
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
