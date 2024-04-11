#include<stdio.h>
int n;
struct stud{
	int rno;
	char name[20];
	float sgpa;
}s[50],temp,*p;
void input()
{
	printf("INSERT DATA\n");
	p=s;
	for(int i=0;i<n;i++)
	{
		printf("ENTER ROLL NO:");
		scanf("%d",&(p+i)->rno);
		printf("ENTER NAME:");
		scanf("%s",(p+i)->name);
		printf("ENTER SGPA:");
		scanf("%f",&(p+i)->sgpa);
	}
}
void display()
{
	p=s;
	printf("STUDENT DETAILS\nROLL NO\tNAME\tSGPA\n");
	for(int i=0;i<n;i++)
	{
		printf("\n%d\t",(p+i)->rno);
		printf("%s\t",(p+i)->name);
		printf("%f\t",(p+i)->sgpa);
	}
}

void sort()
{
	int i,j;
	p=s;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if((p+j)->sgpa < (p+j+1)->sgpa)
			{
				temp=*(p+j);
				*(p+j)=*(p+j+1);
				*(p+j+1)=temp;
			}
		}
	}
	printf("\nSorted values according to sgpa in descending order\n");
	display();
}
void main()
{

	printf("ENTER NO OF INPUTS");
	scanf("%d",&n);
	input();
	display();
	sort();
}
