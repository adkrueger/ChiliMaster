/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"
#include <iostream>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	
	
	if (wnd.kbd.KeyIsPressed(VK_UP)) {
		if (inhibitUp) {

		}
		else {
			vy -= 1;
			inhibitUp = true;
		}
	}
	else {
		inhibitUp = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		if (inhibitDown) {

		}
		else {
			vy += 1;
			inhibitDown = true;
		}
	}
	else {
		inhibitDown = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		if (inhibitLeft) {

		}
		else {
			vx -= 1;
			inhibitLeft = true;
		}
	}
	else {
		inhibitLeft = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		if (inhibitRight) {

		}
		else {
			vx += 1;
			inhibitRight = true;
		}
	}
	else {
		inhibitRight = false;
	}

	x += vx;
	y += vy;

	if (x <= 3) {
		x = 3;
		vx = 0; // do this velocity step after the "setting position" step
	}
	if (x >= 796 ) {
		x = 796;
		vx = 0;
	}
	if (y <= 3) {
		y = 3;
		vy = 0;
	}
	if (y >= 596) {
		y = 596;
		vy = 0;
	}

	
}

void Game::ComposeFrame()
{
	// talk about const, semicolon, int, whatever
	// talk about white space not mattering
	// these won't be commented out 'til later
	// int x = 400;
	// int y = 300;

	// boolean condition
	// bool and boolean are aliases for the same thing:
	//    https://www.tutorialspoint.com/cplusplus/cpp_data_types.htm
	//    data point discussion
	// talk about wnd and kbd both being objects (objects inside objects)
	// VK = virtual key, also have VK_SPACE/SHIFT/ENTER/ESCAPE/UP/DOWN etc
	// Ctrl+Click VK_% to see definition
	const bool cond = wnd.kbd.KeyIsPressed(VK_SHIFT);
	const bool otherCond = wnd.kbd.KeyIsPressed(VK_SPACE);

	// next challenge
	// talk about why it doesn't stay up or down or move around
	// discuss animation, frames etc.
	// process input -> update game -> render to screen
	// use and talk about debugger
	// talk about scope; put stuff editing x before declaration of x, declare variables inside curly braces and try to edit outside
	// also declare a new y below, demonstrate changes (inner y is in its own scope, kind of covers up other y in that scope)
	// so, x and y are lost between frames. need to use classes!
	// discuss object-oriented languages, objects
	// a class is like a blueprint (not real) and objects are like houses built from the blueprint (the real thing)
	//    objects are instances of a class (generally create more objects in .h files, go to Game.h where class is defined)
	//    these header files tell you the members of the class, its behaviors, and data
	//    wnd is from this .h file
	//    this class has a gfx object representing the Graphics class
	// we still lose these x and y every time... how should we fix that?
	// move x and y into the game class in Game.h!
	//    now they'll live as long as the object lives
	/*if (wnd.kbd.KeyIsPressed(VK_UP)) {
		// set these to like 100 beforemoving x and y to class
		// also mention += verse blank = blank + whatever
		y -= 3;
	}
	/*else*//* if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		y += 3;
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		x -= 3;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		x += 3;
	}*/

	// conditional statement, talk about syntax and how it works
	// can also show how to KeyIsPressed (above) into cond
	if (cond) {
		// make plus sign
		// note input parameters, discuss each of them
		DrawPlus(x, y, 255, 255, 255);
	}
	else if (otherCond) {
		DrawPlus(x, y, 255, 0, 255);
	}
	else {
		DrawPlus(x, y, 0, 255, 255);
	}

	// check for collisions
	if (IsCollision(x, y, fixedX, fixedY)) {
		DrawPlus(fixedX, fixedY, 255, 0, 0);

		// need to add #include <iostream>, discuss including various files
		// discuss std:: vs. "using namespace std;" (latter lets you print without typing std::
		std::cout << "collide";
	}
	else {
		DrawPlus(fixedX, fixedY, 255, 255, 255);
	}
}


// double colon (scope resolution operator) says we want to declare a function in the Game class
void Game::DrawPlus(int x, int y, int r, int g, int b) {
	gfx.PutPixel(x - 3, y, r, g, b);
	gfx.PutPixel(x - 2, y, r, g, b);
	gfx.PutPixel(x - 1, y, r, g, b);
	gfx.PutPixel(x, y, r, g, b);
	gfx.PutPixel(x + 1, y, r, g, b);
	gfx.PutPixel(x + 2, y, r, g, b);
	gfx.PutPixel(x + 3, y, r, g, b);
	gfx.PutPixel(x, y - 3, r, g, b);
	gfx.PutPixel(x, y - 2, r, g, b);
	gfx.PutPixel(x, y - 1, r, g, b);
	gfx.PutPixel(x, y, r, g, b);
	gfx.PutPixel(x, y + 1, r, g, b);
	gfx.PutPixel(x, y + 2, r, g, b);
	gfx.PutPixel(x, y + 3, r, g, b);
}

bool Game::IsCollision(int x0, int y0, int x1, int y1) {

	/*
	do this first, then ask if other ways to solve
	if (x0 > x1 - 3 && x0 < x1 + 3) {
		// discuss various operators, i.e. || and truth tables
		if (y0 > y1 - 3 && y0 < y1 + 3) {
			return true;
		}
	}
	else { // ask if we need this else here
		return false;
	}

	// discuss &&
	if ((x0 > x1 - 3 && x0 < x1 + 3) && (y0 > y1 - 3 && y0 < y1 + 3)) {
		return true;
	}
	*/

	// lastly, discuss how this works and how you can return a straight up bool
	return (x0 > x1 - 3 && x0 < x1 + 3) && (y0 > y1 - 3 && y0 < y1 + 3);
}
