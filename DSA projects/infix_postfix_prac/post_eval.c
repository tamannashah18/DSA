#include "infix.c"
#include<stdlib.h>
#include<stdio.h>
int s[20],t=-1;
int pop_post()
{
    return s[t--];
}
void post_push(int a)
{
    s[++t]=a;
}
void eval_post()
{
    int i=0,op1,op2;
    char temp1;
    while(postfix[i]!='\0')
    {
        if(postfix[i]!='+'&&postfix[i]!='-'&&postfix[i]!='*'&&postfix[i]!='/')
        {
            temp1=postfix[i];
            op1=atoi(&temp1);
            post_push(op1);
        }
        else
        {
            op2=pop_post();
            op1=pop_post();
            switch(postfix[i])
            {
                case '+':
                    post_push(op1+op2);
                    break;
                    
                case '-':
                    post_push(op1-op2);
                    break;
                    
                case '*':
                    post_push(op1*op2);
                    break;
                    
                case '/':
                    post_push(op1/op2);
                    break;
            }
        }
        i++;
    }
}
void main()
{
    printf("Enter infix expression:");
    scanf("%s",infix);
    infix_post();
    eval_post();
    printf("\nRESULT : %d ",s[t]);
}
