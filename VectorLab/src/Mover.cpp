#include "Mover.h"

Mover::Mover()
{
}


Mover::~Mover()
{
}

void Mover::update()
{
	this->velocity += this->acceleration;
	this->position += this->velocity;
	if (this->position.x + this->mass > ofGetWindowWidth() || this->position.x - this->mass < 0) {
		if (this->position.x + this->mass > ofGetWindowWidth())
			this->position.x = ofGetWindowWidth() - this->mass;
		else
			this->position.x = this->mass;
		this->velocity.x *= -1;
	}
	if (this->position.y + this->mass > ofGetWindowHeight() || this->position.y - this->mass < 0) {
		if (this->position.y + this->mass > ofGetWindowHeight())
			this->position.y = ofGetWindowHeight() - this->mass;
		else
			this->position.y = this->mass;
		this->velocity.y *= -1;
	}
}

void Mover::display()
{
	ofColor immobile(255, 255, 255);
	ofColor maximum(255, 0, 0);
	ofSetColor(immobile.lerp(maximum,ofMap(this->velocity.length(),0,200,0,1,true)));
	ofDrawCircle(this->position, this->mass);
}

void Mover::applyForce(const ofVec2f & force)
{
	this->acceleration += force / this->mass;
}

void Mover::setPosition(float x, float y)
{
	this->position.x = x;
	this->position.y = y;
}

void Mover::setVelocity(float x, float y)
{
	this->velocity.x = x;
	this->velocity.y = y;
}

void Mover::setAcceleration(float x, float y)
{
	this->acceleration.x = x;
	this->acceleration.y = y;
}

ofVec2f Mover::getPosition()
{
	return this->position;
}

ofVec2f Mover::getVelocity()
{
	return this->velocity;
}

ofVec2f Mover::getAcceleration()
{
	return this->acceleration;
}

int& Mover::getMass()
{
	return this->mass;
}

void Mover::setMass(const int & mass)
{
	this->mass = mass;
}
