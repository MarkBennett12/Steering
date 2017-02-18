#pragma once
#include <iostream>
#include <conio.h>
#include <math.h>
#include "vector.h"

/*
/// <summary>
/// stores all the data and functionality
/// required by the steering agent
/// </summary>
*/
class agent
{
private:
	vector2 position; // ai agents location in the world
	vector2 velocity; // ai agent current velocity
	float orientation; // current facing angle of the ai agent
	float angularVelocity; // maximum turning speed (radians per second)
	float maxVelocity; // maximum travel speed (meters per second)
	float arrivalDistance; // The distance at which we start to slow down

public:
	// constructors and public methods follow...

	/***********************************************************************************
	/// <summary>
	/// Default constructor
	/// </summary>
	***********************************************************************************/
	agent();

	/***********************************************************************************
	/// <summary>
	/// Constructor taking float x and float y as initial position paramter
	/// as well as the maximum velocity
	/// </summary>
	***********************************************************************************/
	agent(float initPosX, float initPosY, float initMaxVelocity, float initAngularVelocity, float initArrivalDistance);

	/***********************************************************************************
	/// <summary>
	/// Constructor taking vector2 as initial position paramter
	/// as well as the maximum velocity
	/// </summary>
	***********************************************************************************/
	agent(vector2 initPosition, float initMaxVelocity, float initAngularVelocity, float initArrivalDistance);

	/***********************************************************************************
	/// <summary>
	/// Return the agents position vector
	/// </summary>
	/// <returns>position vector as vector2</returns>
	***********************************************************************************/
	vector2 getPosition()
	{
		return position;
	}

	/***********************************************************************************
	/// <summary>
	/// Return the agents velocity vector
	/// </summary>
	/// <returns>velocity vector as vector2</returns>
	***********************************************************************************/
	vector2 getVelocity()
	{
		return velocity;
	}

	/***********************************************************************************
	/// <summary>
	/// Return the agents maximum velocity
	/// </summary>
	/// <returns>maximum velocity as float</returns>
	***********************************************************************************/
	float getMaxVelocity()
	{
		return maxVelocity;
	}

	/***********************************************************************************
	/// <summary>
	/// Return the agents maximum rotational velocity
	/// </summary>
	/// <returns>maximum rotational velocity as float</returns>
	***********************************************************************************/
	float getMaxRotationalVelocity()
	{
		return angularVelocity;
	}

	/***********************************************************************************
	/// <summary>
	/// Return the agents orientation in radians
	/// </summary>
	/// <returns>orientation as float</returns>
	***********************************************************************************/
	float getOrientation()
	{
		return orientation;
	}

	/***********************************************************************************
	/// <summary>
	/// Display the agents position, x and y, velocity, x and y and orientation in radians
	/// </summary>
	***********************************************************************************/
	void display();

	/***********************************************************************************
	/// <summary>
	/// Given a direction vector and a time step, calculates and applies the new
	/// facing angle for the ai agent
	/// </summary>
	///
	/// <param name="direction">vector2 direction : direction to face</param>
	/// <param name="deltaTime">float deltaTime :timestep</param>
	***********************************************************************************/
	void orientate(vector2 direction, float deltaTime);

	/***********************************************************************************
	/// <summary>
	/// Given a direction vector and a time step, calculates and applies
	/// the new position for the ai agent to move torwad the desired direction
	/// </summary>
	///
	/// <param name="direction">vector2 direction : direction to move towards</param>
	/// <param name="deltaTime">float deltaTime : timestep</param>
	***********************************************************************************/
	void steer(vector2 direction, float deltaTime);

	/***********************************************************************************
	/// <summary>
	/// Calculates a vector facing the target and steers toward it
	/// </summary>
	///
	/// <param name="target">vector2 target : location of target to move towards</param>
	/// <param name="deltaTime">float deltaTime : timestep</param>
	***********************************************************************************/
	void seek(vector2 target, float deltaTime);

	/***********************************************************************************
	/// <summary>
	/// Calculates a vector facing away from the target and steers toward it
	/// </summary>
	///
	/// <param name="from">vector2 from : location of point to move away from</param>
	/// <param name="deltaTime">float deltaTime : timestep</param>
	***********************************************************************************/
	void flee(vector2 from, float deltaTime);
};

