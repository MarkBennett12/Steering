#include "agent.h"

agent::agent()
{
	position.x = 0.0f;
	position.y = 0.0f;
	velocity.x = 0.0f;
	velocity.y = 0.0f;
	orientation = 0.0f;
	angularVelocity = 0.0f;
	maxVelocity = 0.0f;
	arrivalDistance = 0.0f;
}

agent::agent(float initPosX, float initPosY, float initMaxVelocity, float initAngularVelocity, float initArrivalDistance)
{
	position.x = initPosX;
	position.y = initPosY;
	velocity.x = 0.0f;
	velocity.y = 0.0f;
	orientation = 0.0f;
	angularVelocity = initAngularVelocity;
	maxVelocity = initMaxVelocity;
	arrivalDistance = initArrivalDistance;
}

agent::agent(vector2 initPosition, float initMaxVelocity, float initAngularVelocity, float initArrivalDistance)
{
	position = initPosition;
	velocity.x = 0.0f;
	velocity.y = 0.0f;
	orientation = 0.0f;
	angularVelocity = initAngularVelocity;
	maxVelocity = initMaxVelocity;
	arrivalDistance = initArrivalDistance;
}

void agent::display()
{
	std::cout << "--agent data--" << std::endl;

	std::cout << "agent position x = " << position.x << std::endl;
	std::cout << "agent position y = " << position.y << std::endl;

	std::cout << "agent velocity x = " << velocity.x << std::endl;
	std::cout << "agent velocity y = " << velocity.y << std::endl;

	std::cout << "agent orientation x = " << orientation * 180 / 3.14 << std::endl;

	std::cout << std::endl;
}

void agent::orientate(vector2 direction, float deltaTime)
{
	// turn to face the steering direction, but only if we're moving
	if (magnitude(velocity) > 0)
	{
		// Calculate the change in angle to face the right way
		float deltaAngle = atan2(position.x - direction.x, position.y - direction.y) - orientation;

		// progressively turn toward that direction
		orientation += deltaAngle * angularVelocity * deltaTime;
	}
}

void agent::steer(vector2 direction, float deltaTime)
{
	// distance to target
	float distance = magnitude(direction);

	// turn towards our target
	orientate(direction, deltaTime);

	// Steer in the direction we're facing
	velocity.x = cos(orientation) * maxVelocity * deltaTime;
	velocity.y = sin(orientation) * maxVelocity * deltaTime;

	// Slow down as we get within arrival distance
	if (distance < arrivalDistance)
		velocity *= (distance / arrivalDistance);

	// now move
	position += velocity;
}

void agent::seek(vector2 target, float deltaTime)
{
	// difference between target and ai agent will steer towards target
	steer(target - position, deltaTime);
}

void agent::flee(vector2 from, float deltaTime)
{
	// difference between ai agent and target will steer away from target
	steer(position - from, deltaTime);
}
