#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //gui
    gui.setup();
    gui.add(rotation.setup("Rotation Speed", 0.01, 0.001, 0.05));
    gui.add(count.setup("Scale", 400, 1, 800));
    gui.add(cubeSize.setup("Cube Size", 10, 0.1, 50));
    gui.add(stop.setup("Stop / Resume", true));
    gui.add(clearButton.setup("Clear"));
    gui.add(exitButton.setup("Exit"));
    //listener
    clearButton.addListener(this, &ofApp::clearButtonPressed);
    exitButton.addListener(this, &ofApp::exitButtonPressed);
    
    
//     ofEnableDepthTest();         //入れるとGUIがバグる
     ofEnableLighting();
     ofSetSmoothLighting(true);

    
    //background
    ofSetBackgroundColor(0);
    
    //camera setup
    lookVec.set(0,0,0);
    camera.setDistance(1500);
    camera.setPosition(ofVec3f(1200,900,1150));
    camera.lookAt(lookVec);

//lighting
    //light0
    ambient.set(0.6, 0.0, 0.0);
    diffuse.set(0.6, 0.0, 0.0);
    specular.set(1.0, 0.0, 0.0);
    light0.setAmbientColor(ambient);
    light0.setDiffuseColor(diffuse);
    light0.setSpecularColor(specular);
    light0.setPosition(50, 350, 300);
    light0.enable();
    
    //light1
    ambient2.set(0.4,0.6,0.4);
    diffuse2.set(0.4,0.6,0.4);
    specular2.set(1.0, 0.8, 0.8);
    light1.setAmbientColor(ambient2);
    light1.setDiffuseColor(diffuse2);
    light1.setSpecularColor(specular2);
    light1.setPosition(1300, 900, 1250);
    light1.enable();
    
    ofToggleFullscreen();

}
//--------------------------------------------------------------

void ofApp::clearButtonPressed(){
    for (int i=0; i<countNum; i++){
        particles[i].setClear();
    }
}

void ofApp::exitButtonPressed(){
    ofExit();
}

//--------------------------------------------------------------
void ofApp::update(){
    countNum = count;
    
    for (int i=0; i<countNum; i++){
        if (stop) particles[i].stopToggle(1);
        if (not stop) particles[i].stopToggle(0);
        particles[i].setCubeSize(cubeSize);
        particles[i].setRotation(rotation);
        particles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();
    
    camera.begin();
//    light0.draw();
//    light1.draw();
    
    for (int i=0; i<countNum; i++){
        particles[i].draw();
    }
       
    camera.end();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 'q')  ofExit();
    
    if (key == ' ') {
        for (int i=0; i<countNum; i++){
            particles[i].setClear();
        }
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
