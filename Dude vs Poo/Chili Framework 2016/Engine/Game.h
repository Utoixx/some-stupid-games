/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include <vector>
#include "Dude.h"
#include "Poo.h"
#include <random>
#include "Rect.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
	void UpdateDude();
	void DrawTitle(unsigned int x, unsigned int y);
	void DrawGameOver(unsigned int x, unsigned int y);
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	/********************************/
	Color colorRed = Color(255, 0, 0);
	Color colorGreen = Color(0, 255, 0);
	Color colorWhite = Color(255, 255, 255);
	bool started = false;
	bool gameOver = false;
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen; // seed the generator
	std::uniform_int_distribution<int> distrX; // define the range
	std::uniform_int_distribution<int> distrY; // define the range
	std::uniform_int_distribution<int> distrBool;
	Dude dude;
	Rect scoreBar;
	Rect object;
	Poo poo[5];
	int score = 0;
};