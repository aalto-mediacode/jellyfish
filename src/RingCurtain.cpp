//
//  RingCurtain.cpp
//  Grid
//
//  Created by Juhani Halkomäki on 17/05/2018.
//

#include "RingCurtain.h"

void RingCurtain::setup(float radius, int numHooks, int height, int numRings){
    float heightSpacing = height/(float)numRings;
    float angle_stepsize = 2 * PI / (float)numHooks;
    int strength = 3;
    
    for(int y=0; y<numRings; y++){
        for(int x=0; x<numHooks; x++){
            float angle = x * angle_stepsize;
            Node *n = new Node(radius*cos(angle) + pos.x, y*heightSpacing + pos.y, radius*sin(angle) + pos.z, 1, 0.8);
            n->setElasticity(0.9);
            if(y==0){
                n->bind(&pos, &vel);
            }
            nodes.push_back( n );
        }
    }
    

    for(int y=0; y<numRings; y++){
        for(int x=0; x<numHooks; x++){
            
            if(y < numRings-1){
                connections.push_back( new Connection(nodes[(x + y * numHooks)], nodes[(x + (y+1) * numHooks)], strength) );
//                if(x > 0){
//                    connections.push_back( new Connection(nodes[x + y * numHooks], nodes[x - 1 + (y+1) * numHooks], strength) );
//                }
            }
            if(x < numHooks-1){
                connections.push_back( new Connection(nodes[x + y * numHooks], nodes[x + 1 + y * numHooks], strength) );
//                if(y < numRings-1){
//                    connections.push_back( new Connection(nodes[x + y * numHooks], nodes[x + 1 + (y+1) * numHooks], strength) );
//                }
            }
            else {
                connections.push_back( new Connection(nodes[x + y * numHooks], nodes[x + 1  + (y-1) * numHooks], strength) );
//                if(y < numRings-1){
//                    connections.push_back( new Connection(nodes[x + y * numHooks], nodes[x + 1 + y * numHooks], strength) );
//                }
            }
            
            float len = ofRandom(100, 300);
            createTentacle(nodes[x + y * numHooks], len, len/20, strength);
        }
    }
    
     
}

void RingCurtain::createTentacle(Node *n, float length, int divisions, float strength){
    Node *parent;
    parent = n;
    ofVec3f dir(n->getPosition().x - pos.x, 0, n->getPosition().z - pos.y);
    dir.normalize();
    
    for(int i=0; i<divisions; i++){
        Node *t = new Node(dir*(length/(float)divisions) + parent->getPosition(), (i==divisions-1 ? 2 : 0.5), 0.05);
        t->setElasticity(0.97);
        nodes.push_back( t );
        Connection *c = new Connection(parent, t, 1);
        c->setOpacity(0.4);
        connections.push_back( c );
        parent = t;
    }
}

void RingCurtain::update(){
    Node::update();
    
    for(Node* &node : nodes){
        if(!node->isImmovable())
        {
            ofVec3f np = node->getPosition() * 0.002;
            float frame = ofGetFrameNum() * 0.002;

            node->addForce(ofVec3f(0, 1, 0));
            node->addForce(ofVec3f(
                                 ofNoise(np.x, np.y, np.z, frame) - 0.5,
                                 (ofNoise(np.y, np.z, np.x, frame)) * 0,
                                 ofNoise(np.z, np.x, np.y, frame) - 0.5
                                 ) * 1.5);
        }
        
        node->update();
    }
    
    for(Connection* &c : connections){
        c->update();
        float massA = c->getNodeA()->getMass();
        float massB = c->getNodeB()->getMass();
        float distr = massA / (massA + massB);
        if(!(c->getNodeA()->isImmovable() && c->getNodeA()->isImmovable())){
            
            c->getNodeA()->addRawForce(c->getForce() * -0.5);
            c->getNodeB()->addRawForce(c->getForce() * 0.5);
        }
        else if(c->getNodeA()->isImmovable()){
            c->getNodeB()->addRawForce(c->getForce() * 1);
        }
        else if(c->getNodeB()->isImmovable()){
            c->getNodeA()->addRawForce(c->getForce() * -1);
        }
    }
}

void RingCurtain::applyPointWind(ofVec3f p, float strength, float radius){
    for(Node* &node : nodes){
        ofVec3f dir = (node->getPosition() - p);
        float force = 1/ofMap(dir.length(), 0, radius, 1, 0);
        force = fmin( fmax(force, 0), 1);
        force = force * force;
        node->addForce( dir.getNormalized()*force*strength );
    }
}

void RingCurtain::draw(){
    for(Node* &node : nodes){
        node->draw();
    }
    for(Connection* &c : connections){
        c->draw();
    }
}

void RingCurtain::cleanup(){
    for(Node* &node : nodes){
        delete node;
    }
    for(Connection* &c : connections){
        delete c;
    }
}
