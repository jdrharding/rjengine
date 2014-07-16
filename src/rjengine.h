#ifndef _RJENGINE_H
#define _RJENGINE_H

#include <SDL.h>
#include <SDL_image.h>
#include "texture.h"

class RJEngine
{
	private:
		//Running instance of our engine
		static RJEngine instance;

		//Our main window in which our game will be rendered.
		SDL_Window* mainWindow;
		//Our main renderer
		SDL_Renderer* mainRenderer;
		//Surface on our Window
		SDL_Surface* mainSurface;

		Texture* testTexture;

		SDL_Event event;

		//Window details
		char* windowTitle;
		int windowHeight;
		int windowWidth;

		//Initialize the engine and create the window.
		bool Initialize();
		//The main loop that our game will exist within.
		void MainLoop();
		//Handle any user input
		void HandleInput();
		//Update the game state
		void Update();
		//Render the current frame
		void Render();
		//Close the window
		void Close();
		
	public:

		SDL_Renderer* GetEngineRenderer();

		RJEngine(char* title, int32_t sWidth, int32_t sHeight);

		void Begin();

	public:

		static RJEngine* GetEngineInstance();
};

#endif