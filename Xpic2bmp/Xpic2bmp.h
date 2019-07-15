#ifndef __XPIC2BMP_H__
#define __XPIC2BMP_H__

#include "GVar.h"

//////////////////////////////////////////////////////////////////////////
#ifdef _WIN32
//Windows
extern "C"
{
#include "SDL.h"
};
#else
//Linux...
#ifdef __cplusplus
extern "C" {
#endif

#include <SDL.h>

#ifdef __cplusplus
};
#endif
#endif

#include <stdio.h>

//´°¿Ú¿í¸ß
int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;

SDL_Window *gWindow = NULL;
SDL_Surface *gScreenSurface = NULL;
SDL_Surface *gHelloWorld = NULL;

//SDL show
void ShowOnSDL(char* TagBMPPath);
//Starts up SDL and creates window
bool init();
//Loads media
bool loadMedia(char* sTagPath);
//Frees media and shutdown SDL
void close();
//////////////////////////////////////////////////////////////////////////

#endif // __XPIC2BMP_H__
