//
//  Node.h
//  Grid
//
//  Created by Juhani Halkomäki on 15/05/2018.
//

#ifndef Node_h
#define Node_h

#include "ofMain.h"
#include "stdlib.h"

class Node {
public:
    Node(float x, float y, float z, float size, float mass):
        pos(x,y,z),
        vel(0,0,0),
        acc(0,0,0),
        size(size),
        mass(mass),
        elasticness(0.95),
        immovable(false),
        isDragged(false),
        forceCounter(0),
        bpos(NULL)
    {};
    
    Node(ofVec3f _pos, float _size, float _mass) : Node(_pos.x, _pos.y, _pos.z, _size, _mass) {};
    
    Node(): Node(0,0,0,1,1) {};
    
    void update();
    void draw();
    
    void addForce(ofVec3f force);
    void addForce(ofVec3f force, bool bruteforce);
    void addRawForce(ofVec3f force);
    void setVelocity(ofVec3f velocity);
    ofVec3f getVelocity();
    
    void setImmovable(bool val);
    void toggleImmovable();
    bool isImmovable();
    
    ofVec3f getPosition();
    void setPosition(ofVec3f npos);
    
    void setElasticity(float val){ elasticness = val; };
    float getMass() { return mass; };
    
    void startDrag();
    void stopDrag();
    
    void bind(ofVec3f* _pos, ofVec3f* _vel);
    
public:
    ofVec3f pos, vel, acc, brel, bdir;
    ofVec3f *bpos, *bvel;
    float mass;
    float size;
    bool immovable;
    bool isDragged;
    int forceCounter;
    float elasticness;
};

#endif /* Node_h */
