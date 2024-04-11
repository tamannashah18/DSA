#include<stdio.h>
int n;
struct stud{
	int rno;
	char name[20];
	float sgpa;
}temp,s[50];
void input()
{
	printf("INSERT DATA\n");
	for(int i=0;i<n;i++)
	{
		printf("ENTER ROLL NO:");
		scanf("%d",&s[i].rno);
		printf("ENTER NAME:");
		scanf("%s",s[i].name);
		printf("ENTER SGPA:");
		scanf("%f",&s[i].sgpa);
	}
}
void sort()
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(s[j].sgpa < s[j+1].sgpa)
			{
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
		}
	}
	printf("\nSorted values according to sgpa in descending order\n");
	display();
}
void display()
{
	printf("STUDENT DETAILS\nROLL NO\tNAME\tSGPA\n");
	for(int i=0;i<n;i++)
	{
		printf("\n%d\t",s[i].rno);
		printf("%s\t",s[i].name);
		printf("%f\t",s[i].sgpa);
	}
}
void main()
{
	printf("ENTER NO OF INPUTS");
	scanf("%d",&n);
	input();
	display();
	sort();
}
