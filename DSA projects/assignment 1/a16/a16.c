#include<stdio.h>
char a[50],b[50],c[100],val,*p,*p1;
int top=0,top1=0,t=0,i;
char pop1()
{
	return *(p+top--);
}
char pop2()
{
	return *(p1+top1--);
}
void main()
{
	printf("ENTER FIRST STRING");
	scanf("%s",a);
	p=a;
	for(i=0;a[i]!='\0';i++)
		top++;
	printf("ENTER SECOND STRING");
	scanf("%s",b);
	for(i=0;b[i]!='\0';i++)
		top1++;
	p1=b;
	while(top!=-1)
	{
		c[t++]=pop1();
	}
	while(top1!=-1)
	{
		c[t++]=pop2();
	}
	printf("CONCATENATED STRING :");
	printf("%s",c);
}
