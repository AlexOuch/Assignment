#include "Hero.h"



Hero::Hero()
{
}


Hero::~Hero()
{
}

void Hero::setAnimation(Animation* animation) {
	this->animation = animation;
}

//overriding
void Hero::update(float dt) {
	//face directoin based on velocity.x value
	if (velocity.x > 0)
		faceRight = true;
	else if(velocity.x < 0)
		faceRight = false;

	if (pos.x > 604)
		pos.x = 604;
	if (pos.x < 0)
		pos.x = 0;
	if (pos.y > 444)
		pos.y = 444;
	if (pos.y < 0)
		pos.y = 0;


	//use basic entity movement to move around
	updateMovement(dt);

	//update animations too
	animation->update(dt);
}
void Hero::draw() {
	if (animation != NULL) {
		if (faceRight)
			animation->draw(pos.x, pos.y);
		else
			animation->draw(pos.x, pos.y, true);

	}

}