//
//  RingCurtain.h
//  Grid
//
//  Created by Juhani Halkomäki on 17/05/2018.
//

#ifndef RingCurtain_h
#define RingCurtain_h

#include "ofMain.h"
#include "Node.h"
#include "Connection.h"

class RingCurtain : public Node {
public:
    RingCurtain(): RingCurtain(ofVec3f(0,0,0), 2) {};
    RingCurtain(ofVec3f _pos, float _size) :
        Node(_pos, _size, 1),
        orientation(0,0,0,0)
    {};
    void setup(float radius, int numHooks, int height, int numRings);
    void update();
    void draw();
    
    void applyPointWind(ofVec3f p, float strength, float radius);
    
    void cleanup();
private:
    void createTentacle(Node *n, float length, int divisions, float strength);
    
    vector<Node*> nodes;
    vector<Connection*> connections;
    float rotation = 0;
    ofQuaternion orientation;
};

#endif /* RingCurtain_h */
