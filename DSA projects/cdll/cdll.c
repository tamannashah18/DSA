#include<stdio.h>
#include<stdlib.h>
struct node
{
    int no;
    struct node *left,*right;
}*l,*f,*nn,*t;
int cnt=0;
void insert()
{
    int ch,pos,count;
    nn=(struct node*) malloc(sizeof(struct node));
    printf("INSERT NO:");
    scanf("%d",&nn->no);
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
                nn->right=f;
                f->left=nn;
                f=nn;
                f->left=l;
            }
            cnt++;
            break;
        case 2:
            if(f==NULL)
                f=l=nn;
            else{
                l->right=nn;
                nn->left=l;
                l=nn;
                l->right=f;
            }            
            cnt++;
            break;
        case 3:
            printf("ENTER POSITION");
            scanf("%d",&pos);
            count=1;
            if(f==NULL)
            {
                f=l=nn;
                cnt++;
            }
            else if(pos==cnt+1)
            {
                l->right=nn;
                nn->left=l;
                l=nn;
                 l->right=f;
                cnt++;
            }
            else if(pos>0 && pos<=cnt)
            {
                t=f;
                while(pos>count)
                {
                    t=t->right;
                    count++;
                }
                nn->right=t;
                t->left->right=nn;
                nn->left=t->left;
                t->left=nn;
                cnt++;
            }
            else if(pos==1)
            {
                nn->right=f;
                f->left=nn;
                f=nn;
                f->left=l;
                cnt++;     
            }
            else{
                printf("INVALID POSITION\n");
            }
            break;
        default:
                printf("INVALID INPUT");
                break;

    }
}
void delete()
{
    int ch,pos,count;
    printf("ENTER 1 for delete at first\n");
    printf("ENTER 2 for delete at last\n");
    printf("ENTER 3 for delete at position\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            if(f==NULL)
                printf("EMPTY LIST\n");
            else
            {
                f=f->right;
                free(f->left);
                f->left=l;
                l->right=f;
                cnt--;  
            }
            break;
        case 2:
            if(f==NULL)
                printf("EMPTY LIST\n");
            else
            {
                l=l->left;
                free(l->right);
                l->right=f;
                f->left=l;
                cnt--;
            }         
            break;
        case 3:
            printf("ENTER POSITION");
            scanf("%d",&pos);
            count=1;
            if(f==NULL)
            {
                printf("EMPTY LIST \n");
            }
            else if(pos==cnt+1)
            {
                l=l->left;
                free(l->right);
                l->right=f;
                f->left=l;
                cnt--;
            }
            else if(pos>0 && pos<=cnt)
            {
                t=f;
                while(pos>count)
                {
                    t=t->right;
                    count++;
                }
                t->right->left=t->left;
                t->left->right=t->right;
                free(t);
                cnt--;
            }
            else if(pos==1)
            {
                f=f->right;
                free(f->left);
                f->left=l;
                l->right=f;
                cnt--;  
            }                                   
            else
            {
                printf("INVALID POSITION\n");
            }
            break;
        default:
                printf("INVALID INPUT");
                break;

    }
    
}
void display()
{
    if(f!=NULL)
    {
        int ch;
        printf("ENTER 1 to display first to last\n");
        printf("ENTER 2 to display last to first\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                t=f;
                do
                {
                    printf("DATA IS: %d\n",t->no);
                    t=t->right;
                }while(t!=f);
                break;
            case 2:
                t=l;
                do
                {
                    printf("DATA IS: %d\n",t->no);
                    t=t->left;
                }while(t!=l);
                break;
            default:
                printf("INVALID INPUT");
                break;
        }
    }
}
void main()
{
    int ch;
    while(1)
    {
        printf("\nENTER 1 for insert\n");
        printf("ENTER 2 for delete\n");
        printf("ENTER 3 for display\n");
        printf("ENTER 4 to exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
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