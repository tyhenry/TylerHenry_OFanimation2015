#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        //SOUNDS
    
        void audioIn(float* input, int bufferSize, int nChannels);
        
        vector <float> left;
        vector <float> right;
    
        float smoothedVol;
        float scaledVol;
    
        
        ofSoundStream soundStream;
    
        //SHAPES
    
        ofEasyCam cam;
        ofIcoSpherePrimitive icoSphere;
        
        ofLight extLight;
        ofLight intLight;
        
        float sinOfTime, offset;
        vector<ofMeshFace> origTriangles;
        vector<ofMeshFace> triangles;
		
};
