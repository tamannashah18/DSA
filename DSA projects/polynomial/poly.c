#include<stdio.h>
#include<stdlib.h>
struct node
{
    int exp,coeff;
    struct node *nxt;
}*f,*l,*nn,*temp,*prev,*curr;
int cnt=0;
void insert()
{
    int ch,pos,count;
    nn=(struct node*) malloc(sizeof(struct node));
    printf("INSERT coefficient:");
    scanf("%d",&nn->coeff);
    printf("INSERT exponent:");
    scanf("%d",&nn->exp); 
    printf("ENTER 1 for insert at first\n");
    printf("ENTER 2 for insert at last\n");
    printf("ENTER 3 for insert at position\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        if(f==NULL)
            f=l=nn;
        else
        {
            nn->nxt=f;
            f=nn;
        }
        cnt++;
                break;
        case 2:
            if(f==NULL)
                f=nn;
            else
                l->nxt=nn;
            l=nn;
            cnt++;
            break;
        case 3:
                printf("ENTER POSITION");
                scanf("%d",&pos);
                count=1;
                curr=f;
                if(pos==1)
                {
                    if(f==NULL)
                        f=l=nn;
                    else
                    {
                        nn->nxt=f;
                        f=nn;
                    }  
                    cnt++;
                }
                else if(pos==cnt+1)
                {
                    if(f==NULL)
                        f=nn;
                    else
                        l->nxt=nn;
                    l=nn;
                    cnt++;     
                }
                else if(pos>cnt+1)
                    printf("INVALID POSITION\n");
                else
                {
                    while(count<pos)
                    {
                        prev=curr;
                        curr=curr->nxt;
                        count++;
                    }
                    nn->nxt=curr;
                    prev->nxt=nn;
                    cnt++;
                }
            break;
        default:
            printf("INVALID INPUT");
            break;

    }
}
void display()
{
    if(f==NULL)
        printf("EMPTY");
    else
    {
        temp=f;
        while(temp!=l)
        {
            printf("EXPONENT : %d\n",temp->exp);
            printf("COEFFICIENT : %d\n",temp->coeff);
            temp=temp->nxt;
        }
        printf("EXPONENT : %d\n",temp->exp);
        printf("COEFFICIENT : %d\n",temp->coeff);

    }
}
void delete()
{
    int pos,ch,count;
    if(f==NULL)
        printf("EMPTY");
    else
    {
        printf("ENTER 1 for DELETE at first\n");
        printf("ENTER 2 for DELETE at last\n");
        printf("ENTER 3 for DELETE at position\n");
        printf("ENTER 4 to exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                temp=f;
                f=f->nxt;
                free(temp);
                cnt--;
                break;
            case 2:
                temp=f;
                while(temp->nxt!=l)
                {
                    temp=temp->nxt;
                }
                free(l);
                l=temp;
                l->nxt=NULL;
                cnt--;
                break;
            case 3:
                printf("ENTER POSITION");
                scanf("%d",&pos);
                if(pos==1)
                {
                    temp=f;
                    f=f->nxt;
                    free(temp);
                    cnt--;
                }
                else if(pos==cnt+1)
                {
                    temp=f;
                    while(temp->nxt!=l)
                    {
                        temp=temp->nxt;
                    }
                    free(l);
                    l=temp;
                    l->nxt=NULL;
                    cnt--;
                }
                else if(pos>cnt+1)
                {
                    printf("INVALID POSITION");
                }
                else
                {
                    count=1;
                    curr=f;
                    while(count<pos)
                    {
                        prev=curr;
                        curr=curr->nxt;
                        count++;
                    }   
                    prev->nxt=curr->nxt;
                    free(curr);
                    cnt--;
                    
                }


        }
    }

}
void main()
{
    int ch,no;
    while(1)
    {
        printf("\nENTER 1 to insert a new node\n");
        printf("ENTER 2 to display sll\n");
        printf("ENTER 3 delete node\n");
        printf("ENTER 4 exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insert();
                break;
            case 2:
                display();
            break;
            case 3:
                delete();
                break;
            case 4:
                exit(0);
            break;
            default:
                printf("INVALID INPUT");
                break;
        }
    }
}