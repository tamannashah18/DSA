#include<stdio.h>
#include<stdlib.h>
int top=-1,a[100],n;
void push()
{
	if(top==(n-1))
	{
		printf("\nSTACK OVERFLOW HENCE NO ELEMENT CAN BE PUSHED");
	}
	else
	{
		int val;
		printf("\nENTER VALUE TO BE INSERTED");
		scanf("%d",&val);
		top++;
		a[top]=val;
		printf("\nCURRENT STATUS OF STACK");
		display();
	}
}
void pop()
{

	if(top==-1)
	{
		printf("\nSTACK IS EMPTY HENCE NO ELEMENT CAN BE POPPED");
	}
	else
	{
		printf("\nSTACK BEFORE POP");
		display();
		top--;
		printf("\nSTACK AFTER POP");
		display();
	}
}
void peep()
{
	if(top==-1)
	{
		printf("\nSTACK IS EMPTY");
	}
	else
	{
		int pos,i,cnt=0;
		printf("ENTER POSITION TO BE SEARCHED");
		scanf("%d",&pos);
		if(pos<=top+1)
			printf("THE %d th element from top is %d",pos,a[top-pos+1]);
		else
			printf("PEEP operation not possible");

	}
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("\nSTACK IS EMPTY");
	}
	else
	{
		for(i=0;i<=top;i++)
		{
			printf("\n%d",a[i]);
		}
	}
}
int main()
{
	int ch=0;
	printf("ENTER SIZE OF THE STACK");
	scanf("%d",&n);
	if(n<=0)
	{
		printf("INVALID SIZE");
		exit(0);
	}
	while(1)
	{
		printf("\nENTER 1 to push\n");
		printf("ENTER 2 to pop\n");
		printf("ENTER 3 to peep\n");
		printf("ENTER 4 to display\n");
		printf("ENTER 5 to exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				peep();
				break;
			case 4:
				display();
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("INVALID INPUT\n");
				break;
		}
	}
	return 0;
}
