//
//  ParticleSystem.h
//  w05_h02_knowledgeIsPower
//
//  Created by Tyler Henry on 3/10/15.
//
//

#include "Particle.h"

class ParticleSystem{
public:
    
    ParticleSystem(ofVec2f _pos, int size, float hue);
    void resetForces();
    void applyForce(ofVec2f _force);
    void update();
    void draw();
    
    ofVec2f pos;
    int size;
    float hue;
    vector<Particle> particles;
    
    bool dead; //track life of ParticleSystem
};