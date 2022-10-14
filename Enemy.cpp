#include "Enemy.h"

Enemy::Enemy(Texture* CharacterTexture, int PosX, int PosY, int NumberOfFrames)
	:Character::Character(CharacterTexture,PosX, PosY, NumberOfFrames)
{

}

Enemy::~Enemy()
{
}

void Enemy::Update(float DeltaTime)
{
	Character::Update(DeltaTime);

	PositionX += 500 * DeltaTime;
}

void Enemy::Input()
{
}
