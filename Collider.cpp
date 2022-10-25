#include "Collider.h"
#include <vector>
using namespace std;

Collider::Collider(GameObject* OwnerObject, Vector2 Position, Vector2 HalfDimensions, bool ShouldDebug)
{
	bDebug = ShouldDebug;
	OverlappedColliders = {};
	this->OwnerObject = OwnerObject;

	// get the position and adjust for the size of the collider to centter it
	float x = Position.x - HalfDimensions.x;
	float y = Position.y - HalfDimensions.y;
	// set the width and height of the rect to the full size
	float w = HalfDimensions.x * 2;
	float h = HalfDimensions.y * 2;

	// set the bounds based on the above algorithmss
	ColliderRect = { x, y, w, h };

}

Collider::~Collider()
{
}

void Collider::Update(float DeltaTime, vector<Collider*> OtherColliders)
{
	// check if this collider is interssecting with any other colliders in the game
	for (unsigned int i = 0; i < OtherColliders.size(); i++) {
		if (OtherColliders[i] != this) {
			// make sure the othercollider isnt our collider
			if (SDL_HasIntersectionF(&ColliderRect, &OtherColliders[i]->ColliderRect)) {
				// looking thru the overlapped colliders array to detect if this collider is in there
				// this will passs an interator number less than the end() if its in the array
				vector<Collider*>::iterator it = find(OverlappedColliders.begin(), OverlappedColliders.end(), OtherColliders[i]);
				if (it == OverlappedColliders.end()) {
					OverlappedColliders.push_back(OtherColliders[i]);
					//SDL_Log("Entered Collider");
				}

			}
			else {
				// check if the othercollider is in the overlapped array
				vector<Collider*>::iterator it = find(OverlappedColliders.begin(), OverlappedColliders.end(), OtherColliders[i]);
				// if it is then removee it from the array
				if (it < OverlappedColliders.end()) {
					OverlappedColliders.erase(it);
					//SDL_Log("Exited Collider");

				}
			}
		}
	}
}

void Collider::Draw(SDL_Renderer * Renderer)
{
	if (bDebug == true) {
		if (OverlappedColliders.empty()) {


			SDL_SetRenderDrawColor(Renderer, 255, 0, 0, 1);
			// draw the red colour as a rectangle baased on our collider dimensions
		}
		else {
			SDL_SetRenderDrawColor(Renderer, 0, 255, 0, 1);
		}
		SDL_RenderDrawRectF(Renderer, &ColliderRect);

	}
}

vector<Collider*> Collider::GetOverlappingColliders()
{
	return vector<Collider*>();
}

GameObject* Collider::GetOwner()
{
	return nullptr;
}
