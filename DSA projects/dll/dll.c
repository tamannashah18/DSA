#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *right;
	struct node *left;
}*first=NULL,*last=NULL,*nn=NULL,*temp,*pre,*cur;

int ch,x,pos,cnt=0;

void create()
{
	printf("\nTo continue enter data");
	printf("\nTo exit enter -1\n");
	printf("\nEnter value : ");
	scanf("%d",&x);
	while(x != -1)
	{	
		nn=(struct node *)malloc(sizeof(struct node));
		nn->data = x;
		nn->right = NULL;
		if(first == NULL)
		{
			first = nn;
			first->right = last;
			//last->left = first;
			last = nn;
		}
		else
		{
			nn->left = last;
			last->right = nn;
			last = nn;
			nn->right = NULL;
		}
		printf("\nEnter value : ");
		scanf("%d",&x);
	}
}

void insertf()
{
	printf("\nEnter value : ");
	scanf("%d",&x);
	
	nn=(struct node *)malloc(sizeof(struct node));
	nn->data = x;
	if(first == NULL)
	{
		first = nn;
		last = nn;
		nn->right = first;
		nn->left = last;
	}
	else
	{
		nn->right = first;
		nn->left = NULL;
		first = nn;
	}
}

void insertm()
{
	if(first == NULL)
	{
		printf("\nNo Linked List Present\n");
	}
	else
	{	
		temp = first;
		while(temp != last)
		{
			temp = temp->right;
			cnt++;
		}
		cnt++;
		printf("\nEnter Position : ");
		scanf("%d",&pos);
		if(pos > cnt)
		{
			printf("\nEnter valid Position\n");
		}
		else
		{
			printf("\nEnter value : ");
			scanf("%d",&x);
			nn=(struct node *)malloc(sizeof(struct node));
			nn->data = x;
			cnt = 1;
			cur = first;
			
			while(pos != cnt)
			{
				pre = cur;
				cur = cur->right;
				cnt++;
			}
			if(cur == first)
			{
				nn->right = first;
				first->left = nn;
				first = nn;
				first->left = NULL;
			}
			else
			{
				pre->right = nn;
				nn->left = pre;
				nn->right = cur;
				cur->left = nn;
				cur->right = NULL;
			}
		}
	}
}

void insertl()
{
	printf("\nEnter value : ");
	scanf("%d",&x);
	
	nn=(struct node *)malloc(sizeof(struct node));
	nn->data = x;
	last->right = nn;
	nn->left = last;
	last = nn;
	last->right = NULL;
}

void deletef()
{
	temp = first;
	printf("\nDeleted value : %d",first->data);
	first = first->right;
	first->left = NULL;
	free(temp);
}

void deletem()
{
	if(first == NULL)
	{
		printf("\nNo Linked List Present\n");
	}
	else
	{	
		temp = first;
		while(temp != last)
		{
			temp = temp->right;
			cnt++;
		}
		cnt++;
		printf("\nEnter Position : ");
		scanf("%d",&pos);
		if(pos > cnt)
		{
			printf("\nEnter valid Position\n");
		}
		else
		{
			cnt = 1;
			cur = first;
			
			while(pos != cnt)
			{
				pre = cur;
				cur = cur->right;
				cnt++;
			}
			if(cur == first)
			{
				printf("\nDeleted value : %d",first->data);
				first = first->right;
				first->left = NULL;
				free(temp);
			}
			else if(cur == last)
			{
				printf("\nDeleted value : %d",last->data);
				last->left = pre->left;
				last = pre;
				last->right = NULL;
				free(cur);
			}
			else
			{
				printf("\nDeleted value : %d",cur->data);
				pre->right = cur->right;
				cur->right->left = pre;
				free(cur);
			}
		}
	}
}

void deletel()
{
	temp = first;
	printf("\nDeleted value : %d",last->data);
	while(temp->right != last)
	{
		temp = temp->right;
	}
	free(last);
	last->left = temp->left;
	temp->left->right = last;
	last = temp;
	last->right = NULL;
}

void display()
{
	temp = first;
	printf("\nLinked List values are : \n");
	while(temp != last)
	{
		printf("\t%d\t->",temp->data);
		temp = temp->right;
	}
	printf("\t%d",last->data);
}

void main()
{
	create();
	
	while(1)
	{
		printf("\n1.insert at first");
		printf("\n2.insert at middle");
		printf("\n3.insert at last");
		printf("\n4.delete from first");
		printf("\n5.delete from middle");
		printf("\n6.delete from last");
		printf("\n7.display");
		printf("\n8.Exit");
		printf("\n9.Enter Your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insertf();
				break;
			case 2:
				insertm();
				break;
			case 3:
				insertl();
				break;
			case 4:
				deletef();
				break;
			case 5:
				deletem();
				break;
			case 6:
				deletel();
				break;
			case 7:
				display();
				break;
			case 8:
				printf("\nThank You\nExit");
				exit(0);
				break;
		}
	}
}