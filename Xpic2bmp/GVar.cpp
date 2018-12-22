#include "StdAfx.h"
#include "GVar.h"

GVar::GVar()
{

	char dllpath_bmp[MAX_PATH]="";
	memset(dllpath_bmp, 0, sizeof(dllpath_bmp));
	strcat(dllpath_bmp,"BMPTransByOpenCV.dll");
	hLib_bmp = LoadLibrary(dllpath_bmp);
	if (hLib_bmp == NULL )
	{
		
		MessageBox(NULL,"BMPTransByOpenCV.dll加载失败", "dll error!", MB_OK);
		return ;	
	}
	
	GetBmpInfo = (pGetBmpInfo)GetProcAddress(hLib_bmp,"GetBmpInfo");
	if (!GetBmpInfo)
	{
		MessageBox(NULL,"GetBmpInfo接口加载失败", "interface error!", MB_OK);
		if (hLib_bmp)
		{
			FreeLibrary(hLib_bmp);
		}
		return ;
	}
	BMP_Zoom = (pBMP_Zoom)GetProcAddress(hLib_bmp,"BMP_Zoom");
	if (!GetBmpInfo)
	{
		MessageBox(NULL,"BMP_Zoom接口加载失败", "interface error!", MB_OK);
		if (hLib_bmp)
		{
			FreeLibrary(hLib_bmp);
		}
		return ;
	}

}

GVar::~GVar()
{

	if (this->hLib_bmp != NULL)
	{
		FreeLibrary(this->hLib_bmp);
	}
}