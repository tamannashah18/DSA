#include<stdio.h>
int main()
{
	char a[50],rev[50];
	int top=-1,i,j=0;
	printf("ENTER A STRING");
	scanf("%s",a);
	for(i=0;a[i]!='\0';i++)
		++top;
	for(i=top;i>=0;i--)
	{
		rev[i]=a[j];
		j++;
	}
	rev[top+1]='\0';
	printf("REVERSED STRING %s\n",rev);

}
