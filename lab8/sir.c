#include<stdio.h>
#include<string.h>

int mystrlen(char  str[20])
{
	int k=0;
	while(str[k]!='\0')
		k++;
	return k;
}

int main(int argc, char* argv[])
{
	for(int i=0; i<=argc;i++)
		printf("%s, Lungimea este: %s\n",argv[i],  mystrlen(argv[i])); 	
return 0;
}
