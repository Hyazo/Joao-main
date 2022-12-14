#pragma once
#include  "Vector2.h"
#include <SDL.h>

class Texture
{
public:
	Texture();
	~Texture();

private:
	// hold reference to the texture file
	SDL_Texture* SdlTexture;

	// set dimensions for the file
	int width;
	int height;

public:
	// load the image from path
	// add the texture to the renderer
	bool LoadImageFromFile(const char* path, SDL_Renderer* renderer);

	// render the image to the screen when called
	// param 1 - to copy the texture to the renderer
	// param 2 & 3 - x and y position of the texture on the screen
	// param 4 - the area we wans to copy from the texture onto the window
	void Draw(SDL_Renderer* renderer, Vector2 Pos, SDL_Rect* SourceRect = NULL, int Scale = 1);

	// return the dimensions of the image
	int GetImageWidth() { return width; }
	int GetImageHeight() { return height; }

	// remove the texture from memory
	void ResetTexture();
};