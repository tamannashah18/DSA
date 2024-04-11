#include<stdio.h>
int n,q1[20],q2[20],f1=-1,r1=-1,f2=-1,r2=-1,val,pno;
void enqueue()
{
	printf("ENTER PRIORITY NO.");
	scanf("%d",&pno);
	switch(pno)
	{
	case 1:
		if(r1==-1)
			f1=0;
		if(r1==n-1)
			printf("OVERFLOW\n");
		else
		{
			printf("ENTER VALUE TO BE INSERTED");
			scanf("%d",&val);
			q1[++r1]=val;
			display();
		}
		break;
	case 2:
		if(r2==-1)
			f2=0;
		if(r2==n-1)
			printf("OVERFLOW\n");
		else
		{
			printf("ENTER VALUE TO BE INSERTED");
			scanf("%d",&val);
			q2[++r2]=val;
			display();
		}
		break;
	default:
		printf("ENTER VALID PRIORITY NO.");
		break;
	}
}
void dequeue()
{
	if(r1!=-1 && f1<=n-1)
	{
		printf("The deleted element is %d",q1[f1]);
		if(f1==r1 || f1==n-1)
			f1=r1=-1;
		else
			f1++;
	}
	else if((r1==-1 && f1==r1 && r2==-1 && f2==r2) || (f1>r1 && f2>r2))
	{
		printf("BOTH QUEUES ARE EMPTY");
	}
	else
	{
		printf("Q1 IS EMPTY\n");
		printf("The deleted element is %d",q2[f2]);
		if(f2==r2|| f2==n-1)
			f2=r2=-1;
		else
			f2++;
		f1=r1=-1;
	}
}
void display()
{
	if(r1!=-1)
	{
		printf("THE QUEUE 1 IS: \n");
		for(int i=f1;i<=r1;i++)
			printf("%d\t",q1[i]);
		printf("\n");
	}
	else
		printf(" Q1 IS EMPTY\n");
	if(r2!=-1)
		{
			printf("THE QUEUE 2 IS: \n");
			for(int i=f2;i<=r2;i++)
				printf("%d\t",q2[i]);
			printf("\n");
		}
		else
			printf(" Q2 IS EMPTY\n");
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