#include <iostream>
#include <conio.h>
#include <math.h>
#include "agent.h"

// escape key
const char ESC = 27;

void display(float dt, vector2 start, vector2 target, agent ai)
{
	system("cls");

	std::cout << "-----Update----" << std::endl;

	std::cout << "tick " << dt << std::endl << std::endl;

	std::cout << "distance from start: " << magnitude(ai.getPosition() - start) << std::endl;
	std::cout << "distance from destination: " << magnitude(ai.getPosition() - target) << std::endl;
	std::cout << "angle to destination" << atan2(-target.x, target.y) - ai.getOrientation() << std::endl;

	std::cout << std::endl;

	ai.display();

	std::cout << std::endl;
}

int main()
{
	vector2 startPosition(5.00f, 5.00f);
	vector2 target(10.0f, 10.0f);

	// we'll assume a frame rate of 60 fps
	// therefore deltaTime equals 1 second divided by 60
	float deltaTime = 0.016f;

	agent aiAgent(startPosition, 2.0f, 1.0f, 2.0f);

	// Escape to exit
	char userInput = ESC;
	do
	{
		display(deltaTime, startPosition, target, aiAgent);

		aiAgent.seek(target, deltaTime);

		userInput = _getch();

	} while (userInput != ESC);

	return 0;
}