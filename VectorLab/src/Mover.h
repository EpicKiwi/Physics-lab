#pragma once
#include "ofMath.h"
#include "ofGraphics.h"
#include "ofApp.h"

class Mover
{
public:
	Mover();
	~Mover();
	
	void update();
	void display();
	void applyForce(const ofVec2f & force);

	void setPosition(float x, float y);
	void setVelocity(float x, float y);
	void setAcceleration(float x, float y);
	ofVec2f getPosition();
	ofVec2f getVelocity();
	ofVec2f getAcceleration();
	int& getMass();
	void setMass(const int& mass);
	float& getFrictionCoefficient();
	void setFrictionCoefficient(const float& coef);

private:
	ofVec2f position;
	ofVec2f velocity;
	ofVec2f acceleration;
	int mass = 25;
	float frictionCoefficient = 0.3;
};

