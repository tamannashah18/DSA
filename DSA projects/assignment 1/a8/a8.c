#include<stdio.h>
void main()
{
	int n,sub,i,j,k;
	printf("ENTER no of students");
	scanf("%d",&n);
	printf("ENTER no of subjects");
	scanf("%d",&sub);
	float marks[n][sub][2];
	for(i=0;i<n;i++)
		{
			printf(" ENTER MARKS OF STUDENT with roll no %d\n",i+1);
			for(j=0;j<sub;j++)
			{
				printf("SUBJECT %d\n",j+1);
				for(k=0;k<2;k++)
				{
					if(k==0)
						printf("INTERNAL");
					else
						printf("EXTERNAL");
					scanf("%f",&marks[i][j][k]);
				}
			}
		}
	for(i=0;i<n;i++)
		{
			printf("ROLL NO %d",i+1);
			for(j=0;j<sub;j++)
			{
				printf("\tSUBJECT %d\n",j+1);
				for(k=0;k<2;k++)
				{
					if(k==0)
						printf("INTERNAL:");
					else
						printf("EXTERNAL:");
					printf("%f",marks[i][j][k]);
				}
			}
		}
}
