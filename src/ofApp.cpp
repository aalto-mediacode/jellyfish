#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //RingCurtain ring(ofVec3f(ofGetWidth()/2.0, ofGetHeight()/4.0, 0), 2);
    
    
    
    ofSetBackgroundColor(128);
    //ofSetBackgroundAuto(false);
    
    RingCurtain *ring;
    
    ring = new RingCurtain(ofVec3f(ofGetWidth()/2.0, ofGetHeight()*2, 0), 2);
    
    ring->setup(40, 20, 120, 12);
    
    rings.push_back(ring);
    
    wind.set(ofGetWidth()/2.0, ofGetHeight()/2.0, 0);
    
    /*
    int size = 1;
    int spacing = 10;
    width = ofGetWidth() / spacing + 1;
    height = ofGetHeight() * 0.4 / spacing + 1;
    band_spacing = width / NUM_BANDS;
    
     for(int y=0; y<height; y++){
        for(int x=0; x<width; x++){
            Node n(sin(x) * spacing + size/2.0, y * spacing + size/2.0, 0, size);
            n.setImmovable( false );
            //n.setImmovable( y==0);
            n.setImmovable( y==0 && x % band_spacing == 0 );
            //n.setImmovable( y==0 || x==0 || y==height-1 || x==width-1);
            nodes.push_back( n );
        }
    }
    int strength = 5;
    for(int y=0; y<height; y++){
        for(int x=0; x<width; x++){
            if(y < height-1){
                Connection cy(&nodes[x + y * width], &nodes[x + (y+1) * width], strength);
                connections.push_back( cy );
                //nodes[x + y * width].addConnection( &cy );
                //nodes[x + (y+1) * width].addConnection( &cy );
            }
            if(x < width-1){
                Connection cx(&nodes[x + y * width], &nodes[x + 1 + y * width], strength);
                connections.push_back( cx );
                //nodes[x + y * width].addConnection( &cx );
                //nodes[x + 1 + y * width].addConnection( &cx );
            }
            
            if(x < width-1 && y < height-1){
                Connection cxy(&nodes[x + y * width], &nodes[x + 1 + (y+1) * width], strength);
                connections.push_back( cxy );
                //nodes[x + y * width].addConnection( &cx );
                //nodes[x + 1 + y * width].addConnection( &cx );
            }
            
            if(x > 0 && y < height-1){
                Connection cxy(&nodes[x + y * width], &nodes[x - 1 + (y+1) * width], strength);
                connections.push_back( cxy );
                //nodes[x + y * width].addConnection( &cx );
                //nodes[x + 1 + y * width].addConnection( &cx );
            }
        }
    }
    
    
    for(int i=0, x=0; i<width; i++){
        if(nodes[i].isImmovable()){
            nodes[i].setPosition(ofVec3f(x*40 + 200, 0, 0));
            x++;
        }
    }
    
    num_bands = width+1;
    
    myTrack.load("bensound-jazzyfrenchy.mp3");
    myTrack.play();
    spectrum = (float*)malloc(sizeof(float) * (num_bands+1));
    
    camera.setFov(60);
    camera.setPosition(nodes[nodes.size()/2].getPosition() + ofVec3f(0, -ofGetHeight() * 1.25, 500));
    camera.lookAt(nodes[nodes.size()/2].getPosition());
     
     */
}

