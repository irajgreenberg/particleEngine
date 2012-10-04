//
//  Engine.cpp
//  particle_engine
//
//  Created by Ira on 9/19/12.
//
//

#include "Engine.h"

Engine::Engine(const ofVec2f& loc, int particleCount, float gravity, float damping, float lifeSpan, bool isBoundaryCollision):
loc(loc), particleCount(particleCount), gravity(gravity), damping(damping), lifeSpan(lifeSpan), isBoundaryCollision(isBoundaryCollision) {
    init();
}

Engine::~Engine()
{
    //std::cout << "in destructor" << std:: endl;
    delete [] parts;
}

// overloaded << operator for outputting field values in objects
std::ostream& operator<<(std::ostream& output, const Engine& eng) {
    output << "Engine Instance Fields[\n  particleCount = " << eng.particleCount <<
    ",\n  lifeSpan = " << eng.lifeSpan <<
    ",\n  gravity = " << eng.gravity <<
    ",\n  damping = " << eng.damping <<
    ",\n  friction = " << eng.friction <<
    ",\n  isBoundaryCollision = " << eng.isBoundaryCollision <<
    ",\n  isPhysicsOn = " << eng.isPhysicsOn <<
    ",\n  particleRadius = " << eng.particleRadius <<
    ",\n  sprayRadius = " << eng.sprayRadius <<
    ",\n  emissionRate = " << "(" << eng.emissionRate.x <<
    ", " << eng.emissionRate.y << ")"<< "\n]";
    return output;
}

// assignment operator

// both things exist
Engine& Engine::operator=(const Engine& eng)
{
    // Only do assignment if "eng" is a different object from "this".
    if (this != &eng) {
        // Deallocate, allocate new space, copy values...
        delete [] parts;
        loc = eng.loc;
        particleCount = eng.particleCount;
        particleRadius = eng.particleRadius;
        lifeSpan = eng.lifeSpan;
        gravity = eng.gravity;
        damping = eng.damping;
        friction = eng.friction;
        isPhysicsOn = eng.isPhysicsOn;
        isBoundaryCollision = eng.isBoundaryCollision;
        sprayRadius = eng.sprayRadius;
        init();
    }
    return *this;
}


// 1 thing exists and 1 thing doesn't exist
// copy constructor
Engine::Engine(const Engine& eng)
{
    // Deallocate, allocate new space, copy values...
    delete [] parts;
    loc = eng.loc;
    particleCount = eng.particleCount;
    particleRadius = eng.particleRadius;
    lifeSpan = eng.lifeSpan;
    gravity = eng.gravity;
    damping = eng.damping;
    friction = eng.friction;
    isPhysicsOn = eng.isPhysicsOn;
    isBoundaryCollision = eng.isBoundaryCollision;
    sprayRadius = eng.sprayRadius;
    init();
    
}


void Engine::init()
{
    parts = new Particle[particleCount];
    particleRadius = 3;
    for (int i=0; i<particleCount; i++){
        parts[i] = Particle(loc, ofVec2f(ofRandom(-.5, .5), ofRandom(.2, 1.2)), ofRandom(particleRadius*.05, particleRadius));
    }
}


void Engine::setParticles(Particle parts[])
{
    this->parts = parts;
}

void Engine::run()
{
    // move particles
    for (int i=0; i<particleCount; i++){
        parts[i] += ofVec2f(0, gravity);
        parts[i].move();
        
        // handle collision
        if(isBoundaryCollision){
            ofVec2f tempLoc; // part of keeping particles from moving through ground
            // wall collision
            if(parts[i].getLoc().x > ofGetWidth()-parts[i].getRadius()){
                tempLoc.x = ofGetWidth()-parts[i].getRadius();
                tempLoc.y = parts[i].getLoc().y;
                parts[i].setLoc(tempLoc);
                parts[i] *= ofVec2f(-1, 1);
            } else if(parts[i].getLoc().x < parts[i].getRadius()){
                tempLoc.x = parts[i].getRadius();
                tempLoc.y = parts[i].getLoc().y;
                parts[i].setLoc(tempLoc);
                parts[i] *= ofVec2f(-1, 1);
            }
            
            // ground/ceiling collision
            if(parts[i].getLoc().y > ofGetHeight()-parts[i].getRadius()){
                tempLoc.x = parts[i].getLoc().x;
                tempLoc.y = ofGetHeight()-parts[i].getRadius();
                parts[i].setLoc(tempLoc);
                parts[i] *= ofVec2f(1, -1);
                
                if(isPhysicsOn){
                    //std::cout << "damping = " << damping << std::endl;
                    parts[i] *= ofVec2f(1, ofRandom(damping));
                    parts[i] *= ofVec2f(friction, 1);
                }
                
            } else if(parts[i].getLoc().y < parts[i].getRadius()){
                tempLoc.x = parts[i].getLoc().x;
                tempLoc.y = parts[i].getRadius();
                parts[i] *= ofVec2f(1, -1);
            }

            
        }
    }
}

void Engine::display()
{
    for (int i=0; i<particleCount; i++){
        parts[i].display();
    }
}

void Engine::setGravity(float gravity)
{
    this->gravity = gravity;
}

void Engine::setLifeSpan(float lifeSpan)
{
    this->lifeSpan = lifeSpan;
}

void Engine::setBoundaryCollision(bool isBoundaryCollision)
{
    this->isBoundaryCollision = isBoundaryCollision;
}

void Engine::setPhysicsOn(bool isPhysicsOn)
{
    this->isPhysicsOn = isPhysicsOn;
}

void Engine::setFriction(float friction)
{
    this->friction = friction;
}

void Engine::setEmissionRate(const ofVec2f& emissionRate)
{
    this->emissionRate = emissionRate;
}

void Engine::setParticleRadius(float particleRadius)
{
    this->particleRadius = particleRadius;
    for (int i=0; i<particleCount; i++){
        parts[i].setRadius(ofRandom(particleRadius*.05, particleRadius));
    }
}
