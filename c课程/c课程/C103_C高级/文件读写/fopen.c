#include <stdio.h>



int writeData()
{
	FILE *fp = fopen("stuData","wb");
	if(fp==NULL)
	{
		printf("文件打开失败\n");
	}
	else
	{
		printf("文件打开成功\n");
	}
	//写入文件
	char str[] = "Hello world \n Hello zhimeng";
	int ret = fwrite(str,sizeof(str),1,fp);
	if(ret == 1)
	{
		printf("写入成功\n");
	}
	else
	{
		printf("写入失败\n");
	}

	fclose(fp);
}

void readData()
{
	FILE *fp = fopen("stuData","rb");
	if(fp==NULL)
	{
		printf("文件打开失败\n");
		return;
	}
	//从文件中读书据
	char buffer[1024]={0};
	int i=0;
	int ret;
	while(1)
	{
		ret = fread(&buffer[i++],1,1,fp);
		if(ret == 0)
		break;	
	}
	//printf("ret = %d\n",ret);
	printf("buffer=%s\n",buffer);
	fclose(fp);
}



int main()
{
	//writeData();
	readData();
}
