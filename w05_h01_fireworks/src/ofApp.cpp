#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(60);
    
    gravity.set(0,0.06);
    
    mouseDown = false;
    mouseCount = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (mouseDown) mouseCount++;
    
    /*ROCKETS*/
    
    //check rockets for explosions
    for (int h=0; h<rockets.size(); h++){
        if (rockets[h].explode){
            
            //add an explosion
            Explosion explosion(rockets[h].pos,rockets[h].size, rockets[h].hue);
            explosions.push_back(explosion);
            
            //erase the rocket
            rockets.erase(rockets.begin()+h);
            h=0;
            cout << "exploded a rocket" << endl;
        }
    }
    
    //update live rockets
    for (int i=0; i<rockets.size(); i++){
        rockets[i].resetForces();
        rockets[i].applyForce(gravity);
        rockets[i].update();
    }
    
    
    
    /*EXPLOSIONS*/
    
    //erase dead explosions from vector
    for (int h=0; h<explosions.size(); h++){
        if (explosions[h].dead){
            explosions.erase(explosions.begin()+h);
            h=0;
            cout << "erased explosion" << endl;
        }
    }
    
    //update live explosions
    for (int i=0; i<explosions.size(); i++){
        explosions[i].resetForces();
        explosions[i].applyForce(gravity);
        explosions[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //draw rockets
    for (int i=0; i<rockets.size(); i++){
        rockets[i].draw();
    }
    
    //draw explosions
    for (int i=0; i<explosions.size(); i++){
        explosions[i].draw();
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
    mouseDown = true;
    
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    cout << "mouseCount: " << mouseCount << endl;
    
    float mX = mouseX;
    if (mX < ofGetWidth()/3) mX = ofGetWidth()/3;
    else if (mX > 2*(ofGetWidth()/3)) mX = 2*(ofGetWidth()/3);

    
    //initial velocity of firework
    ofVec2f diff = (ofVec2f(mX,mouseY)-ofVec2f(ofGetWidth()/2,ofGetHeight()));
    float dist = diff.length();
    ofVec2f vel = diff.getNormalized() * (dist/70);
    
    if (mouseCount > 60) mouseCount = 60;

    Rocket rocket(vel, ofMap(mouseCount, 0, 60, 50, 100), ofRandom(255));
    rockets.push_back(rocket);
    
    cout << "launched rocket" << endl;
                             
    mouseCount = 0;
    mouseDown = false;
    

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
