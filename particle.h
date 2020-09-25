//
//  particle.hpp
//  gp_2020_final_3D
//
//  Created by Maya Akahane on 2020/07/15.
//

#ifndef particle_hpp
#define particle_hpp

#include <stdio.h>
#include "ofMain.h"

class particle {
public:
    
    //constructor
    particle();
    
    //method
    void setup();
    void update();
    void draw();
    
    void setRotation(float rot);
    void stopToggle(int stopNum);
    void setCubeSize(int cSize);
    void setClear();
    
    //property
    ofVec3f pos;
    ofVec3f pos2;
    ofVec3f pos3;
    ofVec3f vel;
    float rotation;
    float addRotation;
    float size;
    float size2;
    float size3;
    int resumeNum;
    
};

#endif /* particle_hpp */
