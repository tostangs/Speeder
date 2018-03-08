//============================================================================
// Name        : Speeder Game
// Author      : Not me haha
// Version     : idk honestly
// Copyright   : Your copyright notice
// Description : Three dots for depression, the game for the excitement... ;)
//============================================================================

#include "stdafx.h"	
#include "olcConsoleGameEngine.h"
#include <string>


class Speeder : public olcConsoleGameEngine
{
private:
	// Variables related to the movement of the player
	float sYPosition = ScreenHeight() / 2.0f;
	float sXPosition = ScreenWidth() / 3.0f;
	float sVelocity = 0.0f;
	float sAcceleration = 0.0f;

	// Variables related to the level and obstacles
	float lSectionWidth;
	list<int> enmyListSection;
	float lLevelPosition = 0.0f;
	float lSpeed = 1.0f;

	// Variables related to the interactions between the player and the level
	int nLives = 3;
	int nRound = 0;
	bool gameEnded = false;
	float enmyDist;
	
	// Variables related to the interactions between the player and the obstacles
	bool hasCollided = false;
	int nObstaclesKilled = 0;

protected:

	virtual bool OnUserCreate()
	{
		enmyListSection = { 0, 0, 0, 0 };
		lSectionWidth = (float)ScreenWidth() / (float)(enmyListSection.size() - 1);

		return true;
	}

	virtual bool OnUserUpdate(float sElapsedTime) 
	{
		if (gameEnded)
		{
			gameEnded = false;
			enmyListSection = { 0, 0, 0, 0 };
			hasCollided = false;
			sXPosition = ScreenHeight() / 2.0f;
			sVelocity = 0.0f;
			sAcceleration = 0.0f;
		}

		if (hasCollided)
		{
			if (m_keys[VK_SPACE].bReleased)
				gameEnded = true;
		}
		else {

			// Making the proper actions based on the keys pressed
			if (m_keys[VK_UP].bHeld || m_keys[0x57].bHeld)
			{
				// Vehicle y positon rising
				sYPosition -= 0.06f;
			}
			if (m_keys[VK_DOWN].bHeld || m_keys[0x53].bHeld)
			{
				// Vehicle y position falling
				sYPosition += 0.06f;
			}
			if (m_keys[VK_RIGHT].bHeld || m_keys[0x44].bHeld)
			{
				// Vehicle x position increasing
				sXPosition += 0.08f;

			}
			if (m_keys[VK_LEFT].bHeld || m_keys[0x41].bHeld)
			{
				// Vehicle x positon decreasing
				sXPosition -= 0.08f;
			}

			// Filling the screen
			Fill(0, 0, ScreenWidth(), ScreenHeight(), L' ');

			int nSection = 0;
			for (auto e : enmyListSection)
			{
				if (e != 0)
				{

				}
			}

			// Creating the Screen barriers
			if (sXPosition + 7 > ScreenWidth())
				sXPosition = ScreenWidth() - 8;
			if (sXPosition < 0)
				sXPosition = 0;
			if (sYPosition + 1 > ScreenHeight())
				sYPosition = ScreenHeight() - 2;
			if (sYPosition < 0)
				sYPosition = 0;

			// Printing the speeder vehicle
			DrawString(sXPosition, sYPosition, L":   \\", FG_CYAN);
			DrawString(sXPosition, sYPosition + 1, L"L==--\\>", FG_CYAN);

		}
		return true;

	}

};

int main() {
	
	Speeder game;
	game.ConstructConsole(200, 60, 8, 8);
	game.Start();

	return 0;
}