#include<stdio.h>
void main()
{
	int ch=0,top=-1,i,n,temp;

	printf("ENTER SIZE OF THE STACK");
	scanf("%d",&n);
	int a[n];
	while(1)
	{
		printf("\nENTER 1 to push\n");
		printf("ENTER 2 to pop\n");
		printf("ENTER 3 to peep\n");
		printf("ENTER 4 to display(top to bottom)\n");
		printf("ENTER 5 to display(bottom to top)\n");
		printf("ENTER 6 to exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			if(top<n-1)
			{
				printf("ENTER VALUE TO BE PUSHED");
				scanf("%d",&temp);
				top++;
				a[top]=temp;
				printf("PUSH SUCESSFULL\n");
			}
			else
			{
				printf("STACK WILL BE OVERFLOWED\n");
			}
			break;
		case 2:
			if(top!=-1)
			{
				printf("POPPED ELEMENT IS %d\n",a[top]);
				top--;
			}
			else
			{
				printf("STACK WILL BE UNDERFLOWED\n");
			}
			break;
		case 3:
			if(top!=-1)
			{
				printf("ENTER POSITION OF THE ELEMENT TO BE SEARCHED");
				scanf("%d",&temp);
				if(temp<=0||temp>top)
					printf("INVALID INPUT");
				else
				{
					printf("THE VALUE AT %d from top is %d",temp,a[top-temp+1]);
					printf("PEEP SUCESSFULL\n");
				}
			}
			else
			{
				printf("STACK IS EMPTY\n");
			}
			break;
		case 4:
			if(top!=-1)
			{
				printf("STACK IS\n");
				for(i=top;i>=0;i--)
				{
					printf("%d\n",a[i]);
				}
			}
			else
			{
				printf("STACK IS EMPTY\n");
			}
			break;
		case 5:
			if(top!=-1)
			{
				printf("STACK IS\n");
				for(i=0;i<=top;i++)
				{
					printf("%d\n",a[i]);
				}
			}
			else
			{
				printf("STACK IS EMPTY\n");
			}
			break;
		case 6:
			exit(0);
			break;
		default:
			printf("INVALID INPUT");
			break;
		}
	}
}
