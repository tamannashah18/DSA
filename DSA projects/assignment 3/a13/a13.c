#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
	int no;
	char name[20];
	struct node *nxt;
}*f,*l,*nn,*t;
int cnt=0,sum=0;
void insert()
{
	nn=(struct node*)malloc(sizeof(struct node));
	printf("ENTER NO: ");
		scanf("%d",&nn->no);
		printf("ENTER name: ");
		scanf("%s",nn->name);
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
	while(t!=NULL)
	{
		printf("Priority: %d\n",t->no);
		printf("Name: %s\n",t->name);
		t=t->nxt;
	}
}
void sort()
{
	t=f;
	int temp;
	char temp1[20];
	for(int i=0;i<cnt-1;i++)
	{
		t=f;
		for(int j=0;j<cnt-i-1;j++)
		{
			if(t->no>t->nxt->no)
			{
				temp=t->no;
				t->no=t->nxt->no;
				t->nxt->no=temp;
				strcpy(temp1,t->name);
				strcpy(t->nxt->name,t->name);
				strcpy(t->nxt->name,temp1);
			}
			t=t->nxt;
		}
	}
}
void delete()
{
	sort();
	if(f==NULL)
	{
		printf("LINKED LIST IS EMPTY\n");
	}
	else
	{
		t=f;
		printf("THE DELETED NODE's NO IS %d",t->no);
		printf("Name: %s\n",t->name);
		f=f->nxt;
		free(t);
		cnt--;
	}

}
void main()
{

	int ch;
	while(1)
	{
		printf("\nENTER 1 to insert elements\n");
		printf("ENTER 2 to display list\n");
		printf("ENTER 3 to delete \n");
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
				delete();
				break;
			case 4:
				exit(0);
				break;

		}
	}

}

