#include "ofApp.h"

vector<Mover> balls;
ofVec2f windDirection;

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){

	ofVec2f gravity(0, 0.3);

	for (Mover &ball : balls) {

		ofVec2f gravityForce = gravity * ball.getMass();

		ball.setAcceleration(0, 0);
		ball.applyForce(gravityForce);

		if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {
			ofVec2f center(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
			ofVec2f mouse(ofGetMouseX(), ofGetMouseY());
			windDirection = mouse - center;
			windDirection.normalize();
			windDirection *= 2;
			ball.applyForce(windDirection);
		}

		ball.update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);

	if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {
		ofSetColor(255);
		ofVec2f center(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
		ofDrawArrow(center, center + windDirection * 50, 10);
	}

	for (Mover ball : balls) {
		ball.display();
	}
}

void ofApp::mousePressed(int x, int y, int button) {

	if (button == OF_MOUSE_BUTTON_RIGHT) {
		Mover newBall;
		newBall.setPosition(x, y);
		newBall.setMass(ofRandom(5, 35));
		balls.push_back(newBall);
	}

}