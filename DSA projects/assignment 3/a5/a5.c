//doubly
#include<stdio.h>
#include<stdlib.h>
struct node{
	int no;
	struct node *left,*right;
}*f,*l,*nn,*t;
int cnt=0;
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
				f->left=nn;
				nn->right=f;
			}
			f=nn;
			cnt++;
			break;
		case 2:
			if(l==NULL)
			{
				f=nn;
			}
			else
			{
				l->right=nn;
				nn->left=l;
			}
			l=nn;
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
					l->right=nn;
					nn->left=l;
					l=nn;
				}
				else if(pos==1)
				{
					f->left=nn;
					nn->right=f;
					f=nn;
				}
				else
				{
					t=f;
					i=1;
					while(i<pos)
					{
						t=t->right;
						i++;
					}
					nn->right=t;
					nn->left=t->left;
					t->left->right=nn;
					t->left=nn;
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
	int i=1,ch;
	if(f!=NULL)
	{
		printf("ENTER 1 to display from 1st to last node\n");
		printf("ENTER 2 to display from last to 1st node\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				t=f;
				while(t!=l)
				{
					printf("NODE %d DATA IS: %d\n",i++,t->no);
					t=t->right;
				}
				printf("NODE %d DATA IS: %d\n",i++,t->no);
				break;
			case 2:
				t=l;
				while(t!=f)
				{
					printf("NODE %d DATA IS: %d\n",i++,t->no);
					t=t->left;
				}
				printf("NODE %d DATA IS: %d\n",i++,t->no);
				break;
			default:
				printf("INVALID INPUT\n");
				break;
		}
	}
	else
		printf("LIST IS EMPTY\n");
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
				f=f->right;
				f->left=NULL;
				free(t);
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
				t=l;
				printf("THE DELETED NODE's DATA IS %d",l->no);
				free(t);
				l=l->left;
				l->right=NULL;
				cnt--;
			}
			break;
		case 3:
			printf("Enter position to enter data: (1 to %d)",cnt);
			scanf("%d",&pos);
			if(f==NULL)
			{
				printf("LINKED LIST IS EMPTY\n");
			}
			else if(pos>0 && pos<=cnt)
			{

				if(pos==cnt)
				{
					t=l;
					printf("THE DELETED NODE's DATA IS %d",l->no);
					free(t);
					l=l->left;
					l->right=NULL;
					cnt--;
				}
				else if(pos==1)
				{
					t=f;
					printf("THE DELETED NODE's DATA IS %d",t->no);
					f=f->right;
					f->left=NULL;
					free(t);
					cnt--;
				}
				else
				{
					t=f;
					int i=1;
					while(i<pos)
					{
						t=t->right;
						i++;
					}
					printf("THE DELETED NODE's DATA IS %d",t->no);
					t->left->right=t->right;
					t->right->left=t->left;
					free(t);
				}
				cnt--;
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
