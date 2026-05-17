#pragma once
#include "PlayableCharacter.h"

class Thomas : public PlayableCharacter
{
public:
	// A constructor specific to Thomas
	Thomas();

	//Frame animation for Thomas
	int frame = 0;
	int row = 1;
	int frameCounter = 0;

	sf::IntRect rectsourceSprite;
	sf::Clock clock;

	// The overriden input handler for Thomas
	bool virtual handleInput();

};
