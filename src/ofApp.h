#pragma once

#include "ofMain.h"
//#include "Node.h"
//#include "Connection.h"
#include "RingCurtain.h"

#define NUM_BANDS 10

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    //vector<Node> nodes;
    //vector<Connection> connections;
    
    vector<RingCurtain*> rings;
    
    Node *dragged = NULL;
    
    ofSoundPlayer myTrack;
    float *spectrum;
    int num_bands;
    int band_spacing;
    int width, height;
    ofVec3f wind;
    
    ofCamera camera;
};
