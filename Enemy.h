#pragma once
#include "Character.h"
class Enemy :
    public Character
{
public:
    Enemy(Texture* CharacterTexture, int PosX, int PosY, int NumberOfFrames);
    ~Enemy();
    void Update(float DeltaTime) override;
    void Input() override;
};

