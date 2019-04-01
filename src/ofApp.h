#pragma once

#include "ofMain.h"
#include "ofxPy.h"

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
    
    ofxPy::Context  python;
    
    ofVideoGrabber cam;
    ofImage screenshot;
    
    ofPixels pixel1;
    ofColor point1;
    ofColor point2;
    ofColor point3;
    ofColor point4;
    ofColor point5;
    
    char buf[100];
    
    int x1;
    int y1;
    int rectWidth;
    int rectHeight;
    int diameter;
    
    float cRed;
    float cGreen;
    float cBlue;
    
    
    bool imageShow;
};
