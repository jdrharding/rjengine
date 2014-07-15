#include <SDL.h>
#include <stdio.h>
#include "rjengine.h"

int main(int argc, char* args[])
{
	RJEngine* engine = new RJEngine("Testing Engine", 1024, 1024);
	try
	{
		engine->Begin();
	}
	catch(char* e)
	{
		printf("Exception: %s\n", e);
	}
	return 0;
}