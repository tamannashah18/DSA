#include<stdio.h>
#include<stdlib.h>
struct node{
	int exp,coef,add;
	struct node *nxt;
}*f1,*l1,*nn,*t,*f2,*l2,*p1,*p2,*f3,*l3;
int cnt1=0,cnt2=0,cnt3=0;
void insert()
{
	int ch=0;
	while(ch!=3)
	{
		printf("ENTER 1 to insert in 1st polynomial \n");
		printf("ENTER 2 to insert in 2nd polynomial \n");
		printf("ENTER 3 to exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				nn=(struct node*)malloc(sizeof(struct node));
				printf("ENTER Coefficient: ");
				scanf("%d",&nn->coef);
				printf("ENTER Exponent(power): ");
				scanf("%d",&nn->exp);
				nn->add=0;
				if(f1==NULL)
				{
					f1=nn;
				}
				else
				{
					l1->nxt=nn;
				}
				l1=nn;
				cnt1++;
				break;
			case 2:
				nn=(struct node*)malloc(sizeof(struct node));
				printf("ENTER Coefficient: ");
				scanf("%d",&nn->coef);
				printf("ENTER Exponent(power): ");
				scanf("%d",&nn->exp);
				nn->add=0;
				if(f2==NULL)
				{
					f2=nn;
				}
				else
				{
					l2->nxt=nn;
				}
				l2=nn;
				cnt2++;
				break;
		}

	}
}
void insert3()
{
	if(f3==NULL)
	{
		f3=nn;
	}
	else
	{
		l3->nxt=nn;
	}
	l3=nn;
	cnt3++;
}
void display()
{
	printf("Expression 1 :-\n");
	p1=f1;
	while(p1!=NULL)
	{
		printf("+ %dx^%d  ",p1->coef,p1->exp);
		p1=p1->nxt;
	}
	printf("\nExpression 2 :-\n");
	p2=f2;
	while(p2!=NULL)
	{
		printf("+ %dx^%d  ",p2->coef,p2->exp);
		p2=p2->nxt;
	}
}
void add()
{
	p1=f1;
	p2=f2;
	int check=0;
	do
	{
		p2=f2;
		check=0;
		printf("HELLO check1");
		do
		{
			if(p1->exp==p2->exp)
			{
				nn=(struct node*)malloc(sizeof(struct node));
				nn->coef=p1->coef+p2->coef;
				nn->exp=p1->exp;

				if(f3==NULL)
				{
					f3=nn;
					printf("HELLO");
				}
				else
				{
					l3->nxt=nn;
					printf("HELLO1");

				}
				l3=nn;
				cnt3++;
				p2->add=p1->add=1;
				check++;
			}
			p2=p2->nxt;
		}while(p2!=NULL);
		if(check==0)
		{
			nn=(struct node*)malloc(sizeof(struct node));
			nn->coef=p1->coef;
			nn->exp=p1->exp;
			p1->add=1;
			if(f3==NULL)
			{
				f3=nn;
				printf("HELLO");
			}
			else
			{
				l3->nxt=nn;
				printf("HELLO1");

			}
			l3=nn;
			cnt3++;

		}
		p1=p1->nxt;
	}while(p1!=NULL);
	t=f2;
	while(t!=NULL)
	{
		if(t->add ==0)
		{
			nn=(struct node*)malloc(sizeof(struct node));
			nn->coef=t->coef;
			nn->exp=t->exp;
			t->add=1;
			if(f3==NULL)
			{
				f3=nn;
				printf("HELLO");
			}
			else
			{
				l3->nxt=nn;
				printf("HELLO1");

			}
			l3=nn;
			cnt3++;
		}
		t=t->nxt;
	}
	printf("\n ADDED EXPRESSION :-\n");
	t=f3;
	int i=0;
	while(i<cnt3)
	{
		printf("+ %dx^%d  ",t->coef,t->exp);
		t=t->nxt;
		i++;
	}
}
void main()
{

	int ch;
	while(1)
	{
		printf("\nENTER 1 to insert elements in polynomials\n");
		printf("ENTER 2 to display polynomial\n");
		printf("ENTER 3 to Add polynomials\n");
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
