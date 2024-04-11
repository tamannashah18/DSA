#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *nxt;
}*f,*l,*nn,*t;
void insert()
{
    nn=(struct node*)malloc(sizeof(nn));
    printf("ENTER data(INTEGER):");
    scanf("%d",&nn->data);
    if(f==NULL)
    {
        f=nn;
    }
    else
    {
        l->nxt=nn;
    }
    l=nn;
    l->nxt=NULL;
}
void display()
{
    printf("THE LIST IS:\n");
    t=f;
    while(t!=NULL)
    {
        printf("%d\n",t->data);
        t=t->nxt;
    }    
}
void delete()
{
    int pos,count;
    printf("ENTER position to be deleted:");
    scanf("%d",&pos);
    if(f==NULL)
    {
        printf("EMPTY LIST\n");
    }
    else{
        if(pos==1)
        {
            t=f;
            printf("DELETED DATA %d\n",t->data);
            f=f->nxt;
            free(t);
        }
        else
        {
            t=f;
            count=1;
            while(count<pos-1)
            {
                t=t->nxt;
                count++;
            }
            printf("DELETED DATA %d\n",t->nxt->data);
            t->nxt=t->nxt->nxt;
            t=t->nxt;
            free(t);
        }
    }
}
void search()
{
    t=f;
    int data,cnt=0;
    printf("ENTER DATA TO BE SEARCHED:");
    scanf("%d",&data);
    while(t!=NULL)
    {
        cnt++;
        if(t->data==data)
        {
            printf("DATA FOUND at node : %d\n",cnt);
            cnt=-1;
            break;
        }
        t=t->nxt;
    }
    if(cnt!=-1)
        printf("NO SUCH DATA EXISTS\n");
}
void main()
{
    int ch;
    while(1)
    {
        printf("\n Enter 1 to insert node\n");
        printf("\n Enter 2 to display node\n");
        printf("\n Enter 3 to search node\n");
        printf("\n Enter 4 to delete node\n");
        printf("\n Enter 5 to exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                delete();
                break;
            case 5:
                exit(0);
        }
    }
}