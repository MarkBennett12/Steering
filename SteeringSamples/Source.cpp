#include <iostream>
#include <conio.h>
#include <math.h>
#include "vector.h"

using namespace std;

// escape key
const char ESC = 27;

/*
	stores all the data and functionality 
	required by the steering agent
*/
struct agent
{
	vector2 position; // ai agents location in the world
	vector2 velocity; // ai agent current velocity
	float orientation; // current facing angle of the ai agent
	float angularVelocity; // maximum turning speed (radians per second)
	float maxVelocity; // maximum travel speed (meters per second)

	// constructors and methods follow...

	agent()
	{
		position.x = 0.0f;
		position.y = 0.0f;
		velocity.x = 0.0f;
		velocity.y = 0.0f;
		orientation = 0.0f;
		angularVelocity = 0.0f;
		maxVelocity = 0.0f;
	}

	agent(float initPosX, float initPosY, float initMaxVelocity)
	{
		position.x = initPosX;
		position.y = initPosY;
		velocity.x = 0.0f;
		velocity.y = 0.0f;
		orientation = 0.0f;
		angularVelocity = 4.0f;
		maxVelocity = initMaxVelocity;
	}

	void display()
	{
		cout << "--agent data--" << endl;

		cout << "agent position x = " << position.x << endl;
		cout << "agent position y = " << position.y << endl;

		cout << "agent velocity x = " << velocity.x << endl;
		cout << "agent velocity y = " << velocity.y << endl;

		cout << "agent orientation x = " << orientation * 180 / 3.14 << endl;

		cout << endl;
	}

	/***********************************************************************************
	Given a direction vector and a time step, calculates and applies the new
	facing angle for the ai agent

	- vector2 direction : direction to face
	- float deltaTime :timestep
	***********************************************************************************/
	void orientate(vector2 direction, float deltaTime)
	{
		// turn to face the steering direction, but only if we're moving
		if (magnitude(velocity) > 0)
		{
			// Calculate the change in angle to face the right way
			float deltaAngle = atan2(-direction.x, direction.y) - orientation;

			// progressively turn toward that direction
			orientation += deltaAngle * angularVelocity * deltaTime;
		}
	}

	/***********************************************************************************
	Given a direction vector and a time step, calculates and applies
	the new position for the ai agent to move torwad the desired direction

	- vector2 direction : direction to move towards
	- float deltaTime : timestep
	***********************************************************************************/
	void steer(vector2 direction, float deltaTime)
	{
		// the direction and speed to the destination
		velocity = normalise(direction);

		// turn towards our target
		orientate(velocity, deltaTime);

		// go at full speed
		velocity *= maxVelocity;

		// now move
		position += velocity * deltaTime;
	}

	/*
	Calculates a vector facing the target and steers toward it

	- vector2 direction : direction to move towards
	- float deltaTime : timestep
	*/
	void seek(vector2 destination, float deltaTime)
	{
		// difference between target and ai agent will steer towards target
		steer(destination - position, deltaTime);
	}

	/*
	Calculates a vector facing away from the target and steers toward it

	- vector2 direction : direction to move towards
	- float deltaTime : timestep
	*/
	void flee(vector2 destination, float deltaTime)
	{
		// difference between ai agent and target will steer away from target
		steer(position - destination, deltaTime);
	}
};

void display(float dt, vector2 start, vector2 target, agent ai)
{
	system("cls");

	cout << "-----Update----" << endl;

	cout << "tick " << dt << endl << endl;

	cout << "distance from start: " << magnitude(ai.position - start) << endl;
	cout << "distance from destination: " << magnitude(ai.position - target) << endl;
	cout << "current position: <" << ai.position.x << ", " << ai.position.y << ">" << endl;
	cout << "current velocity: " << magnitude(ai.velocity) << endl;

	cout << endl;

	ai.display();

	cout << endl;
}

int main()
{
	vector2 startPosition(5.00f, 5.00f);
	vector2 target(10.0f, 10.0f);

	// we'll assume a frame rate of 60 fps
	// therefore deltaTime equals 1 second divided by 60
	float deltaTime = 0.016f;

	agent aiAgent(startPosition.x, startPosition.y, 2.0f);

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