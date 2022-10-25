#include "GameObject.h"
#include "Vector2.h"
#include "SDL.h"

GameObject::GameObject()
{
	Position = Vector2(0, 0);
	ObjectTexture = nullptr;
	ObjectCenter = Position;
	Collision = nullptr;
	NumberOfFrames = 1;
}

GameObject::~GameObject()
{
}

void GameObject::Draw(SDL_Renderer* Renderer)
{
}

void GameObject::Update(float DeltaTime)
{
	// this will find the object center based on the texture if there is one
	FindObjectCenter();

	UpdateCollisionPosition();
}

void GameObject::ProcessInput(Input* UserInput)
{
}

void GameObject::SetCollision(Vector2 Position, Vector2 HalfDimensions, bool ShouldDebug)
{
	if (Collision != nullptr) {
		// clear it
		delete (Collision);
	}
	Collision = new Collider(this, Position, HalfDimensions, ShouldDebug);
}

void GameObject::SetCollisionDimensions(Vector2 HalfDimensions)
{
	if (Collision != nullptr) {
		Collision->ColliderRect.w = HalfDimensions.x * 2;
		Collision->ColliderRect.h = HalfDimensions.y * 2;
	}
}

void GameObject::UpdateCollisionPosition()
{
	if (Collision != nullptr) {
		float w = Collision->ColliderRect.w / 2;
		float h = Collision->ColliderRect.h / 2;

		Collision->ColliderRect.x = ObjectCenter.x - w;
		Collision->ColliderRect.y = ObjectCenter.y - h;
	}
}

void GameObject::FindObjectCenter()
{
	ObjectCenter = Position;

	if (ObjectTexture != nullptr) {
		float w = ObjectTexture->GetImageWidth() / SDL_max(1, NumberOfFrames);
		float h = ObjectTexture->GetImageHeight();

		w /= 2;
		h /= 2;

		// ObjectCenter = ObjectCenter +w;
		ObjectCenter.x += w;
		ObjectCenter.y += h;
	}
}

Collider* GameObject::GetCollision()
{
	return Collision;
}
