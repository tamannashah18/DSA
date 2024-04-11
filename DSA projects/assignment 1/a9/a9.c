#include<stdio.h>
void main()
{
	int ch,n,i,j,r,c,index,m,add;
	printf("ENTER 1 for 1D array\n");
	printf("ENTER 2 for 2D array\n");
	scanf("%d",&ch);
	if(ch==1)
	{
		printf("ENTER NO OF ELEMENTS");
		scanf("%d",&n);
		int a[n];
		for(i=0;i<n;i++)
		{
			printf("ENTER ELEMENT");
			scanf("%d",&a[i]);
		}
		printf("ARRAY IS \n");
		for(i=0;i<n;i++)
		{
			printf("%d\t",a[i]);
		}
		printf("\nENTER POSITION OF THE ELEMENTS TO FIND ADDRESS");
		scanf("%d",&index);
		if(index>n|index<=0)
			printf("invalid index");
		else
		{
			add= &a[0]+sizeof(int)*(index-1);
			printf("ADDRESS OF ELEMENT IS %d",add);
		}
	}
	else if(ch==2)
	{

		printf("ENTER NO OF ROWS AND COLUMNS");
		scanf("%d%d",&r,&c);
		int a[r][c];
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				printf("ENTER ELEMENT");
				scanf("%d",&a[i][j]);
			}
		}
		printf("ARRAY IS \n");
		for(i=0;i<r;i++)
				{
					for(j=0;j<c;j++)
					{
						printf("%d",a[i][j]);
					}
					printf("\n");
				}
		printf("ENTER ROW AND COLUMN OF THE ELEMENT TO FIND ADDRESS");
		scanf("%d%d",&m,&n);
		if((n>r|n<=0)&&(m>c|m<=0))
			printf("invalid index");
		else
		{
			add=&a[0][0]+sizeof(int)*(r*(n-1)+(m-1));
			printf("ADDRESS OF ELEMENT IS %d",add);
		}

	}
	else
	{
		printf("invalid input");
	}
}

