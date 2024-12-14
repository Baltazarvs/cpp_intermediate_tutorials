// Created 2024 Baltazarus
// This example demonstrates game loop with controled termination.
// This is disgrace for a game so is not recommended to have fun with.

#include <iostream>
#include <ctime>
#include <windows.h>
#include <thread>

#if !defined(WIN32) || !defined(_WIN32)
	#error "This stupid game is only playable on Windows."
#endif

bool bRunning = true;
bool bPointAlive = true;
unsigned int score = 0;
int charPosX = 0, charPosY = 0;
int pointPosX = 0, pointPosY = 0;

int main()
{
	srand(time(nullptr));
	pointPosX = rand() % 38;
	pointPosY = rand() % 23;

	std::cout << "BrainFck Game 2024 by Baltazarus.\n";
	std::cout << "This code is part of cpp_intermediate_tutorials repo." << std::endl;
	
	std::cout << std::endl << "Move: < ^ > V\nExit: X" << std::endl;

	char choice = 0;
	std::cout << std::endl << "Start the game? (y/n) " << std::endl;
	std::cin >> choice;
	if(choice != 'y')
		return 0;

	int ci = 0;
	while(bRunning)
	{
		if(!bPointAlive)
		{
			pointPosX = rand() % 38;
			pointPosY = rand() % 23;
			bPointAlive = true;
		}

		for(int i = 0; i < 25; ++i)
		{
			for(int j = 0; j < 40; ++j)
		        {
				if(i == 0 || i == 24 || j == 0 || j == 39)
				{
					std::cout << "#";
					continue;
				}
				if(charPosX + 1 == j && charPosY + 1 == i)
					std::cout << '@';
				else if(pointPosX + 1 == j && pointPosY + 1 == i)
					std::cout << '$';
				else
					std::cout << '.';
			}
			std::cout << std::endl;
		}

		if(GetAsyncKeyState(VK_LEFT) & 0x8000)
			if(charPosX > 0)
				charPosX -= 1;
		if(GetAsyncKeyState(VK_RIGHT) & 0x8000)
			if(charPosX < 39 - 2)
				charPosX += 1;
		if(GetAsyncKeyState(VK_UP) & 0x8000)
			if(charPosY > 0)
				charPosY -= 1;
		if(GetAsyncKeyState(VK_DOWN) & 0x8000)
			if(charPosY < 24 - 2)
				charPosY += 1;
		if(GetAsyncKeyState('X') & 0x8000)
			bRunning = false;
		
		// If player collides with point...
		if(charPosX == pointPosX && charPosY == pointPosY)
		{
			score += 100;
			bPointAlive = false;
		}

		std::cout << "Score: " << ::score << std::endl;
		std::cout << "Cycles: " << ci << std::endl;
		std::cout << '(' << pointPosX << ',' << pointPosY << ')' << std::endl;
		system("cls");

		if(ci >= 1e5)
			bRunning = false;
		ci += 1;
	}
	return 0;
}
