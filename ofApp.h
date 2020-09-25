#pragma once

#include "ofMain.h"
#include "particle.h"
#include "ofxGui.h"


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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofEasyCam camera;
    ofLight light0;
    ofLight light1;
    ofFloatColor ambient, diffuse, specular;
    ofFloatColor ambient2, diffuse2, specular2;
    ofVec3f lookVec;

    
    int countNum;
    static const int num = 1000;
    particle particles[num];
    
    //gui
    ofxPanel gui;
    ofxFloatSlider rotation;
    ofxFloatSlider count;
    ofxFloatSlider cubeSize;
    ofxButton exitButton;
    ofxButton clearButton;
    ofxToggle stop;
    
    void exitButtonPressed();
    void clearButtonPressed();
		
};
