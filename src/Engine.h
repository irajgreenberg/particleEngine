//
//  Header.h
//  particle_engine
//
//  Created by Ira on 9/19/12.
//
//

#ifndef particle_engine_Header_h
#define particle_engine_Header_h

#include "Particle.h"
#include "ofMain.h"
#include <iostream>

class Engine {


private:
    ofVec2f loc;
    ofVec2f vel;
    Particle* parts;
    int particleCount;
    float particleRadius;
    float lifeSpan;
    float gravity, damping, friction;
    bool isBoundaryCollision;
    bool isPhysicsOn;
    float sprayRadius;
    ofVec2f emissionRate;
    void init();
    
    
public:
    friend std::ostream& operator<<(std::ostream& output, const Engine& eng);
    
    // constructor
    explicit Engine(const ofVec2f& loc = ofVec2f(), int particleCount = 20, float gravity = .02, float damping = .875, float lifeSpan = 10, bool isBoundaryCollision = false);
    virtual ~Engine(); // override destructor
    
    Engine(const Engine& eng); // override copy constructor
    
    Engine& operator=(const Engine& eng); // override assignment op
    
    void setParticles(Particle parts[]);
    void run();
    void display();
    void setGravity(float gravity=.002);
    void setLifeSpan(float lifeSpan = 10);
    void setBoundaryCollision(bool isBoundaryCollision = true);
    void setPhysicsOn(bool isPhysicsOn = true);
    void setEmissionRate(const ofVec2f& emissionRate = ofVec2f(.5, -.5));
    void setFriction(float friction = .75);
    void setParticleRadius(float particleRadius = 3);
    
};

#endif
