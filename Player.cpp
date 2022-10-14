#include "Player.h"

Player::Player(Texture* CharacterTexture, int PosX, int PosY, int NumberOfFrames)
	: Character:: Character(CharacterTexture, PosX, PosY, NumberOfFrames)
{

}

Player::~Player()
{
}

void Player::Update(float DeltaTime)
{
	Character::Update(DeltaTime);


}

void Player::Input()
{
}
