#include<stdio.h>
int n,q[20],f=-1,r=-1,val;
void enqueue()
{
	if(r==n-1)
		printf("OVERFLOW\n");
	else
	{
		printf("ENTER VALUE TO BE INSERTED");
		scanf("%d",&val);
		if(r==-1 && f==-1)
			f=0;
		q[++r]=val;
		display();
	}
}
void dequeue()
{
	if(r!=f)
	{
		int del;
		printf("\nENTER 1 to delete from left \n");
		printf("ENTER 2 to delete from right \n");
		scanf("%d",&del);
		switch(del)
		{
		case 1:
			printf("%d is the deleted element",q[f++]);
			break;
		case 2:
			printf("%d is the deleted element",q[r--]);
			break;
		default:
			printf("INVALID INPUT");
			break;
		}
	}
	else if(f==-1 || r==-1 )
		printf("EMPTY QUEUE\n");
	else
	{
		printf("%d is the deleted element",q[f]);
		r=f=-1;
	}
}
void display()
{
	if(r!=-1 && f!=-1)
	{
		printf("THE QUEUE IS: \n");
		for(int i=f;i<=r;i++)
			printf("%d\t",q[i]);
		printf("\n");
	}
	else
		printf("EMPTY QUEUE\n");
}
void main()
{
	int ch;
	printf("ENTER N");
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
