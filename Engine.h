#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Thomas.h"
#include "LevelManager.h"

using namespace sf;

class Engine
{
private:
	// The texture holder
	TextureHolder th;

	// Thomas and his friend, Bob
	Thomas m_Thomas;
	


	//A class to manage all the levels
	LevelManager m_LM;

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;

	// The force pushing the characters down
	const int GRAVITY = 300;

	// A regular RenderWindow
	RenderWindow m_Window;

	// The main Views
	View m_MainView;
	View m_LeftView;
	View m_RightView;

	// Three views for the background
	View m_BGMainView;
	View m_BGLeftView;
	View m_BGRightView;

	View m_HudView;

	// Declare a sprite and a Texture for the background
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

	// Is the game currently playing?
	

	// Is character 1 or 2 the current focus?
	bool cameraLookAtCenterOfPlayer = true;

	// Start in full screen mode
	

	// How much time is left in the current level
	float m_TimeRemaining = 10;
	Time m_GameTimeTotal;

	// Is it time for a new/first level?
	bool m_NewLevelRequired = true;
	

	VertexArray m_VALevel;

	int** m_ArrayLevel = NULL;

	Texture m_TextureTiles;


	// Private functions for internal use only
	void input();
	void update(float dtAsSeconds);
	void draw();	

	//Load a new Level
	void loadLevel();

	bool detectCollisions(PlayableCharacter& character);
	
public:
	// The Engine constructor
	Engine();

	// Run will call all the private functions
	void run();

};
