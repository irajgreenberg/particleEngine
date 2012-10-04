#include "CSE1342App.h"

//--------------------------------------------------------------
void CSE1342App::setup(){
	ofBackground(255,255,255);
	ofSetWindowTitle("Particle Engine");
	ofSetFrameRate(60); // if vertical sync is off, we can go a bit fast... this caps the framerate at 60fps.
    ofVec2f _loc(100, 100);
    ofVec2f _spd(2.3, 1.7);
    ofSetColor(255, 100, 0);
    ofFill();
    
    engine = Engine(ofVec2f(ofGetWidth()/2, 100), 3000, .15, .95, 10, true);
    engine.setBoundaryCollision();
    engine.setFriction(.9);
    engine.setParticleRadius(3);
    engine.setPhysicsOn();
    
    
    engine2 = Engine(ofVec2f(ofGetWidth()/1.2, 10), 3000, .45, .95, 10, true);
    engine2.setBoundaryCollision();
    engine2.setFriction(.9);
    engine2.setParticleRadius(1);
    engine2.setPhysicsOn();
    
    std::cout << engine << std::endl;
}

//--------------------------------------------------------------
void CSE1342App::update(){
    engine.run();
    engine2.run();
}

//--------------------------------------------------------------
void CSE1342App::draw(){
   engine.display();
   engine2.display();
}

//--------------------------------------------------------------
void CSE1342App::keyPressed(int key){
    
}

//--------------------------------------------------------------
void CSE1342App::keyReleased(int key){
    
}

//--------------------------------------------------------------
void CSE1342App::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void CSE1342App::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void CSE1342App::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void CSE1342App::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void CSE1342App::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void CSE1342App::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void CSE1342App::dragEvent(ofDragInfo dragInfo){
    
}