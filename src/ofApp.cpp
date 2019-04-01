#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    python.setup();
    cam.setup(640, 480);
    cam.listDevices();
    
    x1 = ofGetWidth()/4;
    y1 = ofGetHeight()/4;
    rectWidth = ofGetWidth()/2;
    rectHeight = ofGetHeight()/2;
    diameter = 20;
    imageShow = false;
    
    screenshot.grabScreen(x1, y1, rectWidth, rectHeight);
    
    putenv((char *)"PYTHONHOME=/Users/noriyukisuzuki/.pyenv/versions/anaconda3-4.3.1");
    python.setup();
    // append data/python to PYTHONPATH
    python.appendPath(ofToDataPath("python"));
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    cam.draw(0, 0);
    ofRectangle myRect(x1, y1, rectWidth, rectHeight);
    
    if(imageShow == true){
        
        
        ofFill();
        screenshot.draw(x1,y1,rectWidth,rectHeight);
        
        /*
         // image processing ///////////////////////////////////////////
         ofSetColor(point1);
         ofDrawCircle(x1, y1, diameter);
         
         ofSetColor(point2);
         ofDrawCircle(x1+myRect.getWidth(), y1, diameter);
         
         ofSetColor(point3);
         ofDrawCircle(x1, y1+myRect.getHeight(), diameter);
         
         ofSetColor(point4);
         ofDrawCircle(x1+myRect.getWidth(), y1+myRect.getHeight(), diameter);
         
         ofSetColor(point5);
         ofDrawCircle(x1+myRect.getWidth()/2, y1+myRect.getHeight()/2, diameter);
         ///////////////////////////////////////////
         */
    }
    
    
    ofNoFill();
    ofSetColor(255);
    ofDrawRectangle(x1, y1, rectWidth, rectHeight);
    ofDrawCircle(x1, y1, diameter);
    ofDrawCircle(x1+myRect.getWidth(), y1, diameter);
    ofDrawCircle(x1, y1+myRect.getHeight(), diameter);
    ofDrawCircle(x1+myRect.getWidth(), y1+myRect.getHeight(), diameter);
    ofDrawCircle(x1+myRect.getWidth()/2, y1+myRect.getHeight()/2, diameter);
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 's'){
        char fileNameStr[255];
        string date = ofGetTimestampString();// time stamp
        sprintf(fileNameStr, "%s.png", date.c_str());
        screenshot.save(fileNameStr);
    }
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
    // write if statement after video available
    
    std::printf("mousePressed\n");
    screenshot.grabScreen(x1,y1,rectWidth,rectHeight);
    
    
    // image processing ///////////////////////////////////////////
    unsigned char *pixels = screenshot.getPixels().getData();
    int w = screenshot.getWidth();
    int h = screenshot.getHeight();
    int type = screenshot.getImageType();
    int bpp = screenshot.getPixels().getBitsPerPixel()/ 8;
    std::printf("imageType : %d, bpp : %d\n", type, bpp);
    // myImageType will be equal to one of these constants:
    //   OF_IMAGE_GRAYSCALE (aka a value of 0)
    //   OF_IMAGE_COLOR (aka a value of 1)
    //   OF_IMAGE_COLOR_ALPHA (aka a value of 2)
    // bpp here means amounts of channel e.g 4 -> rgba
    
    
    /*
     // point1 top-left
     point1.r = pixels[index*4];
     point1.g = pixels[index*4+1];
     point1.b = pixels[index*4+2];
     point1.a = pixels[index*4+3]; // alpha
     //    ofSetColor(point1);
     // point2 top-right
     point2.r = pixels[x1 + w + y1 * w];
     point2.g = pixels[x1 + w + y1 * w + 1];
     point2.b = pixels[x1 + w + y1 * w + 2];
     //    ofSetColor(point2);
     // point3 buttom-left
     point3.r = pixels[x1 + (y1 + h) * w];
     point3.g = pixels[x1 + (y1 + h) * w + 1];
     point3.b = pixels[x1 + (y1 + h) * w + 2];
     //    ofSetColor(point3);
     // point4 buttom-right
     point4.r = pixels[x1 + w + (y1 + h) * w];
     point4.g = pixels[x1 + w + (y1 + h) * w + 1];
     point4.b = pixels[x1 + w + (y1 + h) * w + 2];
     //    ofSetColor(point4);
     // point5 center
     point5.r = pixels[x1 + w/2 + (y1 + h/2) * w];
     point5.g = pixels[x1 + w/2 + (y1 + h/2) * w + 1];
     point5.b = pixels[x1 + w/2 + (y1 + h/2) * w + 2];
     //    ofSetColor(point5);
     
     
     std::printf("color R : %d, color G : %d, color B : %d, color A : %d\n", point1.r, point1.g, point1.b, point1.a);
     
     std::printf("pixels : %zu\n", screenshot.getPixels().size());
     //    std::printf("rectIndex : %i\n", x1*y1*4);
     ///////////////////////////////////////////
     */
    
    
    
    
    
    
    imageShow = !imageShow;
    //    std::printf("imageShow : %s\n", x ? "true" : "false");
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
