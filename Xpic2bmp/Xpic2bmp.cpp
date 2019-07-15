// Xpic2bmp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Xpic2bmp.h"

static void usage(const char *program_name)
{
    fprintf(stderr, "usage: %s \n"
		"-h [ --help ]                         Show commandline options.\n"
		"-s [ --resource ]                     Pointer to a source picture.\n"
		"-v [ --version ]                      Show the program version.\n"
		,program_name);
}

int main(int argc, char* argv[])
{
	printf("Hello World!\n");
	
	int iretval = 0;

	if (argc < 2 || stricmp(argv[1], "-h") == 0 || stricmp(argv[1], "--help") == 0) 
	{
        usage(argv[0]);
        return iretval;
    }
	else if (argc == 2 && (stricmp(argv[1], "-v") == 0 || stricmp(argv[1], "--version") == 0))
	{
        printf("V1.0.0.2\n");
        return iretval;
	}
	else if ( argc == 3 && (stricmp(argv[1], "-s") == 0 || stricmp(argv[1], "--resource") == 0) )
	{
		GVar *gb = NULL;
		gb = new GVar();
		
		//目标路径
		char exePath[MAX_PATH] = "";
		GetModuleFileName(NULL, exePath, MAX_PATH);
		char targetPath[MAX_PATH] = "";
		strncpy(targetPath, exePath, strlen(exePath) - 12);
		//目标图片路径
		char bmpPath[MAX_PATH]="";
		memset(bmpPath, 0, sizeof(bmpPath));
		strcpy(bmpPath, targetPath);
		strcat(bmpPath,"tempscalebmp.bmp");
		//放大或缩小倍率（ > 0 ）
		float ifsale = 0.0f;
		printf("图片缩放率：");
		scanf("%f", &ifsale);
		
		
		printf("原始图片路径：%s\n", argv[2]);
		int i_picW, i_picH;
		iretval = gb->GetBmpInfo(argv[2], &i_picW, &i_picH);
		printf("原始图片宽：%d, 高：%d\n", i_picW, i_picH);
		
		printf("图片压缩中。。。\n");
		iretval = gb->BMP_Zoom(argv[2], bmpPath, (ifsale > 0.00f ? ifsale : 1.0f));
		
		if (iretval != 0)
		{
			MessageBox(NULL,"图片压缩失败！\n", "Error!", MB_OK);
			return -1;
		}
		else
		{
			printf("缩放倍率：%f\n", (ifsale > 0.00f ? ifsale : 1.0f));
			printf("图片压缩成功！\n");
		}
		
		printf("生成图片路径：%s\n", targetPath);
		int o_picW, o_picH;
		iretval = gb->GetBmpInfo(bmpPath, &o_picW, &o_picH);
		printf("生成图片宽：%d, 高：%d\n", o_picW, o_picH);
		SCREEN_WIDTH = o_picW;
		SCREEN_HEIGHT = o_picH;

		ShowOnSDL(bmpPath);
	}
	else
	{
		GVar *gb = NULL;
		gb = new GVar();
		
		//目标路径
		char exePath[MAX_PATH] = "";
		GetModuleFileName(NULL, exePath, MAX_PATH);
		char targetPath[MAX_PATH] = "";
		strncpy(targetPath, exePath, strlen(exePath) - 12);
		//目标图片路径
		char bmpPath[MAX_PATH]="";
		memset(bmpPath, 0, sizeof(bmpPath));
		strcpy(bmpPath, targetPath);
		strcat(bmpPath,"tempscalebmp.bmp");
		//放大或缩小倍率（ > 0 ）
		float ifsale = 0.0f;
		printf("图片缩放率：");
		scanf("%f", &ifsale);
		
		
		printf("原始图片路径：%s\n", argv[1]);
		int i_picW, i_picH;
		iretval = gb->GetBmpInfo(argv[1], &i_picW, &i_picH);
		printf("原始图片宽：%d, 高：%d\n", i_picW, i_picH);
		
		printf("图片压缩中。。。\n");
		iretval = gb->BMP_Zoom(argv[1], bmpPath, (ifsale > 0.00f ? ifsale : 1.0f));
		
		if (iretval != 0)
		{
			MessageBox(NULL,"图片压缩失败！\n", "Error!", MB_OK);
			return -1;
		}
		else
		{
			printf("缩放倍率：%f\n", (ifsale > 0.00f ? ifsale : 1.0f));
			printf("图片压缩成功！\n");
		}
		
		printf("生成图片路径：%s\n", targetPath);
		int o_picW, o_picH;
		iretval = gb->GetBmpInfo(bmpPath, &o_picW, &o_picH);
		printf("生成图片宽：%d, 高：%d\n", o_picW, o_picH);
		SCREEN_WIDTH = o_picW;
		SCREEN_HEIGHT = o_picH;

		ShowOnSDL(bmpPath);
	}

	Sleep(3000);

	return iretval;
}

void ShowOnSDL(char* TagBMPPath)
{

	// Show pic by SDL [7/15/2019 yjt95]
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia(TagBMPPath))
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while (!quit)
			{//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}
				//Apply the image
				SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);

				//Update the surface
				SDL_UpdateWindowSurface(gWindow);
			}
		}
	}
	//Free resources and close SDL
	close();
}

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}

bool loadMedia(char* sTagPath)
{
	//Load success flag
	bool success = true;

	//Load splash image
	gHelloWorld = SDL_LoadBMP(sTagPath);
	if (gHelloWorld == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", sTagPath, SDL_GetError());
		success = false;
	}

	return success;
}

void close()
{
	//Deallocate surface
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}