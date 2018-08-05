#include "ofApp.h"

#include "Area.h"
#include "Pt.h"
#include "Rect.h"
#include "ctrlVector.h"


void ofApp::setup(){
	srand(time(NULL));

	vecIniRect.clear();
	vecOutRect.clear();
	vecParentVec.clear();
	
	/* ONE RECT ONLY */
	//int U = 2; int V = 1;

	/* MULTIPLE RECTS */
	int U = 3; int V = 2;
	
	for (unsigned int i = 300; i < 300 * U; i += 325) {
		for (unsigned int j = 0; j < 300 * V; j += 325) {
			a = Pt(50 + i, 50 + j);
			b = Pt(a.x + 300, a.y);
			c = Pt(a.x + 300, b.y + 150);
			d = Pt(a.x, c.y);
			/* AREA */
			float totalArea = ar.getTotalAr();
			ar.initSubdiv();
			ar.constructGraph();
			ar.displayGraph();
			cout << "\n------------------------------\n" << std::endl;

			//ar.displayGraph();
			vector<Parent> parentVec; parentVec.clear();
			parentVec = ar.getParentVec();
			//vecParentVec.push_back(parentVec);
			
			/* CONTROL */
			ctrlVector cv; // control vector
			vector<int> cvV;// initialize the control vector
			cvV.clear(); // clear the control vector
			cvV = cv.newIntVector(NUM);

			/* RECTANGLE */
			Rect R0; // Initialize the rectangle
			Rect r=R0.genIniRect(a, 1, 2, totalArea); // setup the initial rectangle
			r.setParentVec(parentVec); // set the area tree to the rect
			r.setIntVector(cvV); // generate & set control vector to Rect
			vecIniRect.push_back(r); //make a vector of initial rectangles
			vecBoundaryRect.push_back(r);
			r.clrState();
			r.subdivide(r, 0, 0, parentVec[0]); // construct the vectors of rects from initial rect

			vector<Rect> rv;
			rv.clear();
			rv = r.getRectVector();// get the vector of output vectors
			vecOutRect.push_back(rv); // vector of output vectors from subdivision of initial rectangles
		}
	}
}

void ofApp::update(){
	
}

void ofApp::draw(){
	ofBackground(255, 255, 255);
	for (int i = 0; i < vecBoundaryRect.size(); i++) {
		Rect R = vecBoundaryRect[i];
		vecBoundaryRect[i].drawRect(3);
	}
	for (int i = 0; i < vecOutRect.size(); i++) {
		for (int j = 0; j < vecOutRect[i].size(); j++) {
			Rect p= vecOutRect[i][j];
			p.drawRect();
			Pt m = p.getCen(); float ar = p.getCoordArea();
			ofSetColor(0, 0, 0);
			ofDrawBitmapString(ar, m.x-10, m.y);
		}
	}
}

void ofApp::keyPressed(int key){

}

void ofApp::keyReleased(int key){

}

void ofApp::mouseMoved(int x, int y ){

}

void ofApp::mouseDragged(int x, int y, int button){

}

void ofApp::mousePressed(int x, int y, int button){
	setup();
}

void ofApp::mouseReleased(int x, int y, int button){

}

void ofApp::mouseEntered(int x, int y){

}

void ofApp::mouseExited(int x, int y){

}

void ofApp::windowResized(int w, int h){

}

void ofApp::gotMessage(ofMessage msg){

}

void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
