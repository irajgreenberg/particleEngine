//
//  Particle.h
//  particle_engine
//
//  Created by Ira on 9/18/12.
//
//

//
//  Particle.h
//  animatingParticles
//
//  Created by Ira on 8/27/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef animatingParticles_Particle_h
#define animatingParticles_Particle_h

#include "ofMain.h"

// currently no heap allocation
class Particle {
    
private:
    
    float mass;
    ofVec2f loc;
    ofVec2f spd;
    float radius;


public:
    
    
    //Particle(const ofVec2f& loc, const ofVec2f& spd, float radius);
    
   // constructor - explicit keyword avoids single param implicit conversions
    explicit Particle(const ofVec2f& loc = ofVec2f(200, 200), const ofVec2f& spd = ofVec2f(1, 1.9), float radius = 8);
    
    // overload ops
    //+=
    Particle& operator+=(const ofVec2f& vel);
    Particle& operator*=(const ofVec2f& vel);
    
    
    //function protoypes
    void move();
    void display();
    void collide();
    
    //setters/getters
    void setLoc(const ofVec2f& loc);
    ofVec2f& getLoc();

    
    void setSpd(const ofVec2f& spd);
    ofVec2f& getSpd();
    
    void setRadius(float radius);
    float getRadius() const;
    
    void setMass(float mass);
    float getMass() const;
 

    
    
};

#endif
