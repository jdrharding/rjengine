#include "rjengine.h"
#include "sprite.h"
#include "texturemgr.h"

RJEngine RJEngine::instance;

RJEngine::RJEngine()
{
}

bool RJEngine::Initialize(char* title, int sWidth, int sHeight)
{
	bool success = true;

	windowTitle = title;
	windowWidth = sWidth;
	windowHeight = sHeight;

	if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		printf("SDL could not be initialized! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Linear texture filtering disabled");
		}

		mainWindow = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
		if ( mainWindow == NULL )
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);
			if (mainRenderer == NULL)
			{
				printf("Renderer not created! SDL_Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(mainRenderer, 255, 255, 255, 255);
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags ))
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	testTextureMgr = new TextureManager();
	testTextureMgr->Add(mainRenderer, "testBG", "..\\images\\swamp.png");
	testSprite = new Sprite("tSprite", 500, 500);
	if(!testSprite->Sprite::Initialize("..\\images\\sprite.png", "..\\images\\sprite.xml", mainRenderer, testTextureMgr));
	{
		printf("Unable to initialize Sprite!");
	}



	return success;
}

void RJEngine::MainLoop()
{
	while (mainWindow != NULL)
	{
		SDL_RenderClear(mainRenderer);
		HandleInput();
		Update();
		Render();
	}

}

void RJEngine::HandleInput()
{
	while (SDL_PollEvent(&event) != 0)
	{
		switch (event.type)
		{
			case SDL_QUIT:
				this->Close();
				break;

			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_LEFT:
						printf("LEFT PRESSED!\n");
						break;
					case SDLK_RIGHT:
						printf("RIGHT PRESSED!\n");
						break;
					case SDLK_DOWN:
						printf("DOWN PRESSED!\n");
						break;
					case SDLK_UP:
						printf("UP PRESSED!\n");
						break;
				}
				break;
		} 
	}
}

void RJEngine::Update()
{

}

void RJEngine::Render()
{
	SDL_RenderClear(mainRenderer);
	testTextureMgr->Get("testBG")->Draw(0,0);
	testSprite->Draw("WalkUp");
	SDL_RenderPresent(mainRenderer);
}

void RJEngine::Close()
{
	if(mainWindow)
	{
		SDL_DestroyWindow( mainWindow );
		mainWindow = NULL;
	}

	if(mainRenderer)
	{
		SDL_DestroyRenderer(mainRenderer);
		mainRenderer = NULL;
	}

	IMG_Quit();
	SDL_Quit();	
}

void RJEngine::Begin()
{
	if (!Initialize("Testing Engine", 1024, 1024))
	{
		throw "Unable to initialize engine, shutting down!";
	}

	MainLoop();
}

SDL_Renderer* RJEngine::GetEngineRenderer()
{
	return mainRenderer;
}

RJEngine* RJEngine::GetEngineInstance()
{
	return  &instance;
}