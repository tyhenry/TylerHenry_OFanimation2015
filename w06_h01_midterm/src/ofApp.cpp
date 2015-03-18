#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //ofSetBackgroundAuto(false);
    ofBackground(0);
    
    ofHideCursor();

    
    /*-- KINECT + OPENCV --*/
    
    // enable depth->video image calibration
    kinect.setRegistration(true);
    
    kinect.init();
    //kinect.init(true); // shows infrared instead of RGB video image
    //kinect.init(false, false); // disable video image (faster fps)
    
    kinect.open(0);		// opens first available kinect
    //kinect.open(1);	// open a kinect by id, starting with 0 (sorted by serial # lexicographically))
    //kinect.open("A00362A08602047A");	// open a kinect using it's unique serial #
    
    colorImg.allocate(kinect.width, kinect.height);
    grayImage.allocate(kinect.width, kinect.height);
    grayBg.allocate(kinect.width, kinect.height);
    grayDiff.allocate(kinect.width, kinect.height);
    grayThreshNear.allocate(kinect.width, kinect.height);
    grayThreshFar.allocate(kinect.width, kinect.height);
    
    nearThreshold = 255;
    farThreshold = 248;
    
    ofSetFrameRate(60);
    
    // zero the tilt on startup
    angle = 0;
    kinect.setCameraTiltAngle(angle);
    
    bLearnBackground = false;
    drawCv = false;
    drawGray = false;
    
    cout << kinect.width;
    cout << kinect.height;
    
    /*--PROJECTION MASK--*/
    
    //mask.loadImage("projectionmask.png");
    
    //CYCLOID PARTICLES
    
    center.set(ofGetWidth()/2, ofGetHeight()/2);
    
    //cycloid radii are backwards to make spiral
    cycloid.setup(ofVec2f(ofGetWidth()/2, ofGetHeight()/2), 5.0, 170.0);
    
    //initialize bloom vector
    for (int i=0; i<cycloid.trace.size(); i++){
        ofVec2f bloomPos;
        bloomPos.set(cycloid.trace[i].x,cycloid.trace[i].y);
        Bloom bloom(bloomPos, 10.0, 255);
        blooms.push_back(bloom);
    }

    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    /*-- KINECT + OPENCV --*/
    kinect.update();
    
    // there is a new frame and we are connected
    if(kinect.isFrameNew()) {
        
        // load grayscale depth image from the kinect source
        grayImage.setFromPixels(kinect.getDepthPixels(), kinect.width, kinect.height);
        
        if (bLearnBackground == true) {
            grayBg = grayImage; // update the background image
            bLearnBackground = false;
        }
        
        //extract the background
        grayDiff.absDiff(grayBg, grayImage);
        
        //get thresholds
        grayThreshNear = grayImage;
        grayThreshFar = grayImage;
        grayThreshNear.threshold(nearThreshold, true);
        grayThreshFar.threshold(farThreshold);
        cvAnd(grayThreshNear.getCvImage(), grayThreshFar.getCvImage(), grayDiff.getCvImage(), NULL);
        
        // update the cv images
        grayImage.flagImageChanged();
        grayDiff.flagImageChanged();
        
        
        // find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
        // also, find holes is set to true so we will get interior contours as well....
        contourFinder.findContours(grayDiff, 10, (kinect.width*kinect.height)/2, 2, false);
        
    }
    
    /*-- GET BLOB CENTROIDS --*/
    
    ofxCvBlob blobOne;
    ofxCvBlob blobTwo;
    
    //converts kinect dims to screen dims
    // ofVec2f vidScalar = ofVec2f(ofGetWidth()/kinect.width, ofGetHeight()/kinect.height);
    
    //if only one hand is showing
    if (contourFinder.nBlobs == 1){
        blobOne = contourFinder.blobs.at(0);
        
        //give both hands the same coordinates
        handPosRight = ofVec2f(ofMap(blobOne.centroid.x,0,kinect.width,0,ofGetWidth()),ofMap(blobOne.centroid.y,0,kinect.height,0,ofGetHeight()));
        handPosLeft = ofVec2f(ofMap(blobOne.centroid.x,0,kinect.width,0,ofGetWidth()),ofMap(blobOne.centroid.y,0,kinect.height,0,ofGetHeight()));
        
    }
    //if two hands are showing
    else if (contourFinder.nBlobs == 2){
        
        //determine right and left
        blobOne = contourFinder.blobs.at(0);
        blobTwo = contourFinder.blobs.at(1);
        
        //if blobOne is further right, call it the left hand
        if (blobOne.centroid.x >= blobTwo.centroid.x){
            
            handPosLeft = ofVec2f(ofMap(blobOne.centroid.x,0,kinect.width,0,ofGetWidth()),ofMap(blobOne.centroid.y,0,kinect.height,0,ofGetHeight()));
            handPosRight = ofVec2f(ofMap(blobTwo.centroid.x,0,kinect.width,0,ofGetWidth()),ofMap(blobTwo.centroid.y,0,kinect.height,0,ofGetHeight()));
        }
        //if bloblTwo is further right, call it the left hand
        else {
            handPosRight = ofVec2f(ofMap(blobOne.centroid.x,0,kinect.width,0,ofGetWidth()),ofMap(blobOne.centroid.y,0,kinect.height,0,ofGetHeight()));
            handPosLeft = ofVec2f(ofMap(blobTwo.centroid.x,0,kinect.width,0,ofGetWidth()),ofMap(blobTwo.centroid.y,0,kinect.height,0,ofGetHeight()));
        }
        
    }
    

    
    //ROTATE CYCLOID - by 0.5 degrees
    cycloid.rotate(0.5);
    
    //BLOOMS
    
    /*add new bloom
    ofVec2f bloomPos;
    bloomPos.set(cycloid.trace[bloomNum].x,cycloid.trace[bloomNum].y);
    Bloom bloom(bloomPos, 10.0, 255);
    blooms.push_back(bloom);
    bloomNum++;
    if (bloomNum >= cycloid.trace.size()){
        bloomNum = 0;
    }
    
    //erase dead blooms from vector
    for (int i=0; i<blooms.size(); i++){
        if (blooms[i].dead){
            blooms.erase(blooms.begin()+i);
            i=0;
            cout << "erased bloom" << endl;
        }
    }
    */
    
    
    //SET PARTICLE ATTRACTION
    
    ofVec2f mousePos;
    mousePos.set(ofVec2f(ofGetMouseX(),ofGetMouseY()));
    
    for (int i = 0; i < blooms.size(); i++) {
        for (int j = 0; j < blooms[i].particles.size(); j++){
        
            ofVec2f diff, diffOne, diffTwo;
            
            //GET DIFF FOR LEFT HAND (RIGHT SCREEN)
            //diffOne = mousePos - blooms[i].particles[j].pos;
            diffOne = handPosLeft - blooms[i].particles[j].pos;
            

            //GET DIFF FOR RIGHT HAND (RIGHT SCREEN)
            //diffTwo = mousePos - blooms[i].particles[j].pos;
            diffTwo = handPosRight - blooms[i].particles[j].pos;
            
            if (diffOne.length() <= diffTwo.length()){
                diff = diffOne;
            } else {
                diff = diffTwo;
            }
            
            ofVec2f attraction;
            
            float dist = diff.length();
            
            if (dist < 100) {
                attraction.set(diff.getNormalized()* 0.2);
            }
            
            blooms[i].particles[j].resetForces();
            blooms[i].particles[j].applyForce(attraction);
            blooms[i].particles[j].applyDampingForce(0.02);
        }
        
    }
    
    //update blooms
    for (int i=0; i<blooms.size(); i++){
        
        //update base bloom position (according to cycloid rotation)
        ofVec2f bloomPos;
        bloomPos.set(cycloid.trace[i].x,cycloid.trace[i].y);
        blooms[i].pos.set(bloomPos);
        
        //blooms[i].update(mousePos, mousePos);
        blooms[i].update(handPosLeft, handPosRight);
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if (drawCv){
        
        contourFinder.draw(0, 0, ofGetWidth(), ofGetHeight());;
    } else if (drawGray) {
        grayImage.draw(0, 0, ofGetWidth(), ofGetHeight());
    }
    
    //draw cycloid
    //cycloid.draw();
    
    //draw blooms
    for (int i=0; i<blooms.size(); i++){
        blooms[i].draw();
    }
    
    /*--PROJECTION MASK--*/
    
    //mask.draw(0,0);

}

//--------------------------------------------------------------
void ofApp::exit() {
    kinect.setCameraTiltAngle(0); // zero the tilt on exit
    kinect.close();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case '>':
        case '.':
            farThreshold ++;
            if (farThreshold > 255) farThreshold = 255;
            break;
            
        case '<':
        case ',':
            farThreshold --;
            if (farThreshold < 0) farThreshold = 0;
            break;
            
        case '+':
        case '=':
            nearThreshold ++;
            if (nearThreshold > 255) nearThreshold = 255;
            break;
            
        case '-':
            nearThreshold --;
            if (nearThreshold < 0) nearThreshold = 0;
            break;
            
        case 'd':
            drawGray = !drawGray;
            break;
            
        case 'c':
            drawCv = !drawCv;
            break;
            
        case 'b':
            bLearnBackground = true;
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
