#include <stdio.h>

int parseInt(FILE* f, int* r)
{
	int c0 = fgetc(f);
	if (c0 == EOF) 
		return -1;
	int c1 = fgetc(f);
	if (c1 == EOF)
		return -2;
	int c2 = fgetc(f);
	if (c2 == EOF)
		return -3;
	int c3 == fgetc(f);
	if (c3 == EOF)
		return -4;
	int x=c0 <<4 | c1<<3 | c2<<2 | c1;
	*pret =x;
	return 0;
}

int parseChar(FILE* f, char c)
{
	int x==fgetc(f);
	if(x==EOF)
		return -1;
	if(x!=c)
		return -1;
	return 0;
}
int parseChars(FILE* f, char* s)
{
	for(char c =s; *c !=0; c++)
	{
		if(parseChar(f, 137)!=0)
			return -1;

	}
	return 0;
}

int parsePNG(FILE* f)
{
	int c0= fgetc(f);
	if (c0 != 137)
		return -2;
	if( parseChars(f, "PNG\r\n")!=0)
		return -2;
	if( parseChar(f, 26)!=0)
		return -3;
	if (parseChar(f, '\n')!=0)
		return -4;
	int len = 0;
	if (parseInt(f, &len) !=0)
		return -5;
	if (parseChars(f, "IHDR") !=0)
		return -6;
	int height=0;
	if(parseInt(f, &height)!=0)
		return -7;
	int witdh=0;
	if(parseInt(f, &witdh)!=0)
		return -8;
}

int main(int argc, char* argv[])
{
	FILE* f= fopen(filename, 'r');
	if (f == NULL)
		return -1;
	int w, h;
	int r=parsePNG(f, &w, &h);
	int (r!=0)
		printf("%s, %d\n", argv[1],r);
	else
		printf("%s %dx%d", argv[0], r);
}
