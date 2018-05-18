//
//  Connector.h
//  Grid
//
//  Created by Juhani Halkomäki on 15/05/2018.
//

#ifndef Connection_h
#define Connection_h

#include "ofMain.h"
#include "Node.h"

#define DIFF_BUFFER_SIZE 30

class Connection {
public:
    Connection(Node *a, Node *b, float strength) :
        nodeA(a),
        nodeB(b),
        length( (a->getPosition() - b->getPosition()).length() ),
        strength(strength),
        opacity(1)
    {};
    
    void update();
    void draw();
    ofVec3f getForce();
    Node *getNodeA();
    Node *getNodeB();
    void setOpacity(float val) { opacity = fmin( fmax(val, 0), 1); } ;
private:
    float opacity;
    float length;
    float strength;
    ofVec3f acc;
    ofVec3f force;
    Node *nodeA;
    Node *nodeB;
    float diff_buffer[DIFF_BUFFER_SIZE] = {0};
    int buffer_index = 0;
    float diff_avg=0;
    
    void addToBuffer(float diff);
};

#endif /* Connection_h */
