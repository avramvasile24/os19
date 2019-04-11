#include<stdio.h>
#include<stdlib.h>
int main()
{
  int x, v[20],i=0,j=0;
  while(x)
  {
	  scanf("%d",&x);
	  v[i]=x;
	  i++;
  }
  for(j=0;j<i;j++)
  {
	  printf("%d ", v[j]);
  }
return 0;
}
