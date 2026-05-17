#include "Thomas.h"
#include "TextureHolder.h"

Thomas::Thomas()
{
	// Associate a texture with the sprite
	sf::IntRect rectsourceSprite(0, 54, 31, 51);

	m_Sprite = Sprite(TextureHolder::GetTexture("graphics/playersheet.png"), rectsourceSprite);


	m_JumpDuration = .45;
}

// A virtual function
bool Thomas::handleInput()
{



	m_JustJumped = false;

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		m_Sprite.setTextureRect(IntRect(31 * frame, 159 * row, 31, 54));

		if (frameCounter == 60)
		{
			frame = (frame + 1) % 3;
			frameCounter = 0;
		}
		frameCounter++;


		// Start a jump if not already jumping
		// but only if standing on a block (not falling)
		if (!m_IsJumping && !m_IsFalling)
		{
			m_IsJumping = true;
			m_TimeThisJump = 0;
			m_JustJumped = true;
		}
	}
	else
	{
		m_IsJumping = false;
		m_IsFalling = true;
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		m_Sprite.setTextureRect(IntRect(31 * frame, 51 * row, 31, 54));

		if (frameCounter == 60)
		{
			frame = (frame + 1) % 3;
			frameCounter = 0;
		}
		frameCounter++;

		m_LeftPressed = true;
	}
	else
	{		
		m_LeftPressed = false;
	}


	if (Keyboard::isKeyPressed(Keyboard::D))
	{

		m_Sprite.setTextureRect(IntRect(31 * frame, 102 * row, 31, 54));

		if (frameCounter == 60)
		{
			frame = (frame + 1) % 3;
			frameCounter = 0;
		}
		frameCounter++;

		m_RightPressed = true;
	}
	else
	{
		m_RightPressed = false;
	}

	return m_JustJumped;
}