#pragma once

#include <vector>
#include "SDL.h"
#include "Vector2.h"

using namespace std;


class GameObject;

class Collider
{
public:
	Collider(GameObject* OwnverObject, Vector2 Position = Vector2().Zero(), Vector2 HalfDimensions = Vector2(1.0f,1.0f), bool ShouldDebug = true);
	~Collider();
	
	void Update(float DeltaTime, vector<Collider*> OtherColliders);
	void Draw(SDL_Renderer* Renderer);

	// set the bound for the collider
	SDL_FRect ColliderRect;

	// Get the other colliders that are overlapping this collider
	vector<Collider*> GetOverlappingColliders();

	// debug to draw the collider to the screen
	bool bDebug;

	GameObject* GetOwner();

protected:
	// Store all the colliders that are currently overlapping this collider
	vector<Collider*> OverlappedColliders;


	GameObject* OwnerObject;
};

