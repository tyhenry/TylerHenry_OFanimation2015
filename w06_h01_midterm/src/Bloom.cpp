//
//  Bloom.cpp
//  midterm_particlestest
//
//  Created by Tyler Henry on 3/17/15.
//
//

#include "Bloom.h"

Bloom::Bloom(ofVec2f _pos, int _size, float _hue){
    
    pos.set(_pos);
    size = _size;
    hue = _hue;
    
    for (int i=0; i<size; i++){
        Particle particle(pos, 0, 3, hue);
        particles.push_back(particle);
    }
    
    dead = false;
    
}

void Bloom::resetForces(){
    for (int i=0; i<size; i++){
        particles[i].resetForces();
    }
}

void Bloom::applyForce(ofVec2f force){
    for (int i=0; i<size; i++){
        particles[i].applyForce(force);
    }
}

void Bloom::applyDampingForce(float damping){
    for (int i=0; i<particles.size(); i++){
        particles[i].applyDampingForce(damping);
    }
}

void Bloom::update(ofVec2f mousePos){
    //dead = true;
    for (int i=0; i<size; i++){
        particles[i].update(mousePos, mousePos, pos);
        
        //if (!particles[i].dead) dead = false;
    }
    

}

void Bloom::draw(){
    for (int i=0; i<size; i++){
        particles[i].draw();
    }
    
}
