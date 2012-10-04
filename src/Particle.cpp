//
//  Particle.cpp
//  particle_engine
//
//  Created by Ira on 9/18/12.
//
//

#include "Particle.h"


/*Particle::Particle(ofVec2f loc, ofVec2f spd, float radius):
loc(loc), spd(spd), radius(radius)
{
    //std::cout << "loc size = " << sizeof(loc) << std::endl;
}*/

Particle::Particle(const ofVec2f& loc, const ofVec2f& spd, float radius):
loc(loc), spd(spd), radius(radius)
{
     //std::cout << "loc pointer size = " << sizeof(loc) << std::endl;
}

// overload ops
Particle& Particle::operator+=(const ofVec2f& vel)
{
    spd += vel;
    //std::cout << "vel = " << vel << std::endl;
    return *this;
}

Particle& Particle::operator*=(const ofVec2f& vel)
{
    spd *= vel;
    //std::cout << "vel = " << vel << std::endl;
    return *this;
}




//function implmentations
void Particle::move()
{
    loc += spd;
    //std::cout << "spd.x = " << spd.x << std::endl;
}

void Particle::display()
{
    ofPushMatrix();
    // either syntax works to connect instance pointer to field
    ofTranslate(loc.x, loc.y);
    
    ofCircle(0, 0, radius);
    ofPopMatrix();
}

void Particle::collide()
{
    if(loc.x > ofGetWidth()-radius) {
        spd.x *= -1;
    }
    
    if(loc.x < radius) {
        spd.x *= -1;
    }
    
    if(loc.y > ofGetHeight()-radius) {
        spd.y *= -1;
        spd.y *= .75;
        
    }
    
    if(loc.y < radius) {
        spd.y *= -1;
    }
}

//setters/getters
void Particle::setLoc(const ofVec2f&  loc)
{
    
    this->loc = loc;
}

ofVec2f& Particle::getLoc()
{
    return loc;
}


void Particle::setSpd(const ofVec2f& spd)
{
    this->spd = spd;
}

ofVec2f& Particle::getSpd()
{
    return spd;
}

void Particle::setRadius(float radius)
{
    this->radius = radius;
}

float Particle::getRadius() const
{
    return radius;
}

void Particle::setMass(float mass)
{
    this->mass = mass;
}
float Particle::getMass() const
{
    return mass;
}
