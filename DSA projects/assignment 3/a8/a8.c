#include<stdio.h>
#include<stdlib.h>
struct node{
	struct stud{
	int rno,sem;
	char name[20];
	float mks[5],total;
	}s;
	struct node *nxt;
}*f,*l,*nn,*c,*t,*p;
int cnt=0,i;
void sort()
{
	int i,j;
	struct stud temp;
	for(i=0;i<cnt-1;i++)
	{
		t=f;
		for(j=0;j<cnt-i-1;j++)
		{
			if(t->s.total>t->nxt->s.total)
			{
				temp=t->s;
				t->s=t->nxt->s;
				t->nxt->s=temp;
			}
			t=t->nxt;
		}
	}

}
void insert(int a)
{
	int pos,i;
	nn=(struct node*)malloc(sizeof(struct node));
	printf("ENTER ROLL NO: ");
	scanf("%d",&nn->s.rno);
	printf("ENTER SEM: ");
	scanf("%d",&nn->s.sem);
	printf("ENTER NAME: ");
	scanf("%s",nn->s.name);
	nn->s.total=0;
	for(i=0;i<5;i++)
	{
		printf("ENTER MARKS %d: ",i+1);
		scanf("%f",&nn->s.mks[i]);
		nn->s.total+=nn->s.mks[i];
	}
	switch(a)
	{
		case 1:
			if(f==NULL)
			{
				l=nn;
			}
			else
			{
				nn->nxt=f;
			}
			f=nn;

			printf("INITAL %d",f);
			cnt++;
			break;
		case 2:
			if(l==NULL)
			{
				f=nn;
			}
			else
			{
				l->nxt=nn;
			}
			l=nn;

			printf("LAST : %d",l);
			cnt++;
			break;
		case 3:
			printf("Enter position to enter data: (1 to %d)",cnt+1);
			scanf("%d",&pos);
			if(f==NULL)
			{
				printf("LINKED LIST IS EMPTY\nSO DATA INSERTED AT NODE 1");
				f=l=nn;
				cnt++;
			}
			else if(pos>0 && pos<=cnt+1)
			{

				if(pos==cnt+1)
				{
					l->nxt=nn;
					l=nn;
				}
				else if(pos==1)
				{
					nn->nxt=f;
					f=nn;
				}
				else
				{
					c=f;
					i=1;
					while(i<pos)
					{
						p=c;
						c=c->nxt;
						i++;
					}
					p->nxt=nn;
					nn->nxt=c;
				}
				cnt++;
			}
			else
			{
				printf("NODE POSITION OUT OF SCOPE\n");
			}
			break;

			default:
				printf("INSERT VALID VALUE\n");
				break;

	}
}
void display()
{
	printf("THE DATA OF LINKED LIST IS:-\n");
	t=f;
	int i=1,j=0;
	if(f!=NULL)
	{
		printf("ROLL NO\tSEM\tNAME\tMARKS 1\tMARKS 2\tMARKS 3\tMARKS 4\tMARKS 5\tTOTAL\n");
		while(j<cnt)
		{

			printf("%d\t",t->s.rno);
			printf("%d\t",t->s.sem);
			printf("%s\t",t->s.name);
			for(i=0;i<5;i++)
			{
				printf("%f\t",t->s.mks[i]);
			}
			printf("%f\n",t->s.total);
			t=t->nxt;
			j++;
		}
	}
}
void search()
{
	t=f;
	if(t!=NULL)
	{
		while(t!=NULL)
		{
			if(t->s.total/5>70)
			{
				printf("%d\t",t->s.rno);
				printf("%d\t",t->s.sem);
				printf("%s\t",t->s.name);
				for(int i=0;i<5;i++)
				{
					printf("%f\t",t->s.mks[i]);
				}
				printf("%f\n",t->s.total);
			}
			t=t->nxt;
		}
	}
	else
	{
		printf("LIST IS EMPTY\n");
	}
}
void delete()
{
	int rn,count=0;
			printf("Enter Roll no to delete data:");
			scanf("%d",&rn);
			if(f==NULL)
			{
				printf("LINKED LIST IS EMPTY\n");
			}
			else
			{
				c=f;
				for(int i=1;i<=cnt;i++)
				{
					if(c->s.rno==rn)
					{
						count++;
						break;
					}
					p=c;
					c=c->nxt;
				}

				if(count==0)
				{
					printf("No such roll no exists\n");
				}
				else
				{
					if(i==1)
					{
						printf("THE DELETED NODE's DATA IS %d",c->s.rno);
						f=f->nxt;
						free(c);
					}
					else
					{
						printf("THE DELETED NODE's DATA IS %d",c->s.rno);
						p->nxt=c->nxt;
						free(c);
						cnt--;
					}

				}
			}
}
int main()
{
	int ch,a;
	while(1)
	{
		//create();
		printf("\nENTER 1 to insert\n");
		printf("ENTER 2 to display\n");
		printf("ENTER 3 to delete by roll no\n");
		printf("ENTER 4 to sort\n");
		printf("ENTER 5 to search\n");
		printf("ENTER 6 to exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("ENTER 1 to insert at first\n");
				printf("ENTER 2 to insert at last\n");
				printf("ENTER 3 to insert in the middle\n");
				scanf("%d",&a);
				insert(a);
				break;
			case 2:
				display();
				break;
			case 3:
				delete();
				break;
			case 4:
				sort();
				display();
				break;
			case 5:
				search();
				break;
			case 6:
				exit(0);
				break;

		}
	}
}

