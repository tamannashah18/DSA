#include<stdio.h>
#include<stdlib.h>

void create();
void insertf();
void insertm();
void insertl();
void deletef();
void deletem();
void deletel();
void display();
struct node
{
	int data;
	struct node *next;
}*first,*last,*nn,*temp,*cur,*prev;

int value,ch;

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
		printf("\n8.exit");	
		printf("\nenter choice");
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
			exit(0);
			break;
		}
	}
}

void create()
{
	value = 0;
	printf("\nenter value : -1 to end (: : ");
	scanf("%d",&value);
	while(value!=-1)
	{
		nn=(struct node *)malloc(sizeof(struct node));
		nn->data=value;
		nn->next=NULL;
		if(first==NULL)
		{
			first=nn;
			last=nn;
		}
		else
		{
			last->next=nn;
			last=nn;
			last->next=first;
		}
		printf("\nenter value : -1 to end (: : ");
		scanf("%d",&value);
	}
}
void insertf()
{
	value = 0;
	printf("\nenter value : ");
	scanf("%d",&value);
	nn=(struct node *)malloc(sizeof(struct node));
	nn->data=value;
	nn->next=first;
	first=nn;
	last->next=first;
}
void insertm()
{
	int cnt,pos;
	printf("\nenter the pos : ");
	scanf("%d",&pos);
	cnt=1;
	printf("\nenter value : ");
	scanf("%d",&value);
	nn=(struct node *)malloc(sizeof(struct node));
	nn->data=value;
	nn->next=NULL;
	cur=first;
	prev=NULL;
	while(cnt!=pos)
	{
		prev=cur;
		cur=cur->next;
		cnt++;
	}
	prev->next=nn;
	nn->next=cur;
}
void insertl()
{
	printf("\nenter value : ");
	scanf("%d",&value);
	nn=(struct node *)malloc(sizeof(struct node));
	nn->data=value;
	last->next=nn;
	last=nn;
	nn->next=first;
}
void deletef()
{
    if (first == NULL)
    {
        printf("\nList is Empty");
    }
    else
    {
        printf("\ndeleted value : %d", first->data);
        temp = first;
        first = first->next;
        if (temp == last) // If there was only one node
        {
            first = last = NULL; // Reset both first and last
        }
        free(temp);
        if (first != NULL)
        {
            last->next = first; // Update last->next to maintain circularity
        }
    }
}

void deletem()
{
	int cnt,pos;
	printf("\nenter the pos : ");
	scanf("%d",&pos);
	cnt=1;
	cur=first;
	prev=NULL;
	while(cnt!=pos)
	{
		prev=cur;
		cur=cur->next;
		cnt++;
	}
	printf("deleted element %d",cur->data);
	if(cur==last)
	{
		free(last);
		last=prev;
		last->next=NULL;
	}
	else
	{
		prev->next=cur->next;
		free(cur);
	}
}
void deletel()
{
	if(first==NULL)
	{
		printf("\nList is Empty");
	}
	else
	{
		printf("\ndeleted value : %d",last->data);
		temp=first;
		while(temp->next!=last)
		{
			temp=temp->next;
		}
		free(last);
		last=temp;
		last->next=first;
	}
}
void display()
{
	temp=first;
	do
	{
		printf("\nLink list value : %d",temp->data);
		temp=temp->next;
	}while(temp!=first);
}