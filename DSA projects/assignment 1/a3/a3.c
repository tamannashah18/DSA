#include<stdio.h>
void main()
{
	int a[10],*p,i,max,min;
	p=a;
	for(i=0;i<10;i++)
	{
		printf("ENTER ELEMENT:");
		scanf("%d",p++);
	}
	max=min=a[0];
	p=a;
	for(i=0;i<10;i++)
	{
		printf("%d\t",*p++);
	}
	p=a;
	for(i=0;i<10;i++)
	{
		if(*p>max)
			max=*p;
		if(*p<min)
			min=*p;
		p++;
	}
	printf("\nMAXIMUM OUT OF 10 ELEMENTS IS %d",max);
	printf("\nMINIMUM OUT OF 10 ELEMENTS IS %d",min);

}
