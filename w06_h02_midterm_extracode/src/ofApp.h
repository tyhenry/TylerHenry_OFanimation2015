#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxKinect.h"
#include "Mover.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        /*-- KINECT + OPENCV --*/
    
        ofxKinect kinect;
    
        ofxCvColorImage colorImg;
        
        ofxCvGrayscaleImage grayImage; // grayscale depth image
        ofxCvGrayscaleImage grayBg; // grayscale background image
        ofxCvGrayscaleImage grayDiff; // image with background subtracted
        ofxCvGrayscaleImage grayThreshNear; // the near thresholded image
        ofxCvGrayscaleImage grayThreshFar; // the far thresholded image

        
        ofxCvContourFinder contourFinder;
            
        int nearThreshold;
        int farThreshold;
    
        int angle; //kinect tilt angle
        
        bool bLearnBackground, drawCv, drawGray;
    
        /*-- PARTICLES --*/
    
        ofVec2f handPosLeft, handPosRight;
    
        vector <Mover> moverList;
    
        /*--PROJECTION MASK--*/
    
        ofImage mask;
		
};
