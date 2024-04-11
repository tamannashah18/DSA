#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct person
{
    long int rno;
    int room_no,age;
    char name[30],city[30],state[30],dept[30], uni[30],email[30];
    char mother[30], father[30],lg_name[30], lg_email[30]; 
};
struct node{
    struct person data;
    struct node *nxt;
}*f,*l,*nn,*t;
int cnt=0;
void person_data()
{
    nn=(struct node*)malloc(sizeof(struct node));
    printf("ENTER RNO:");
    scanf("%ld",&nn->data.rno);
    printf("ENTER NAME:");
    scanf("%s",nn->data.name);
    printf("ENTER AGE:");
    scanf("%d",&nn->data.age);    
    printf("ENTER MAIL ID:");
    scanf("%s",nn->data.email);
    printf("ENTER CITY:");
    scanf("%s",nn->data.city);
    printf("ENTER STATE:"); 
    scanf("%s",nn->data.state);
    printf("ENTER UNIVERSITY NAME:");
    scanf("%s",nn->data.uni);
    printf("ENTER DEPARTMENT NAME:");
    scanf("%s",nn->data.dept);
    printf("ENTER PARENT DETAILS:\n");
    printf("ENTER FATHER'S NAME:");
    scanf("%s",nn->data.father);
    printf("ENTER MOTHER'S NAME:");
    scanf("%s",nn->data.mother);
    printf("ENTER GUARDIAN'S NAME:");
    scanf("%s",nn->data.lg_name);
    printf("ENTER GUARDIAN'S MAIL ID:");
    scanf("%s",nn->data.lg_email);
}
int check_room()
{
    t=f;
    int room_cnt=0;
    if(t!=NULL)
    {
        while(t!=NULL)
        {
            if(nn->data.room_no==t->data.room_no)
            {
                room_cnt++;
            }
            t=t->nxt;
        }
    }
    if(room_cnt==3 && f!=NULL)
        return 0;
    else    
        return 1;
}
void allotment()
{
    int allot=0;
    while(allot != 1)
    {
        printf("ENTER ROOM NO:");
        scanf("%d",&nn->data.room_no);
        if(check_room()==1)
        {
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
            allot=1;
            cnt++;
            printf("BOOKING SUCCESSFULL\n");
        }
        else
        {
            printf("ENTER OTHER ROOM NO AS THE PRIOR ROOM IS ALREADY BOOKED\n");
        }
    }
}
void sort()
{
    struct person temp;
    t=f;
    for(int i=0;i<cnt-1;i++)
    {
        t=f;
        for(int j=0;j<cnt-1-i;j++)
        {
            if(t->data.room_no>t->nxt->data.room_no)
            {
                temp=t->data;
                t->data=t->nxt->data;
                t->nxt->data=temp;
            }
            t=t->nxt;
        }
    }
}
void display_data()
{
    if(cnt!=0)
    {
        sort();
        t=f;
        printf("ROOM NO\tROLL NO\t\t NAME\t\tAGE\tCITY\tUNI\tDEPT.\tMAIL ID\n");
        
        for(int i=1;i<=cnt;i++)
        {
            printf("%d\t%ld\t%s\t%d\t%s\t%s\t%s\t%s\n",t->data.room_no,t->data.rno,t->data.name,t->data.age,t->data.city,t->data.uni,t->data.dept,t->data.email);
            t=t->nxt;
        }
    }

}
int search()
{
    char n[30];
    long int r;
    printf("Enter NAME to be searched ");
    scanf("%s",n);
    printf("Enter ROLL NO of the name to be searched");
    scanf("%ld",&r);
    if(f!=NULL)
    {
        t=f;
        int rec=0;
        for(int i=1;i<=cnt;i++)
        {
            if(t->data.rno==r && strcmp(t->data.name,n)==0)
            {
                printf("\nROOM NO\tROLL NO\t NAME\t\tAGE\tCITY\tUNIVERSITY\tDEPT.\tMAIL ID\n");
                printf("%d\t%ld\t%s\t%d\t%s\t%s\t%s\t%s\n",t->data.room_no,t->data.rno,t->data.name,t->data.age,t->data.city,t->data.uni,t->data.dept,t->data.email);
                printf("\nPARENT DETAILS\n");
                printf("FATHER\tMOTHER\tGUARDIAN\tGUARDIAN'S MAIL ID\n");
                printf("%s\t%s\t%s\t%s\n",t->data.father,t->data.mother,t->data.lg_name,t->data.lg_email);
                rec=i;
                break;
            }
            t=t->nxt;
        }
        if(rec==0)
        {
            printf("NO SUCH RECORD EXIST\n");
            return 0;
        }
        else
            return rec;
    }
}
void delete()
{
    t=f; 
    int i=1;
    int temp=search();
    if(temp!=0)
    {
        if(temp==1)
        {
            t=f;
            f=f->nxt;
            free(t);
        }
        while(i<temp-1)
        {
            t=t->nxt;
            i++;
        }
        if(temp==cnt)
        {
            free(l);
            l=t;
            l->nxt=NULL;
        }
        else
        {
            nn=t->nxt;
            t->nxt=t->nxt->nxt;
            free(nn);
        }
        cnt--;
        printf("CANCELLATION SUCCESSFULL\n");
    }

}
void main()
{
    int ch,temp;
    while(1)
    {
        printf("\nENTER 1 FOR BOOKING\n");
        printf("ENTER 2 FOR DISPLAYING ROOM WISE ALLOTMENTS\n");
        printf("ENTER 3 FOR CANCELLATION\n");
        printf("ENTER 4 FOR SEARCHING DATA (By name & roll no.)\n");
        printf("ENTER 5 FOR EXIT\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                person_data();
                allotment();
                break;
            case 2:
                display_data();
                break;
            case 3:
                delete();
                break;
            case 4:
                temp=search();
                break;
            case 5:
                exit(0);
        }
    }
}