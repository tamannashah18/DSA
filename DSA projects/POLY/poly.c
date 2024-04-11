#include<stdio.h>
#include<stdlib.h>
struct poly
{
    int coeff,exp,add;
    struct poly *next;
}*last1,*first1,*first2,*last2,*first3,*last3,*temp1,*nn,*poly1,*poly2,*poly3,*temp;
int ch,cnt=0,check=0,cnt1=0,i,j,cnt2=0;
void insert()
{
    nn=(struct poly*)malloc(sizeof(struct poly));
    printf("Enter coeff:\n");
    scanf("%d",&nn->coeff);
    printf("Enter exp:\n");
    scanf("%d",&nn->exp);
    printf("Enter 1 to insert in first polynomial:\n");
    printf("Enter 2 to insert in 2nd polynomial:\n");
    printf("Enter choicde:\n");
    scanf("%d",&ch);
    nn->add=0;
    switch(ch)
    {
        case 1:
        if(first1==NULL)
        {
            first1=nn;
            last1=nn;
        }
        else
        {
            last1->next=nn;
            last1=nn;
        }
        cnt++;
        break;
        case 2:
        if(first2==NULL)
        {
            first2=nn;
            last2=nn;
        }
        else
        {
            last2->next=nn;
            last2=nn;
        }
        cnt1++;
        break;    
    }
}
void add()
{
    poly1=first1;
    poly2=first2;
    poly3=first3;
    for(i=0;i<cnt;i++)
    {
        poly2=first2;
        check=0;
        for(j=0;j<cnt1;j++)
        {
            if(poly1->exp==poly2->exp)
            {
                nn=(struct poly*)malloc(sizeof(struct poly));
                nn->coeff=poly1->coeff+poly2->coeff;
                nn->exp=poly1->exp;
                if(first3==NULL)
                {
                    first3=nn;
                    last3=nn;
                    cnt2++;
                }
                else
                {
                    last3->next=nn;
                    last3=nn;
                    cnt2++;
                }
                check++;
                poly1->add=1;
                poly2->add=1;
            }
            poly2=poly2->next;
        }
            if(check==0)
            {
                nn=(struct poly*)malloc(sizeof(struct poly));
                nn->coeff=poly1->coeff;
                nn->exp=poly1->exp;
                poly1->add=1;
                if(first3==NULL)
                {
                    printf("LL CAME IN 1\n");
                    first3=nn;
                    last3=nn;
                    cnt2++;
                }
                else
                {
                    
                    printf("CAME IN 2\n");
                    last3->next=nn;
                    last3=nn;
                    cnt2++;
                }
            }
            
        poly1=poly1->next;
    }
    temp=first2;
    for(i=0;i<cnt1;i++)
    {
        if(temp->add==0)
        {
            nn=(struct poly*)malloc(sizeof(struct poly));
                nn->coeff=temp->coeff;
                nn->exp=temp->exp;
                if(first3==NULL)
                {
                    
                    first3=nn;
                    last3=nn;
                    cnt2++;
                }
                else
                { 
                    printf("CAME IN 2\n");
                    last3->next=nn;
                    last3=nn;
                    cnt2++;
                }
                temp->add=1;
        }
        temp=temp->next;
    }
}
void display()
{
    printf("1st expression:\n");
    temp=first1;
    for(i=0;i<cnt;i++)
    {
        printf("+%dx^%d\t",temp->coeff,temp->exp);
        temp=temp->next;
    }
        printf("\n");
        printf("2nd expression:\n");
    temp=first2;
        for(i=0;i<cnt1;i++)
        {
            printf("+%dx^%d\t",temp->coeff,temp->exp);
            temp=temp->next;
        }
            printf("\n");
            printf("3rd Expression:\n");
        temp=first3;
            for(i=0;i<cnt2;i++)
            {
                printf("+%dx^%d\t",temp->coeff,temp->exp);
                temp=temp->next;
            }
}
void main()
{
	do
	{
		printf("\nEnter 1 to insert:\n");
		printf("Enter 2 to add:\n");
		printf("Enter 3 to display:\n");
		printf("Enter 4 to exit:\n");
		printf("Enter choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			insert();
			break;
		case 2:
			add();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("Invalid Input");
			break;
		}
	}while(ch!=4);
}