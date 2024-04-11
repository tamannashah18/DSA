#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int stack[10],i=0,j=0,top=-1,op1,op2;
char post[50],temp[10];
int pop()
{
    return stack[top--];
}
void push(int val)
{
    stack[++top]=val;
}
void main()
{
    printf("Enter postfix expression(separate with comma)");
    scanf("%s",post);
    while(post[i]!='\0')
    {
        if(post[i]=='/')
        {
                op2=pop();
                op1=pop();              
                push(op1/op2);
        }
        else if(post[i]=='*')
        {
                op2=pop();
                op1=pop();
                push(op1*op2);
        }
        else if(post[i]=='+')
        {     
                op2=pop();
                op1=pop();    
                push(op1+op2);
        }
        else if(post[i]=='-')
        {
                op2=pop();
                op1=pop();
                push(op1-op2);
        }           
        else
        {
                if(post[i]!=',')
                {
                    j=0;
                    while(post[i]!=',')
                    {                      
                        temp[j++]=post[i++];
                    }
                    op1=atoi(temp);
                    push(op1);
                    j=0;
                    while(temp[j]!='\0')
                    {
                        temp[++j]='\0';
                    }
                }
        }
        i++;
    }
    printf("\nEVALUATED EXPRESSION: %d",stack[top]);
}
 