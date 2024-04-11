#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct ll{
	int a;
	char b[2];
	struct ll *nxt;
}*f1,*l1,*nn1,*t1;
struct intll{
	int a;
	struct intll *nxt;
}*f2,*l2,*nn2,*t2;
struct charll{
	char b[2];
	struct charll *nxt;
}*f3,*l3,*nn3,*t3;
int cnt=0;
void display()
{
	int ch=0;
	printf("ENTER 1 to display int list\n");
	printf("ENTER 2 to display char list\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			t2=f2;
			while(t2!=NULL)
			{
				printf("%d ",t2->a);
				t2=t2->nxt;
			}
			break;
		case 2:
			t3=f3;
			printf("CHARACTER LINKED LIST IS :\n");
			int i=0;
			while(t3!=NULL)
			{
				printf("%c ",t3->b[0]);
				t3=t3->nxt;
			}
		break;
		default:
			printf("INVALID INPUT\n");
			break;
	}
}
void insert()
{
	nn1=(struct ll*)malloc(sizeof(nn1));
	printf("ENTER INTEGER:");
	scanf("%d",&nn1->a);
	printf("ENTER CHARCTER:");
	scanf("%s",nn1->b);
	if(f1==NULL)
		f1=nn1;
	else
		l1->nxt=nn1;
	l1=nn1;

}
void separate()
{
	t1=f1;
	do
	{
		nn2=(struct intll*)malloc(sizeof(nn2));
		nn2->a=t1->a;
		if(f2==NULL)
		{
			f2=nn2;
		}
		else
		{
			l2->nxt=nn2;
		}
		l2=nn2;

		nn3=(struct charll*)malloc(sizeof(nn3));
		nn3->b[0]=t1->b[0];
		if(f3==NULL)
		{
			f3=nn3;
		}
		else
		{
			l3->nxt=nn3;
		}
		l3=nn3;
		cnt++;
		t1=t1->nxt;
	}while(t1!=NULL);
}
void main()
{

	int ch;
	while(1)
	{
		printf("\nENTER 1 to insert elements\n");
		printf("ENTER 2 to display list\n");
		printf("ENTER 3 to exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				separate();
				display();
				break;
			case 3:
				exit(0);
				break;

		}
	}

}

