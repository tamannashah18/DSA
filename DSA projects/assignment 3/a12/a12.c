#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
	int no;
	struct node *nxt;
}*f,*l,*nn,*t;
int cnt=0,sum=0;
void insert()
{
	nn=(struct node*)malloc(sizeof(struct node));
	printf("ENTER NO: ");
	scanf("%d",&nn->no);
	if(f==NULL)
	{
		f=nn;
	}
	else
	{
		l->nxt=nn;
	}
	l=nn;
	cnt++;
}
void display()
{
	printf("THE DATA OF QUEUE IS:-\n");
	t=f;
	int i=1;
	while(t!=NULL)
	{
		printf("DATA %d: %d\n",i++,t->no);
		t=t->nxt;
	}
}
void add()
{
	printf("THE SUM OF DATA IS:-\n");
	t=f;
	int sum=0;
	while(t!=NULL)
	{
		sum+=t->no;
		t=t->nxt;
	}
	printf("%d\n",sum);

}
void main()
{

	int ch;
	while(1)
	{
		printf("\nENTER 1 to insert elements\n");
		printf("ENTER 2 to display list\n");
		printf("ENTER 3 to display sum\n");
		printf("ENTER 4 to exit\n");

		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				display();
				break;
			case 3:
				add();
				break;
			case 4:
				exit(0);
				break;

		}
	}

}

