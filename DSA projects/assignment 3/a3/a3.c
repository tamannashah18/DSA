#include<stdio.h>
#include<stdlib.h>
struct node{
	int no;
	struct node *nxt;
}*f,*l,*nn,*c,*t,*p;
int cnt=0;
void push()
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
	printf("THE DATA OF STACK IS:-\n");
	t=f;
	int i=1;
	while(t!=NULL)
	{
		printf("NODE %d DATA IS: %d\n",i++,t->no);
		t=t->nxt;
	}
}
void pop()
{
	if(l==NULL)
	{
		printf("STACK IS EMPTY\n");
	}
	else if(cnt!=1)
	{
		t=f;
		printf("THE DELETED NODE's DATA IS %d",l->no);
		while(t->nxt->nxt!=NULL)
		{
			t=t->nxt;
		}
		free(l);
		l=t;
		l->nxt=NULL;
		cnt--;
	}
	else
	{
		printf("THE DELETED NODE's DATA IS %d",l->no);
		free(l);
		f=l=NULL;
	}

}
int main()
{
	int ch,a;
	while(1)
	{
		printf("\nENTER 1 to push\n");
		printf("ENTER 2 to display\n");
		printf("ENTER 3 to pop\n");
		printf("ENTER 4 to exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				display();
				break;
			case 3:
				pop();
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
