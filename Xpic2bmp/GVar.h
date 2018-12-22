#ifndef __GVAR_H__
#define __GVAR_H__

#include "windows.h"

typedef int (*pGetBmpInfo)(char *OldBmpPath,int *picwidth,int *picheight);
typedef int (*pBMP_Zoom)(char *OldBmpPath,char *NewBmpPath,float Multiple);

class GVar
{
public:
	GVar();
	virtual ~GVar();

public:
	//Í¼Æ¬Ëõ·Å
	pGetBmpInfo GetBmpInfo;
	pBMP_Zoom BMP_Zoom;
	
	HINSTANCE	hLib_bmp;
};


#endif