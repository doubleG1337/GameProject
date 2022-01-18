#include"Game.h"
#include"TextureManager.h"

SDL_Texture* playerTex;
SDL_Rect srcR, destR;



Game::Game()
{

}
Game::~Game()
{

};

void Game::init(const char* tittle, int xpos, int ypos, int width, int height, bool fullscreen) 
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems initilised\n";

		window = SDL_CreateWindow(tittle, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window created\n";
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created\n";
		}
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}

	playerTex = TextureManager::LoadTexture("assets/pix.png", renderer);
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}
void Game::update()
{
	cnt++;
	destR.h = 128;
	destR.w = 128;
	destR.x = cnt;


	std::cout << cnt << std::endl;
}

void Game::render()
{
	SDL_RenderClear(renderer);
	//stuff to render
	SDL_RenderCopy(renderer, playerTex, NULL, &destR);
	
	SDL_RenderPresent(renderer);

}
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned\n";
}