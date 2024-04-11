#include<stdio.h>
#include<stdlib.h>
int ch=0,top=-1,i,n,temp,*p;
void push(int a[n])
{
	if(top<n-1)
	{
		printf("ENTER VALUE TO BE PUSHED");
		scanf("%d",&temp);
		top++;
		*(p+top)=temp;
		printf("\nPUSH SUCCESSFULL\n");
	}
	else
	{
		printf("STACK WILL BE OVERFLOWED\n");
	}
}
void pop(int a[n])
{
	if(top!=-1)
	{
		printf("POPPED ELEMENT IS %d\n",*(p+top));
		top--;
	}
	else
	{
		printf("STACK WILL BE UNDERFLOWED\n");
	}
}
void peep(int a[n])
{

	if(top!=-1)
	{
		printf("ENTER POSITION OF THE ELEMENT TO BE SEARCHED");
		scanf("%d",&temp);
		if(temp<=0||temp>top)
			printf("INVALID INPUT");
		else
		{
			printf("THE VALUE AT %d from top is %d",temp,*(p+top-temp+1));
			printf("\nPEEP SUCCESSFULL\n");
		}
	}
	else
	{
		printf("STACK IS EMPTY\n");
	}
}
void display(int a[n])
{
	if(top!=-1)
	{
		printf("STACK IS\n");
		for(i=top;i>=0;i--)
		{
			printf("%d\n",*(p+i));
		}
	}
	else
	{
		printf("STACK IS EMPTY\n");
	}
}
void main()
{

	printf("ENTER SIZE OF THE STACK");
	scanf("%d",&n);
	int a[n];
	p=a;
	while(1)
	{
		printf("\nENTER 1 to push\n");
		printf("ENTER 2 to pop\n");
		printf("ENTER 3 to peep\n");
		printf("ENTER 4 to display\n");
		printf("ENTER 5 to exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			push(a);
			break;
		case 2:
			pop(a);
			display(a);
			break;
		case 3:
			peep(a);
			break;
		case 4:
			display(a);
			break;
		case 5:
			exit(0);
			break;
		default:
			printf("INVALID INPUT");
			break;
		}
	}
}
