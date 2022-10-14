#pragma once
#include "Character.h"
class Player :
    public Character
{
public:
    Player(Texture* CharacterTexture, int PosX, int PosY, int NumberOfFrames = 1);
    ~Player();

    void Update(float DeltaTime) override;
    void Input() override;
};

