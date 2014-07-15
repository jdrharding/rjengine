#include <SDL.h>
#include "rjengine.h"

RJEngine::RJEngine(char* title, int32_t sWidth, int32_t sHeight)
{
	windowTitle = title;
	windowWidth = sWidth;
	windowHeight = sHeight;
}

RJEngine::~RJEngine()
{

}

bool RJEngine::Initialize()
{
	bool success = true;
	if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		printf("SDL could not be initialized! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		mainWindow = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
		if ( mainWindow == NULL )
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			screenSurface = SDL_GetWindowSurface( mainWindow );
		}
	}

	imageSurface = SDL_LoadBMP("swamp.bmp");
	if(imageSurface == NULL)
	{
		printf("Unable to load image %s. SDL error: %s\n", "\\images\\swamp.bmp", SDL_GetError() );
		success = false;
	}

	return success;
}

void RJEngine::MainLoop()
{
	while (mainWindow != NULL)
	{
		HandleInput();
		Update();
		Render();
	}

}

void RJEngine::HandleInput()
{
	while (SDL_PollEvent(&event) != 0)
	{
		if (event.type == SDL_QUIT)
		{
			this->Close();
		} 
		else if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			//switch(event.button.button)
			//{
			//	case SDL_BUTTON_LEFT:

			//}
		}
	}
}

void RJEngine::Update()
{
	SDL_BlitSurface(imageSurface, NULL, screenSurface, NULL);
	SDL_UpdateWindowSurface(mainWindow);
}

void RJEngine::Render()
{

}

void RJEngine::Close()
{
	SDL_FreeSurface(screenSurface);
	screenSurface = NULL;
	SDL_DestroyWindow( mainWindow );
	mainWindow = NULL;
	SDL_Quit();	
}

void RJEngine::Begin()
{
	if (!Initialize())
	{
		throw "Unable to initialize engine, shutting down!";
	}

	MainLoop();
}