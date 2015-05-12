#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetBackgroundAuto(false);
    
    depth = 1000.0;
    
    flowField.setup(ofGetWidth(), ofGetHeight(), depth, 20.0);
    flowField.setRandom(2.0);

    for (int i=0; i<1000; i++){
        Particle particle;
        particle.setup(1000);
        particles.push_back(particle);
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (!drawField){
        for (int i = 0; i < particles.size(); i++){
            particles[i].resetForces();
            
            ofVec3f force;
            force = flowField.getForceAt(particles[i].pos.x, particles[i].pos.y, particles[i].pos.z);
            particles[i].applyForce(force);
            particles[i].applyDampingForce(0.01);
            particles[i].update();
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    easyCam.begin();
        ofPushMatrix();
        ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    
            ofSetColor(255,0,0);
            
            if (drawField){
                flowField.draw();
            } else {
                ofSetColor(255,200);
                for (int i=0; i<particles.size(); i++){
                    particles[i].draw();
                }
            }
    
            ofSetColor(0,50);
            ofDrawBox(ofGetWidth()/2,ofGetHeight()/2,depth/2,ofGetWidth(),ofGetHeight(),1000);
    
        ofPopMatrix();
    easyCam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch(key){
        case 'f':
            drawField = !drawField;
            break;
        case 'n':
            flowField.setNoise();
            break;
        case 'r':
            flowField.setRandom(20.0);
            break;
    }

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
