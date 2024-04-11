#include<stdio.h>
void main()
{
	int a[5]={5,10,15,20,25},*p,i,*q;
	printf("ARRAY IS:\n");
	for(i=0;i<5;i++)
	{
		printf("%d\t",a[i]);
	}
	p=&a[0];
	q=&a[4];
	for(p=a;p!=q;p++)
		q--;
	printf("\nADDRESS OF P = %u VALUE AT P = %d\n",p,*p);
	printf("ADDRESS OF Q = %u VALUE AT Q = %d\n",q,*q);

}
