#include<stdio.h>
void main()
{
	char str[100],*p;
	int len=0;
	printf("ENTER STRING");
	scanf("%s",str);
	p=str;
	while(*p!='\0')
	{
		len++;
		p++;
	}
	printf("LENGTH OF STRING %s IS %d",str,len);
}
