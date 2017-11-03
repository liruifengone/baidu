//gdb a.exe -e 2345  letter.txt letter2.txt letter3.txt
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define LEN 4
int main(int argc, char *argv[])
{
	srand((unsigned)time(NULL));
	
	int ch, i,j;
	int key;
	int count=0;
	const int cons=7;
	FILE *in, *out;
	char password[LEN];
	strcpy(password,argv[2]);
	
	if (strlen(password) < 4)
	{
		printf("password is not long enough");
		return 0;
	}
	if (argc < 4)//判定输入字符个数
	{
		fprintf(stderr, "INPUT is not complete %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (strcmp(argv[1],"-e") == 0)//加密程序
	{
		for(j=0;j<(argc-3);j++)
		{
			in=NULL;
			out=NULL;
			key=rand()%100;//随机获取秘钥
			char name[20]="encrypted";
			if ((in = fopen(argv[3+j], "r")) == NULL)
			{
				fprintf(stderr, "I coundn't open the file\"%s\"\n", argv[3]);
				exit(EXIT_FAILURE);
			}
			strcat(name,argv[j+3]);
		if ((out = fopen(name, "w")) == NULL)
		{
			fprintf(stderr, "Can't creat output file.\n");
			exit(3);
		}
		putc(cons^key,out);
		for (i = 0; i < strlen(password); i++)
		
		if(putc(key^password[i], out)==EOF);
		printf("writing fail");
		while ((ch = getc(in)) != -1)
			putc(key^ch, out);
		if (fclose(in) != 0 || fclose(out) != 0)
		{
			fprintf(stderr, "Error in close file\n");
		}else
		{
			printf("finish sucessfully\n");
		}
		}
	}
	if (strcmp(argv[1],"-d") == 0)
	{
		if ((in = fopen(argv[3], "r")) == NULL)
		{
			fprintf(stderr, "I coundn't open the file\"%s\"\n", argv[3]);
			exit(EXIT_FAILURE);
		}
		key=getc(in);
		key=cons^key;
		for(i=0;i<4;i++)
		{
			password[i]=getc(in);
			password[i]=(char)(key^password[i]);
		}
		if (strcmp(password,argv[2])!=0)
		{
			printf("password is not right");
			
		}
		
		if ((out = fopen("nonencrypted.txt\0", "w")) == NULL)
		{
			fprintf(stderr, "Can't creat output file.\n");
			exit(3);
		}
		

		while ((ch = getc(in)) != -1)
			putc(key^ch, out);
		if (fclose(in) != 0 || fclose(out) != 0)
			fprintf(stderr, "Error in close file\n");
	}
	return 0;
}