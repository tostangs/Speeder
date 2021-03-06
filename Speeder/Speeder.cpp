//============================================================================
// Name        : Speeder Game
// Author      : Not me haha
// Version     : idk honestly
// Copyright   : Your copyright notice
// Description : Three dots for depression, the game for the excitement... ;)
//============================================================================

#include "stdafx.h"	
#include "olcConsoleGameEngine.h"
#include <conio.h>
#include <string>


class Speeder : public olcConsoleGameEngine
{
private:
	// Variables related to the movement of the player
	float sYPosition = ScreenHeight() / 2.0f;
	float sXPosition = ScreenWidth() / 3.0f;
	float sVelocity = 0.0f;
	float sAcceleration = 10.0f;

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
			sXPosition = ScreenWidth() / 2.0f;
			sVelocity = 0.0f;
			sAcceleration = 10.0f;
		}

		if (hasCollided)
		{
			if (m_keys[VK_SPACE].bReleased)
				gameEnded = true;
		}
		else {

			if (m_keys[VK_UP].bHeld || m_keys[VK_DOWN].bHeld || m_keys[VK_RIGHT].bHeld || m_keys[VK_LEFT].bHeld || m_keys[0x57].bHeld || m_keys[0x53].bHeld || m_keys[0x44].bHeld || m_keys[0x41].bHeld)
			{
				sAcceleration = 1.0f;

				// Making the proper actions based on the keys pressed
				if (m_keys[VK_UP].bHeld || m_keys[0x57].bHeld)
				{
					// Vehicle y positon rising
					sVelocity += -(sElapsedTime * sAcceleration);
					sYPosition += (sElapsedTime * sVelocity);
				}
				if (m_keys[VK_DOWN].bHeld || m_keys[0x53].bHeld)
				{
					// Vehicle y position falling
					sVelocity += (sElapsedTime * sAcceleration);
					sYPosition += (sElapsedTime * sVelocity);
				}
				if (m_keys[VK_RIGHT].bHeld || m_keys[0x44].bHeld)
				{
					// Vehicle x position increasing
					sVelocity += (sElapsedTime * sAcceleration);
					sXPosition += (sElapsedTime * sVelocity);

				}
				if (m_keys[VK_LEFT].bHeld || m_keys[0x41].bHeld)
				{
					// Vehicle x positon decreasing
					sVelocity += -(sElapsedTime * sAcceleration);
					sXPosition += (sElapsedTime * sVelocity);
				}
			}
			else
			{
				sAcceleration = 0.0f;
				sVelocity += (sElapsedTime * sAcceleration);
				sXPosition += (sElapsedTime * sVelocity);
				sYPosition += (sElapsedTime * sVelocity);
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
			{
				sAcceleration = 0.0f;
				sXPosition = ScreenWidth() - 8;
			}
			if (sXPosition < 0)
			{
				sAcceleration = 0.0f;
				sXPosition = 0;
			}
			if (sYPosition + 1 > ScreenHeight())
			{
				sAcceleration = 0.0f;
				sYPosition = ScreenHeight() - 2;
			}
			if (sYPosition < 0)
			{
				sAcceleration = 0.0f;
				sYPosition = 0;
			}

			// Printing the speeder vehicle
			DrawString(sXPosition, sYPosition, L":   \\", FG_CYAN);
			DrawString(sXPosition, sYPosition + 1, L"L==--\\>", FG_CYAN);

		}
		return true;

	}

};

class Player {

private:
	float xPos, yPos;
	float pXVel, pYVel, pXAccel = 10.0f, pYAccel = 10.0f;

	
protected:

	void accel(float &vel, float &acc, float &dir, float elTime)
	{
		// Kinematic equation for change in position at an instance of time
		dir += (vel * elTime) + (.5 * acc * (elTime * elTime));
	}

};


int main() {
	
	Speeder game;
	game.ConstructConsole(200, 60, 8, 8);
	game.Start();

	return 0;
}