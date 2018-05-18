//
//  Connector.cpp
//  Grid
//
//  Created by Juhani Halkomäki on 15/05/2018.
//

#include "Connection.h"

void Connection::update(){
    ofVec3f diff = (nodeA->getPosition()+nodeA->getVelocity()) - (nodeB->getPosition()+nodeB->getVelocity());
    float dist = diff.length();
    dist = dist/length - 1;
    addToBuffer(dist);
    if(dist > 0 && diff_avg > 0.001)
    {
        float tension = dist * dist;
        force.set(diff.getNormalized() * tension * strength);
    }
    else
    {
        force *= 0.3;
    }
}

void Connection::addToBuffer(float diff){
    diff_buffer[buffer_index] = diff;
    buffer_index++;
    if(buffer_index >= DIFF_BUFFER_SIZE-1){
        buffer_index = 0;
    }
    
    float sum = 0;
    for(int i=0; i<DIFF_BUFFER_SIZE; i++){
        sum += diff_buffer[i];
    }
    diff_avg = sum / DIFF_BUFFER_SIZE;
}

void Connection::draw(){
    ofSetColor(255, opacity * 255);
    ofSetLineWidth(1);
    ofDrawLine(nodeA->getPosition(), nodeB->getPosition());
}

ofVec3f Connection::getForce(){
    return force;
}

Node *Connection::getNodeA(){
    return nodeA;
}

Node *Connection::getNodeB(){
    return nodeB;
}
