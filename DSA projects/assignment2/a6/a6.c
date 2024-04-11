#include<stdio.h>
int n,q[20],*f,*r=&q[-1],val;
void enqueue()
{
	if(r==&q[-1])
		f=&q[0];
	if(r==&q[n-1])
		printf("OVERFLOW\n");
	else
	{
		printf("ENTER VALUE TO BE INSERTED");
		scanf("%d",&val);
		*(++r)=val;
		display();
	}
}
void dequeue()
{
	if(r!=&q[-1] && f<=&q[n-1])
	{
		printf("The deleted element is %d",*(f++));
		if(f==r)
			f=r=&q[-1];
	}
	else
	{
		printf("EMPTY QUEUE\n");
		f=r=&q[-1];
	}
}
void display()
{
	if(r!=&q[-1])
	{
		int *i;
		printf("THE QUEUE IS: \n");
		for(i=f;i<=r;i++)
		{
			printf("%d\t",*i);
		}
		printf("\n");
	}
	else
		printf("EMPTY QUEUE\n");
}
void main()
{
	int ch;
	printf("ENTER n");
	scanf("%d",&n);
	while(1)
	{
		printf("\nENTER 1 to insert \n");
		printf("ENTER 2 to delete \n");
		printf("ENTER 3 to display \n");
		printf("ENTER 4 to exit \n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				enqueue();
			break;
			case 2:
				dequeue();
			break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
		}
	}
}