 //Programul volum
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double heron(double a, double b, double c)
{
	double p=(a+b+c)/2;
	double x=p*(p-a)*(p-b)*(p-c);
	return sqrt(x);
}
double volumpt(double h, double a, double b, double c)
{
	double Ab=heron(a, b, c);
        return (Ab*h)/3;
}
int main(int argc,  char *argv[])
{
	if(argc!=5)
	{
		return -1;
		printf("Introducere neconforma\n");
	}
	double h=atof(argv[1]);
	double a=atof(argv[2]);
	double b=atof(argv[3]);
	double c=atof(argv[4]);
	double v=volumpt(h,a,b,c);
	printf("%f\n", v);
	return 0;
}
