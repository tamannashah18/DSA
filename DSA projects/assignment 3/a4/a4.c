#include<stdio.h>
#include<stdlib.h>
struct node{
	int no;
	struct node *nxt;
}*f,*l,*nn,*c,*t,*p;
int cnt=0;
void enqueue()
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
void dequeue()
{
	if(f==NULL)
	{
		printf("QUEUE IS EMPTY\n");
	}
	else if(cnt!=1)
	{
		t=f;
		printf("THE DELETED DATA IS %d",f->no);
		f=f->nxt;
		free(t);
		cnt--;
	}
	else
	{
		printf("THE DELETED DATA IS %d",f->no);
		free(f);
		f=l=NULL;
	}

}
int main()
{
	int ch,a;
	while(1)
	{
		printf("\nENTER 1 to enqueue\n");
		printf("ENTER 2 to display\n");
		printf("ENTER 3 to dequeue\n");
		printf("ENTER 4 to exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				enqueue();
				break;
			case 2:
				display();
				break;
			case 3:
				dequeue();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("INVALID INPUT\n");
				break;
		}
	}
}
