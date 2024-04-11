#include<stdio.h>
char infix[20],postfix[20],stack[20],temp;
int i=0,j=0,top=-1;
void push(char a)
{
    stack[++top]=a;
}
char pop()
{
    return stack[top--];
}
void infix_post()
{
    while(infix[i]!='\0')
    {
        switch(infix[i])
        {
            case '(':
                push(infix[i++]);
                break;
            case '+':
            case '-':
                while(stack[top]=='+'||stack[top]=='-'||stack[top]=='/'||stack[top]=='*'&&stack[top]!='('&& top!=-1)
                    {
                        postfix[j++]=pop();
                    }
                push(infix[i++]);
            break;
            case '/':
            case '*':
                while(stack[top]=='/'||stack[top]=='*'&& stack[top]!='('&& top!=-1)
                {
                        postfix[j++]=pop();
                }
                push(infix[i++]);
            break;
            case')':
                while(stack[top]!='('&& top!=-1)
                {
                        postfix[j++]=pop();
                }
                i++;
                break;
            default:
                postfix[j++]=infix[i++];
                break;
        }
    }
    while(top!=-1)
    {
        temp=pop();
            if(temp!='(')
                postfix[j++]=temp;
    }
    printf("\nPOSTFIX EXPRESSION = %s",postfix);
}