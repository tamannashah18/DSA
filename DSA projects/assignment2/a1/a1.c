#include<stdio.h>
int n,q[20],f=-1,r=-1,val;
void enqueue()
{
	if(r==-1)
		f=0;
	if(r==n-1)
		printf("OVERFLOW\n");
	else
	{
		printf("ENTER VALUE TO BE INSERTED");
		scanf("%d",&val);
		q[++r]=val;
		display();
	}
}
void dequeue()
{
	if(r!=-1 && f<=n-1)
	{
		printf("The deleted element is %d",q[f++]);
		if(f==r)
			f=r=-1;
	}
	else
	{
		printf("EMPTY QUEUE\n");
		f=r=-1;
	}
}
void display()
{
	if(r!=-1)
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