//
//  ParticleSystem.cpp
//  w05_h02_knowledgeIsPower
//
//  Created by Tyler Henry on 3/10/15.
//
//

#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(ofVec2f _pos, int _size, float _hue){
    
    pos.set(_pos);
    size = _size;
    hue = _hue;
    
    for (int i=0; i<size; i++){
        Particle particle(pos, (size/25), ofRandom(5,10), hue);
        particles.push_back(particle);
    }
    
    dead = false;
    
}

void ParticleSystem::resetForces(){
    for (int i=0; i<size; i++){
        particles[i].resetForces();
    }
    
}

void ParticleSystem::applyForce(ofVec2f force){
    for (int i=0; i<size; i++){
        particles[i].applyForce(force);
    }
}

void ParticleSystem::update(){
    
    
    dead = true;
    for (int i=0; i<size; i++){
        particles[i].update();
        
        if (!particles[i].dead) dead = false;
    }
    if (dead) {
        cout << "dead ParticleSystem" << endl;
    }
    
}

void ParticleSystem::draw(){
    for (int i=0; i<size; i++){
        particles[i].draw();
    }
    
}

