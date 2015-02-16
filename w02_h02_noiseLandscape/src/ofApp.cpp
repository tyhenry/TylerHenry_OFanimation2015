#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    mesh.setMode(OF_PRIMITIVE_LINES);
    mesh.enableIndices();
    
    for (int x=0; x<=ofGetWidth(); x+=10){
        for (int y=0; y<=ofGetHeight(); y+=10){
            
            ofVec3f pos(x,y,0); //z==0 for now
            mesh.addVertex(pos);
            
            ofColor c(0, 0, 255.0);
            mesh.addColor(c);
        }
    }
    
    int numVerts = mesh.getVertices().size();
    float connectionDistance = 10;
    
    //loop through all vertices to check distance and connect them
    for (int a=0; a<mesh.getVertices().size(); ++a) {
        
        ofVec3f vertA = mesh.getVertex(a); //get the first vertex to compare
        
        for (int b=a+1; b<numVerts; ++b) { //loop through the rest of the vertices and compare
            
            ofVec3f vertB = mesh.getVertex(b); //get another vertex
            
            float distance = vertA.distance(vertB); //get the distance between two vertices
            
            if (distance <= connectionDistance) { //if the distance is less than or equal to min distance
                
                //add a line between the vertices
                mesh.addIndex(a);
                mesh.addIndex(b);
                
            }
        }
        
        //set noise z-offset to x value of mesh vertex (each column will have same z offset)
        offsets.push_back(ofVec3f(0, 0, 0));
        
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    
    mesh = waveMesh(mesh);
    
    for (int i=0; i<mesh.getVertices().size(); ++i) {
        offsets[i].x++;
        offsets[i].y++;
        
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    easyCam.begin();
    
        ofPushMatrix();
    
            ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    
            mesh.draw();
    
        ofPopMatrix();
    
    easyCam.end();
}

//--------------------------------------------------------------
ofMesh ofApp::waveMesh(ofMesh _mesh){
    
    float mult = 0.01;
    
    int numVerts = _mesh.getNumVertices();
    
    for (int i=0; i<numVerts; ++i) {
        ofVec3f vert = _mesh.getVertex(i);
        
        ofVec3f offset = offsets[i];
        
        //set z value of vertex
        vert.z = ofSignedNoise((vert.x + offset.x) * mult, (vert.y + offset.y) * mult) * 20.0;
        _mesh.setVertex(i, vert);
        
        //set color of vertex based on z
        _mesh.setColor(i, ofColor::fromHsb(ofMap(vert.z,-20,20,255,0),255,255));

    }
    
    return _mesh;
    
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