//--------------------------------------------------------------
void ofApp::update(){
    /*
    float *newSpectrum = ofSoundGetSpectrum(num_bands * 1.5);
    for(int i=0; i<num_bands; i+=band_spacing){
        newSpectrum[i] *= (i*1+1);
        spectrum[i] *= 0.7;
        spectrum[i] += newSpectrum[i]*newSpectrum[i] * 0.01;
        if(spectrum[i] > 0){
            spectrum[i] = fmin(spectrum[i], 1);
        }
        else {
            spectrum[i] = fmax(spectrum[i], -1);
        }
        //spectrum[i] = newSpectrum[i];
        ofVec3f pos = nodes[i].getPosition();
        pos.z = 100 + spectrum[i] * 100;
        //nodes[i].setPosition( pos );
    }
    */
    
    
//    if(ofGetMousePressed()){
//        if(dragged == NULL){
//            for(auto &node : nodes){
//                if( ofVec3f(mouseX, mouseY, node.getPosition().z).distance( node.getPosition() ) < 10 ){
//                    if(ofGetKeyPressed()){
//                        node.toggleImmovable();
//                    }
//                    else {
//                        dragged = &node;
//                        dragged->startDrag();
//                    }
//                    break;
//                }
//            }
//        }
//    }
//    else if (dragged != NULL ){
//        dragged->stopDrag();
//        dragged = NULL;
//    }
//
//    if(dragged){
//        dragged->addForce( ofVec3f(mouseX, mouseY, 0) - dragged->getPosition(), true);
//    }
//
//
//    if(ofRandom(100) > 95){
//        int r = ofRandom(nodes.size());
//        if(!nodes[r].isImmovable()){
//            //ofVec3f np = nodes[r].getPosition();
//            //np.z += ofRandom(500);
//            //nodes[r].setPosition(np);
//            nodes[r].setVelocity(ofVec3f(0,0,ofRandom(100)));
//        }
//    }
//
//    wind *= 0.99;
//    wind += ofVec3f(ofRandom(1)-0.5, ofRandom(1)-0.5, ofRandom(1)-0.5).normalize() * ofRandom(0.1);
//
//    for(auto &node : nodes){
//        ofVec3f np = node.getPosition() * 0.002;
//        float frame = ofGetFrameNum() * 0.002;
//
//        node.addForce(ofVec3f(0, 0.4, 0));
//        node.addForce(ofVec3f(
//                             ofNoise(np.x, np.y, np.z, frame) - 0.5,
//                             (ofNoise(np.y, np.z, np.x, frame)) * -0.4,
//                             ofNoise(np.z, np.x, np.y, frame) - 0.5
//                             ) * 1);
//
//        node.update();
//    }
//    for(auto &c : connections){
//        c.update();
//        if(!(c.getNodeA()->isImmovable() && c.getNodeA()->isImmovable())){
//            c.getNodeA()->addForce(c.getForce() * -0.5);
//            c.getNodeB()->addForce(c.getForce() * 0.5);
//        }
//        else if(c.getNodeA()->isImmovable()){
//            c.getNodeB()->addForce(c.getForce() * 1);
//        }
//        else if(c.getNodeB()->isImmovable()){
//            c.getNodeA()->addForce(c.getForce() * -1);
//        }
//    }
    
    for(auto *ring : rings){
        ring->applyPointWind(wind, 50, 200);
        ring->addForce((ofVec3f(ofGetWidth()/2.0, (sin(ofGetFrameNum()*0.03)) * ofGetHeight()/4.0 + ofGetHeight()/2.0, 0) - ring->getPosition()) * 0.01);
        ring->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
   /* ofNoFill();
    for(int i=0; i<num_bands; i+=band_spacing){
        float rectWidth = ofGetWidth()/num_bands;
        float rectx = rectWidth*i;
        float rectHeight = ofMap(spectrum[i],0,1,0,100);
        ofDrawRectangle(rectx, 100 - rectHeight / 2, rectWidth, rectHeight);
    }
    */
    //ofSetColor(128, 120);
    //ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
    ofPushMatrix();
        ofTranslate(ofGetWidth()/2.0, ofGetHeight()/2.0);
        ofRotateZDeg(45);
        ofTranslate(-ofGetWidth()/2, -ofGetHeight()/1.8);
        ofSetColor(255, 160);

        for(RingCurtain *ring : rings){
            ring->draw();
        }
    ofPopMatrix();

    
    //camera.begin();
//        ofFill();
//    
//    
//        ofSetColor(255,255,255);
//        ofSetLineWidth(1);
//        for(auto &c : connections){
//            c.draw();
//        }
//        for(auto &node : nodes){
//            node.draw();
//        }
    //camera.end();
    
    
//    if(false)
//    {
//        // Draw vertices
//        ofFill();
//        ofSetPolyMode(OF_POLY_WINDING_NONZERO);
//        for(int y=0; y<height-1; y++){
//            for(int x=0; x<width-1; x++){
//                ofVec3f vx = nodes[x + 1 + y * width].getPosition() - nodes[x + y * width].getPosition();
//                ofVec3f vy = nodes[x + (y+1) * width].getPosition() - nodes[x + y * width].getPosition();
//                
//                ofVec3f vp = vx.getPerpendicular(vy);
//                float angleDiff = vp.angle(ofVec3f(0.5,0.5,-1)) / 180.0;
//                
//                if(y==1 && x==1){
//                }
//                
//                ofSetColor(angleDiff * 128+128, 0, 0);
//                
//                ofBeginShape();
//                    ofVertex(nodes[x + y * width].getPosition());
//                    ofVertex(nodes[x + 1 + y * width].getPosition());
//                    //ofVertex(nodes[x + 1 + (y+1) * width].getPosition());
//                    ofVertex(nodes[x + (y+1) * width].getPosition());
//                ofEndShape();
//                
//                ofBeginShape();
//                    //ofVertex(nodes[x + y * width].getPosition());
//                    ofVertex(nodes[x + 1 + y * width].getPosition());
//                    ofVertex(nodes[x + 1 + (y+1) * width].getPosition());
//                    ofVertex(nodes[x + (y+1) * width].getPosition());
//                ofEndShape();
//                
//                ofSetColor(ofColor::red);
//                ofDrawLine(nodes[x + y * width].getPosition(), nodes[x + y * width].getPosition() + vp * 10);
//            }
//        }
//    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
