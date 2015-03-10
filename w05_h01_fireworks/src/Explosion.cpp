//
//  Explosion.cpp
//  w05_h01_fireworks
//
//  Created by Tyler Henry on 3/10/15.
//
//

#include "Explosion.h"

Explosion::Explosion(ofVec2f _pos, int _size, float _hue){
    
    pos.set(_pos);
    size = _size;
    hue = _hue;
    
    for (int i=0; i<size; i++){
        Particle particle(pos, (size/25), 5, hue);
        particles.push_back(particle);
    }
    
    dead = false;
    
}

void Explosion::resetForces(){
    for (int i=0; i<size; i++){
        particles[i].resetForces();
    }
    
}

void Explosion::applyForce(ofVec2f force){
    for (int i=0; i<size; i++){
        particles[i].applyForce(force);
    }
}

void Explosion::update(){
    dead = true;
    for (int i=0; i<size; i++){
        particles[i].update();
        
        if (!particles[i].dead) dead = false;
    }
    if (dead) {
        cout << "dead explosion" << endl;
    }

}

void Explosion::draw(){
    for (int i=0; i<size; i++){
        particles[i].draw();
    }
    
}

