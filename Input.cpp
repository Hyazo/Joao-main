#include "Input.h"
#include "SDL.h"

Input::Input()
{
}

Input::~Input()
{
}

void Input::UpdateInput(bool& bIsGameOver)
{
	SDL_Event Event;
	if (SDL_PollEvent(&Event)) {

		switch (Event.type) {
			// detect the type of input that was inputted
		case SDL_KEYDOWN:
			KeyboardState = SDL_GetKeyboardState(NULL);
		case SDL_KEYUP:
			KeyboardState = SDL_GetKeyboardState(NULL);
			break;
		default:
			break;
		}
		// when you hit the cross button on the app, closse the game
		if (Event.type == SDL_QUIT) {
			bIsGameOver = true;
		}
	}
}

bool Input::IsKeyDown(SDL_Scancode Key)
{
	if (KeyboardState != nullptr && KeyboardState[Key] == true) {
		return true;
	}
	return false;
}

bool Input::IsKeyUp(SDL_Scancode Key)
{
	if (KeyboardState != nullptr && KeyboardState[Key] == true) {
		return false;
	}
	return true;
}
