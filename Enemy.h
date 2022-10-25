#pragma once
#include "Character.h"
#include "Vector2.h"

class Enemy :
    public Character
{
public:
    Enemy(Texture* CharacterTexture, Vector2 Pos, int NumberOfFrames);
    ~Enemy();
    void Update(float DeltaTime) override;
    void ProcessInput(Input* UserInput) override;
};

