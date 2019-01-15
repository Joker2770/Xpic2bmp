// Xpic2bmp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GVar.h"

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
		
		//Ŀ��·��
		char exePath[MAX_PATH] = "";
		GetModuleFileName(NULL, exePath, MAX_PATH);
		char targetPath[MAX_PATH] = "";
		strncpy(targetPath, exePath, strlen(exePath) - 12);
		//Ŀ��ͼƬ·��
		char bmpPath[MAX_PATH]="";
		memset(bmpPath, 0, sizeof(bmpPath));
		strcpy(bmpPath, targetPath);
		strcat(bmpPath,"tempscalebmp.bmp");
		//�Ŵ����С���ʣ� > 0 ��
		float ifsale = 0.0f;
		printf("ͼƬ�����ʣ�");
		scanf("%f", &ifsale);
		
		
		printf("ԭʼͼƬ·����%s\n", argv[2]);
		int i_picW, i_picH;
		iretval = gb->GetBmpInfo(argv[2], &i_picW, &i_picH);
		printf("ԭʼͼƬ��%d, �ߣ�%d\n", i_picW, i_picH);
		
		printf("ͼƬѹ���С�����\n");
		iretval = gb->BMP_Zoom(argv[2], bmpPath, (ifsale > 0.00f ? ifsale : 1.0f));
		
		if (iretval != 0)
		{
			MessageBox(NULL,"ͼƬѹ��ʧ�ܣ�\n", "Error!", MB_OK);
			return -1;
		}
		else
		{
			printf("���ű��ʣ�%f\n", (ifsale > 0.00f ? ifsale : 1.0f));
			printf("ͼƬѹ���ɹ���\n");
		}
		
		printf("����ͼƬ·����%s\n", targetPath);
		int o_picW, o_picH;
		iretval = gb->GetBmpInfo(bmpPath, &o_picW, &o_picH);
		printf("����ͼƬ��%d, �ߣ�%d\n", o_picW, o_picH);
	}
	else
	{
		GVar *gb = NULL;
		gb = new GVar();
		
		//Ŀ��·��
		char exePath[MAX_PATH] = "";
		GetModuleFileName(NULL, exePath, MAX_PATH);
		char targetPath[MAX_PATH] = "";
		strncpy(targetPath, exePath, strlen(exePath) - 12);
		//Ŀ��ͼƬ·��
		char bmpPath[MAX_PATH]="";
		memset(bmpPath, 0, sizeof(bmpPath));
		strcpy(bmpPath, targetPath);
		strcat(bmpPath,"tempscalebmp.bmp");
		//�Ŵ����С���ʣ� > 0 ��
		float ifsale = 0.0f;
		printf("ͼƬ�����ʣ�");
		scanf("%f", &ifsale);
		
		
		printf("ԭʼͼƬ·����%s\n", argv[1]);
		int i_picW, i_picH;
		iretval = gb->GetBmpInfo(argv[1], &i_picW, &i_picH);
		printf("ԭʼͼƬ��%d, �ߣ�%d\n", i_picW, i_picH);
		
		printf("ͼƬѹ���С�����\n");
		iretval = gb->BMP_Zoom(argv[1], bmpPath, (ifsale > 0.00f ? ifsale : 1.0f));
		
		if (iretval != 0)
		{
			MessageBox(NULL,"ͼƬѹ��ʧ�ܣ�\n", "Error!", MB_OK);
			return -1;
		}
		else
		{
			printf("���ű��ʣ�%f\n", (ifsale > 0.00f ? ifsale : 1.0f));
			printf("ͼƬѹ���ɹ���\n");
		}
		
		printf("����ͼƬ·����%s\n", targetPath);
		int o_picW, o_picH;
		iretval = gb->GetBmpInfo(bmpPath, &o_picW, &o_picH);
		printf("����ͼƬ��%d, �ߣ�%d\n", o_picW, o_picH);
	}

	Sleep(5000);

	return iretval;
}

