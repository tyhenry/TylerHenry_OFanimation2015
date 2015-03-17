#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGLFWWindow.h"


//========================================================================
int main(){
    ofAppGLFWWindow window;
    window.setMultiDisplayFullscreen(true);
    
    //setup the GL context
    ofSetupOpenGL(&window,1024,768,OF_FULLSCREEN);

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
