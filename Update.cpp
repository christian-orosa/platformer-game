#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>



using namespace sf;

void Engine::update(float dtAsSeconds)
{
	if (m_NewLevelRequired)
	{
		//// These calls to spawn will be moved to a new
		//// LoadLevel function soon
		//// Spawn Thomas and Bob
		//m_Thomas.spawn(Vector2f(0, 0), GRAVITY);


		//// Make sure spawn is called only once
		//m_TimeRemaining = 10;
		//m_NewLevelRequired = false;





		//load a level
		loadLevel();


	}


	// Update Thomas
	m_Thomas.update(dtAsSeconds);
	
	if (detectCollisions(m_Thomas))
	{
		m_NewLevelRequired = true;
	}

	// Update Bob


	// Count down the time the player has left
	m_TimeRemaining -= dtAsSeconds;

	// Have Thomas and Bob run out of time?
	if (m_TimeRemaining <= 0)
	{
		m_NewLevelRequired = true;
	}

	// Set the appropriate view around the appropriate character

		// Centre full screen around appropriate character
	if (cameraLookAtCenterOfPlayer)
	{
		m_MainView.setCenter(m_Thomas.getCenter());
	}


}