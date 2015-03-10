#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);

    gravity.set(0.0, 0.0);
    
}

//--------------------------------------------------------------
void ofApp::update(){

    
    //erase dead explosions from vector
    for (int h=0; h<systems.size(); h++){
        if (systems[h].dead){
            systems.erase(systems.begin()+h);
            h=0;
            cout << "erased system" << endl;
        }
    }
    
    for (int i=0; i<systems.size(); i++){
        systems[i].resetForces();
        systems[i].applyForce(gravity);
        systems[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i=0; i<systems.size(); i++){
        systems[i].draw();
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
    
    ParticleSystem system(ofVec2f(mouseX, mouseY), ofRandom(50,100), ofRandom(255));
    systems.push_back(system);

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
