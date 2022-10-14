#pragma once
#include "GameObject.h"
#include"SDL.h"
class Character :
    public GameObject
{
public:
    Character(Texture* CharacterTexture, int PosX, int PosY,int NumberOfFrames = 1);

    ~Character();

    void Draw(SDL_Renderer* Renderer)override;
   virtual void Update(float DeltaTime)override;
   virtual void Input()override;

private:
    unsigned int NumberOfFrames;
};

