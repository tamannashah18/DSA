#include<stdio.h>
#include<stdlib.h>
int stack[10],i=0,j=0,top=-1,op1,op2;
char s[50],infix[50],post[50],temp;
void i_push(char val)
{
    s[++top]=val;
}
char i_pop()
{
    if(top!=-1)
       return s[top--];
    else
        return '\0';
}

int pop()
{
    if(top!=-1)
         return stack[top--];
    else
         return 0; 
}
void push(int val)
{
    stack[++top]=val;
}       

void postfix()
{
    switch(infix[i])
          {
            case '/':
            case '*':
                while((s[top]=='*'||s[top]=='/') && top!=-1)
                {
                    post[j++]=i_pop();
                }
                i_push(infix[i++]);
            break;
            case '+':
            case '-':
                while((s[top]=='*'||s[top]=='/'||s[top]=='+'||s[top]=='-' )&& top!=-1)
                {
                    post[j++]=i_pop();
                }
                i_push(infix[i++]);
            break;
            default:
                post[j++]=infix[i++];
            break;
           }
}
void main()
{
    printf("Enter Infix expression(NUMERICAL)");
    scanf("%s",infix);
    while(infix[i]!='\0')
    {
        if(infix[i]=='(')
        {
            i_push(infix[i++]);
        }
        else if(infix[i]==')')
        {
            while(stack[top]!='(' && top!=-1)
            {   
                temp=i_pop();
                if(temp!='(')
                    post[j++]=temp;
            }
            i++;
        }
        else
        {
            postfix();
        }
    }
    while(top!=-1)
    { 
        post[j++]=i_pop();
    }
    printf("POSTFIX EXPRESSION : %s",post);
    i=0;
    //evalutation
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
                    temp=post[i];
                    op1=atoi(&temp);
                    push(op1);
        }
        i++;
    }
    printf("\nEVALUATED EXPRESSION: %d",stack[top]);
}
