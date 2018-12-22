// Xpic2bmp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GVar.h"

int main(int argc, char* argv[])
{
	printf("Hello World!\n");

	GVar *gb = NULL;
	gb = new GVar();

	int iretval = 0;
	
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

	return 0;
}

