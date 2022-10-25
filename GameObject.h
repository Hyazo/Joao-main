#pragma once
#include "SDL.h"
#include "Texture.h"
#include "Vector2.h"
#include "Input.h"
#include "Collider.h"


class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void Draw(SDL_Renderer* Renderer);
	virtual void Update(float DeltaTime);
	virtual void ProcessInput(Input* UserInput);

	void SetCollision(Vector2 Position = Vector2().Zero(), Vector2 HalfDimensions = Vector2(1.0f, 1.0f), bool ShouldDebug = true);

	// this will change the width and height of the collider
	void SetCollisionDimensions(Vector2 HalfDimensions);

	void UpdateCollisionPosition();
	void FindObjectCenter();

	// get the collision publicly

	Collider* GetCollision();

protected:
	//positions for the game object to display on the window
	Vector2 Position;
	// The objects texture 
	Texture* ObjectTexture;
	// Collider
	Collider* Collision;
	// get the center of the object 
	Vector2 ObjectCenter;

	unsigned int NumberOfFrames;
};
