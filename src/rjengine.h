#ifndef _RJENGINE_H
#define _RJENGINE_H

#include <SDL.h>
#include <SDL_image.h>

class RJEngine
{
	private:
		//Our main window in which our game will be rendered.
		SDL_Window* mainWindow;
		SDL_Renderer* mainRenderer;
		SDL_Texture* bgTexture;
		SDL_Texture* testSprite;
		SDL_Event event;
		char* windowTitle;
		int32_t windowHeight;
		int32_t windowWidth;

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
	RJEngine(char* title, int32_t sWidth, int32_t sHeight);
	~RJEngine();

	void Begin();
};

#endif