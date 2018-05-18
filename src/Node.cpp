//
//  Node.cpp
//  Grid
//
//  Created by Juhani Halkomäki on 15/05/2018.
//

#include "Node.h"

void Node::update(){
    if(bpos == NULL){
        vel *= elasticness;
        //acc /= (forceCounter + 1);
        acc.limit(1);
        vel += acc;// / forceCounter;
        //vel.limit(100);
        pos += vel;
        acc *= 0;
        forceCounter = 0;
    }
    else {
        pos.set(*bpos + brel);
    }
    
}

void Node::draw(){
    if(immovable){
        ofSetColor(255,0,0);
    }
    else {
        //ofSetColor(255,255,255,acc.length()*255);
        ofSetColor(255);
    }
    ofDrawCircle(pos, size);
}

void Node::addForce(ofVec3f force){
    if(!immovable){
        acc += force * mass;
        forceCounter++;
    }
}

void Node::addForce(ofVec3f force, bool bruteforce){
    acc += force * mass;
    forceCounter++;
}

void Node::addRawForce(ofVec3f force){
    if(!immovable){
        acc += force;
        forceCounter++;
    }
}

void Node::setVelocity(ofVec3f velocity){
    vel.set(velocity);
}

ofVec3f Node::getVelocity(){
    return vel;
}

void Node::setImmovable(bool val){
    immovable = val;
}

void Node::toggleImmovable(){
    immovable = !immovable;
}

bool Node::isImmovable(){
    return immovable || isDragged;
}

void Node::setPosition(ofVec3f npos){
    pos.set(npos);
}

ofVec3f Node::getPosition(){
    return pos;
}

void Node::startDrag(){
    isDragged = true;
}

void Node::stopDrag(){
    isDragged = false;
}

void Node::bind(ofVec3f* _pos, ofVec3f* _vel){
    bpos = _pos;
    bvel = _vel;
    bdir.set(0,1,0);
    brel.set(*_pos - pos);
}
