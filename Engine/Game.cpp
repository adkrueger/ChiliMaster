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
		/*
		gfx.PutPixel(397, 300, 255, 255, 255);
		gfx.PutPixel(398, 300, 255, 255, 255);
		gfx.PutPixel(399, 300, 255, 255, 255);
		gfx.PutPixel(400, 300, 255, 255, 255);
		gfx.PutPixel(401, 300, 255, 255, 255);
		gfx.PutPixel(402, 300, 255, 255, 255);
		gfx.PutPixel(403, 300, 255, 255, 255);
		gfx.PutPixel(400, 297, 255, 255, 255);
		gfx.PutPixel(400, 298, 255, 255, 255);
		gfx.PutPixel(400, 299, 255, 255, 255);
		gfx.PutPixel(400, 300, 255, 255, 255);
		gfx.PutPixel(400, 301, 255, 255, 255);
		gfx.PutPixel(400, 302, 255, 255, 255);
		gfx.PutPixel(400, 303, 255, 255, 255);
		*/
		gfx.PutPixel(x - 3, y, 255, 255, 255);
		gfx.PutPixel(x - 2, y, 255, 255, 255);
		gfx.PutPixel(x - 1, y, 255, 255, 255);
		gfx.PutPixel(x, y, 255, 255, 255);
		gfx.PutPixel(x + 1, y, 255, 255, 255);
		gfx.PutPixel(x + 2, y, 255, 255, 255);
		gfx.PutPixel(x + 3, y, 255, 255, 255);
		gfx.PutPixel(x, y - 3, 255, 255, 255);
		gfx.PutPixel(x, y - 2, 255, 255, 255);
		gfx.PutPixel(x, y - 1, 255, 255, 255);
		gfx.PutPixel(x, y, 255, 255, 255);
		gfx.PutPixel(x, y + 1, 255, 255, 255);
		gfx.PutPixel(x, y + 2, 255, 255, 255);
		gfx.PutPixel(x, y + 3, 255, 255, 255);
	}
	else if (otherCond) {
		gfx.PutPixel(x - 3, y, 255, 0, 255);
		gfx.PutPixel(x - 2, y, 255, 0, 255);
		gfx.PutPixel(x - 1, y, 255, 0, 255);
		gfx.PutPixel(x, y, 255, 0, 255);
		gfx.PutPixel(x + 1, y, 255, 0, 255);
		gfx.PutPixel(x + 2, y, 255, 0, 255);
		gfx.PutPixel(x + 3, y, 255, 0, 255);
		gfx.PutPixel(x, y - 3, 255, 0, 255);
		gfx.PutPixel(x, y - 2, 255, 0, 255);
		gfx.PutPixel(x, y - 1, 255, 0, 255);
		gfx.PutPixel(x, y, 255, 0, 255);
		gfx.PutPixel(x, y + 1, 255, 0, 255);
		gfx.PutPixel(x, y + 2, 255, 0, 255);
		gfx.PutPixel(x, y + 3, 255, 0, 255);
	}
	else {
		gfx.PutPixel(x - 3, y, 0, 255, 255);
		gfx.PutPixel(x - 2, y, 0, 255, 255);
		gfx.PutPixel(x - 1, y, 0, 255, 255);
		gfx.PutPixel(x, y, 0, 255, 255);
		gfx.PutPixel(x + 1, y, 0, 255, 255);
		gfx.PutPixel(x + 2, y, 0, 255, 255);
		gfx.PutPixel(x + 3, y, 0, 255, 255);
		gfx.PutPixel(x, y - 3, 0, 255, 255);
		gfx.PutPixel(x, y - 2, 0, 255, 255);
		gfx.PutPixel(x, y - 1, 0, 255, 255);
		gfx.PutPixel(x, y, 0, 255, 255);
		gfx.PutPixel(x, y + 1, 0, 255, 255);
		gfx.PutPixel(x, y + 2, 0, 255, 255);
		gfx.PutPixel(x, y + 3, 0, 255, 255);
	}

}
