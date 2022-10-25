#include "Game.h"
#include "Texture.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include <iostream>
#include "Vector2.h"
#include "Collider.h"

//constructor
Game::Game()
{
	//set the sdl window to null in case it has memory
	SdlWindow = nullptr;
	SdlRenderer = nullptr;

	//initiallise subsystem in SDL2 framework
	if (SDL_InitSubSystem(SDL_INIT_EVERYTHING) != 0)
	{

		bIsGameOver = true;
		//if failed to initialise subsystem, tell us on the console
		cout << "initialised SDL - failed" << endl;
		//exit app


	}
	else
	{

		bIsGameOver = false;
		//if subsystem successully initialises
		cout << "initialised success" << endl;
	}
}


// deconsructor
Game::~Game()
{
	
}


bool Game::Start()
{
	//create the sdl renderer and define it
	SdlRenderer = SDL_CreateRenderer(SdlWindow, 0, -1);

	LastUpdateTime = SDL_GetTicks();

	//make sure the renderer worked
	if (SdlRenderer != nullptr) {
		cout << "create renderer - success" << endl;


		// start detecting Input
		UserInput = new Input();


		//initialised texture
		PlayerTexture = new Texture();
		//load the texture
		PlayerTexture->LoadImageFromFile("Assets/spritesheet.png", SdlRenderer);
        // construct the playeer as a character
		Player* PlayerCharacter = new Player(PlayerTexture, Vector2(0, 0), 109);
			GameObjects.push_back(PlayerCharacter);
			//Add the gameobjects collision into the games colliders to allow for the proper detection
			BoxColliders.push_back(PlayerCharacter->GetCollision());
			
			//initialised texture
			EnemyTexture = new Texture();
			//load the texture
			EnemyTexture->LoadImageFromFile("Assets/goblin-spritesheet-65x35-28.png", SdlRenderer);
			
			
			// construct the playeer as a character
			Character* EnemyCharacter = new Enemy(EnemyTexture, Vector2(0, 37), 28);
			GameObjects.push_back(EnemyCharacter);
			BoxColliders.push_back(EnemyCharacter->GetCollision());

		
			// construct the playeer as a character
			Character* EnemyCharacter2 = new Enemy(EnemyTexture, Vector2(0, 72), 28);
			GameObjects.push_back(EnemyCharacter2);
			BoxColliders.push_back(EnemyCharacter2->GetCollision());

		
		return true;
	}

	cout << "create renderer - failed" << SDL_GetError() << endl;
	return false;
}


void Game::ProcessInput()

{
	UserInput->UpdateInput(bIsGameOver);

	// cycle thru all gameobjects and run their inputs
	for (unsigned int i = 0; i < GameObjects.size(); i++) {
		GameObjects[i]->ProcessInput(UserInput);
	}
}


void Game::Update()
{
	// @ todo: add and changes to the game each frame
	// how long since the last frame was updated in milliseconds
	unsigned int tick = SDL_GetTicks() - LastUpdateTime;

	//change the tick to seconds
	float DeltaTime = tick / 1000.0f;

	// Refresh the last update time
	LastUpdateTime = SDL_GetTicks();
	

	//@TODO add anything that needs DeltaTime below here
	// cycle thru all gameobjects and run their update
	for (unsigned int i = 0; i < GameObjects.size(); i++) {
		GameObjects[i]->Update(DeltaTime);
	}
	// detection for box colliders
	for (unsigned int i = 0; i < BoxColliders.size(); ++i) {
		BoxColliders[i]->Update(DeltaTime, BoxColliders);
	}

	
	
}


void Game::Draw()
{
	//set draw the colour
	SDL_SetRenderDrawColor(SdlRenderer, 15, 15, 15, 255);

	//clear the renderer
	SDL_RenderClear(SdlRenderer);

	// @ todo: Draw stuff here
	

	// cycle thru all gameobjects and run their draw
	for (unsigned int i = 0; i < GameObjects.size(); i++) {
		GameObjects[i]->Draw(SdlRenderer);
	}

	for (unsigned int i = 0; i < BoxColliders.size(); i++) {
		BoxColliders[i]->Draw(SdlRenderer);
	}

	SDL_RenderPresent(SdlRenderer);

}


void Game::Run(const char* title, int width, int height, bool fullscreen)
{
	//define the creation flag
	int CreationFlag = 0;

	//if bool screen is set to false then set windowed mode
	if (!fullscreen)
	{
		CreationFlag = SDL_WINDOW_SHOWN;

	}
	else
	{
		CreationFlag = SDL_WINDOW_FULLSCREEN;
	}

	//create the sdl window 
	SdlWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, CreationFlag);

	//check if the sdl window worked
	//create renderer and start game loop
	if (SdlWindow != nullptr && Start())
	{
		cout << "create window - success" << endl;


		//run the game loop
		while (!bIsGameOver)
		{
			//check for player input
			ProcessInput();

			//any changes that were made either by input or game code
			Update();

			//draw everything to the screen
			Draw();
		}
	}

	// debug if we failed or exited
	cout << "create window - failed or was exited" << endl;

	Shutdown();
	Destroy();
}


void Game::Shutdown()
{
}


void Game::Destroy()
{
	//dealocate the window
	SDL_DestroyWindow(SdlWindow);

	//dealocate the renderer
	SDL_DestroyRenderer(SdlRenderer);

	//shutdown sdl framework
	SDL_Quit();
}