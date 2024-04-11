#include<stdio.h>
#include<stdlib.h>
struct node{
	int no;
	struct node *nxt;
}*f,*l,*nn,*c,*t,*p;
int cnt=1;
void insert(int a)
{
	int pos,i;
	nn=(struct node*)malloc(sizeof(struct node));
	printf("ENTER NO: ");
	scanf("%d",&nn->no);
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
			l->nxt=f;
			cnt++;
			break;
		case 2:
			if(l==NULL)
			{
				f=l=nn;
			}
			else
			{
				l->nxt=nn;
			}
			l=nn;
			l->nxt=f;
			cnt++;
			break;
		case 3:
			printf("Enter position to enter data: (1 to %d)",cnt+1);
			scanf("%d",&pos);
			if(f==NULL)
			{
				printf("LINKED LIST IS EMPTY\nSO DATA INSERTED AT NODE 1");
				f=l=nn;
				l->nxt=f;
				cnt++;
			}
			else if(pos>0 && pos<=cnt+1)
			{

				if(pos==cnt+1)
				{
					l->nxt=nn;
					l=nn;
					l->nxt=f;
				}
				else if(pos==1)
				{
					nn->nxt=f;
					f=nn;
					l=nn;
					l->nxt=f;
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
	if(f!=NULL)
	{
		printf("THE DATA OF LINKED LIST IS:-\n");
		t=f;
		int i=1;
		do
		{
			printf("NODE %d DATA IS: %d\n",i++,t->no);
			t=t->nxt;
		}while(t!=f);
	}
	else
		printf("LIST IS EMPTY");
}
void delete(int a)
{
	int pos;
	switch(a)
	{
		case 1:
			if(f==NULL)
			{
				printf("LINKED LIST IS EMPTY\n");
			}
			else
			{
				t=f;
				printf("THE DELETED NODE's DATA IS %d",t->no);
				f=f->nxt;
				free(t);
				l->nxt=f;
				cnt--;
			}
			break;
		case 2:
			if(l==NULL)
			{
				printf("LINKED LIST IS EMPTY\n");
			}
			else
			{
				t=f;
				printf("THE DELETED NODE's DATA IS %d",l->no);
				while(t->nxt!=l)
				{
					t=t->nxt;
				}
				free(l);
				l=t;
				l->nxt=f;
				cnt--;
			}
			break;
		case 3:
			printf("Enter position to delete data: (1 to %d)",cnt);
			scanf("%d",&pos);
			if(f==NULL)
			{
				printf("LINKED LIST IS EMPTY\n");
			}
			else if(pos>0 && pos<=cnt)
			{

				if(pos==cnt)
				{
					t=f;
					printf("THE DELETED NODE's DATA IS %d",l->no);
					while(t->nxt!=l)
					{
						t=t->nxt;
					}
					free(l);
					l=t;
					l->nxt=f;
					cnt--;
				}
				else if(pos==1)
				{
					t=f;
					printf("THE DELETED NODE's DATA IS %d",t->no);
					f=f->nxt;
					l->nxt=f;
					free(t);
					cnt--;
				}
				else
				{
					c=f;
					int i=1;
					while(i<pos)
					{
						p=c;
						c=c->nxt;
						i++;
					}
					printf("THE DELETED NODE's DATA IS %d",c->no);
					p->nxt=c->nxt;
					free(c);

					cnt--;
				}
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
int main()
{
	int ch,a;
	while(1)
	{
		printf("\nENTER 1 to insert\n");
		printf("ENTER 2 to display\n");
		printf("ENTER 3 to delete\n");
		printf("ENTER 4 to exit\n");
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
				printf("ENTER 1 to delete first node\n");
				printf("ENTER 2 to delete last node\n");
				printf("ENTER 3 to delete by position\n");
				scanf("%d",&a);
				delete(a);
				break;
			case 4:
				exit(0);
				break;

		}
	}
}

