#include<stdio.h>
#include<stdlib.h>
struct node{
	int exp,coef;
	struct node *nxt;
}*f,*l,*nn,*t;
int cnt=0;
void insert()
{
	nn=(struct node*)malloc(sizeof(struct node));
	printf("ENTER Coefficient: ");
	scanf("%d",&nn->coef);
	printf("ENTER Exponent(power): ");
	scanf("%d",&nn->exp);
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
	printf("THE DATA OF LINKED LIST IS:-\n");
	t=f;
	int i=1;
	while(t!=NULL)
	{
		printf("+ %dx^%d  ",t->coef,t->exp);
		t=t->nxt;
	}
}
void main()
{

	int ch;
	while(1)
	{
		printf("\nENTER 1 to insert elements\n");
		printf("ENTER 2 to display polynomial\n");
		printf("ENTER 3 to exit\n");
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
				exit(0);
				break;

		}
	}

}
