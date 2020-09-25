//
//  particle.cpp
//  gp_2020_final_3D
//
//  Created by Maya Akahane on 2020/07/15.
//

#include "particle.h"

particle::particle() {
    setup();
}

void particle::setup(){
    pos.set(ofRandom(50,200));
    pos2.set(ofRandom(50,200));
    pos3.set(ofRandom(50,200));
    vel.set(0.1, 5);
    rotation = 0;
    addRotation = 0.1;
    
    size = ofRandom(10);
    size2 = ofRandom(0.1,5.0);
    size3 = ofRandom(0.1,3);
}

void particle::update(){
    

    
    if (resumeNum == 1) {
        vel.set(0.1, 5);

        if (pos.x < ofGetWidth() && pos.y < ofGetHeight()) {
            pos += vel;
            pos2 += vel;
            pos3 += vel/2;
        }
        
        if (pos.x >= ofGetWidth() || pos.y >= ofGetHeight()) {
            pos.set(0);
        }
        
        if (pos2.x >= ofGetWidth()*1.5 || pos2.y >= ofGetHeight()*1.5) {
            pos2.set(0);
        }
        
        if (pos3.x >= ofGetWidth()*2.0 || pos3.y >= ofGetHeight()*1.3) {
            pos3.set(0);
        }
        
        rotation += addRotation;

    }
    
    if (resumeNum == 0) {
        vel.set(0, 0);
        rotation += 0;
    }
        
}

void particle::draw(){
    
    ofRotateDeg(rotation);
    ofDrawBox(pos.x, pos.y, pos.z, size);
    ofDrawSphere(pos2.x, pos2.y, pos2.z, size2);
    ofDrawCone(pos3.x, pos3.y, pos3.z, size3, size3*2);

    ofRotateXDeg(rotation);
    ofDrawBox(pos.x, pos.y, pos.z, size);
    ofDrawSphere(pos2.x, pos2.y, pos2.z, size2);
    ofDrawCone(pos3.x, pos3.y, pos3.z, size3, size3*2);

    
    ofRotateYDeg(rotation);
    ofDrawBox(pos.x, pos.y, pos.z, size);
    ofDrawSphere(pos2.x, pos2.y, pos2.z, size2);
    ofDrawCone(pos3.x, pos3.y, pos3.z, size3, size3*2);

}

void particle::setRotation(float rot) {
    addRotation = rot;
}



void particle::stopToggle(int stopNum) {
    resumeNum = stopNum;
}

void particle::setCubeSize(int cSize) {
    size = cSize;
}

void particle::setClear(){
    rotation = 0;
    pos.set(ofRandom(50,200));
    pos2.set(ofRandom(50,200));
    pos3.set(ofRandom(50,200));

}
