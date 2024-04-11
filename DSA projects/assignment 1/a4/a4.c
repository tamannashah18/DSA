#include<stdio.h>
void main()
{
	int a[5]={5,10,15,20,25},*p,i;
	printf("ARRAY IS:\n");
	p=a;
	for(i=0;i<5;i++)
	{
		printf("%d\t",*p++);
	}
	p=a;
	printf("\np++ %d ",p++);
	printf("\np-- %d ",p--);
	printf("\n*p++ %d ",*p++);
	printf("\n*p-- %d ",*p--);
	printf("\n*(p++) %d ",*(p++));
	printf("\n*(p--) %d ",*(p--));
	printf("\n*(++p) %d ",*(++p));
	printf("\n*(--p) %d ",*(--p));

}



