#include<stdio.h>
#include<string.h>

int mystrlen(char  str[20])
{
	int k=0;
	while(str[k]!='\0')
		k++;
	return k;
}

int main()
{
	char str[10];
	scanf("%s", str);
	printf("%s %d\n", str, mystrlen(str));
	char str2[20];
	scanf("%s", str2);
	printf("%s %d\n",str2, mystrlen(str2));
return 0;
}
