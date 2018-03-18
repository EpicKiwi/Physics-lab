#include "ofApp.h"

vector<Mover> balls;

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);

	for (int i = 0; i < 1; i++) {
		Mover ball;
		ball.setMass(ofRandom(5, 35));
		ball.setPosition(ofRandom(ball.getMass(),ofGetWindowWidth() - ball.getMass()), ofRandom(ball.getMass(), 100));
		balls.push_back(ball);
	}
}

//--------------------------------------------------------------
void ofApp::update(){

	ofVec2f gravity(0, 0.3);
	ofVec2f wind(0.2, 0);

	for (Mover &ball : balls) {

		ball.setAcceleration(0, 0);
		ball.applyForce(gravity);

		if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {
			ball.applyForce(wind);
		}

		ball.update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
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