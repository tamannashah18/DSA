#include<stdio.h>
struct q
{
	int pno,sno;
	char name[20];
}temp,p1[10],p2[10];
int n=3,r1=-1,r2=-1,f1=-1,f2=-1,j=1,k=1;
void enqueue()
{
	printf("ENTER NAME");
	scanf("%s",temp.name);
	printf("ENTER PRIORITY NO(1 or 2)");
	scanf("%d",&temp.pno);
	switch(temp.pno)
	{
		case 1 :
			if(r1==-1)
				f1=0;

			if(r1==n-1)
				printf("OVERFLOW IN P1\n");
			else
			{
				p1[++r1]=temp;
				p1[r1].sno=j++;
			}
			break;
		case 2 :
			if(r2==-1)
				f2=0;
			if(r2==n-1|| f2==r2)
				printf("OVERFLOW IN P2\n");
			else
			{
				p2[++r2]=temp;
				p2[r2].sno=k++;
			}
			break;
		default:
			printf("INVALLID NO.");
			break;
	}
 }
void display()
{
	if((r1==-1 && f1==r1 && r2==-1 && f2==r2))
		{
			printf("BOTH QUEUES ARE EMPTY\n");
		}
	else
	{
		if(r1==-1)
			printf("QUEUE 1 isEMPTY\n");
		else
		{
			printf("\nPRIORITY QUEUE 1 :\n");
			printf("S.no\tName\n");
			printf("\n-----------------------------------------------\n");
			for(int i=f1;i<=r1;i++)
			{
				printf("%d\t%s\n",p1[i].sno,p1[i].name);
			}
		}
		if(r2==-1)
			printf("QUEUE 2 isEMPTY\n");
		else
		{
			printf("\nPRIORITY QUEUE 2 :\n");
			printf("S.no\tName\n");
			printf("\n-----------------------------------------------\n");
			for(int i=f2;i<=r2;i++)
			{
				printf("%d\t%s\n",p2[i].sno,p2[i].name);
			}
		}
	}
}
void dequeue()
{
	if(r1!=-1 && f1<=n-1)
	{
		printf("\nThe deleted element from priority queue 1 is :\n");
		printf("S.no\tName\n");
		printf("\n-----------------------------------------------\n");
		printf("%d\t%s\n",p1[f1].sno,p1[f1].name);
		if(f1==r1 || f1==n-1)
			f1=r1=-1;
		else
			f1++;
	}
	else if((r1==-1 && f1==r1 && r2==-1 && f2==r2))
	{
		printf("BOTH QUEUES ARE EMPTY\n");
		r1=r2=-1;
	}
	else
	{
		printf("\nThe deleted element from priority queue 2 is :\n");
		printf("S.no\tName\n");
		printf("\n-----------------------------------------------\n");
		printf("%d\t%s\n",p2[f2].sno,p2[f2].name);
		if(f2==r2|| f2==n-1)
			f2=r2=-1;
		else
			f2++;
		f1=r1=-1;
	}
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
