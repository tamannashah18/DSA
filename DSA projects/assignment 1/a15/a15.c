#include<stdio.h>
#include<stdlib.h>
char post[50],ch,temp;
int i=0,top=-1,op1,op2,stack[10];
void push(int val)
{
	stack[++top]=val;
}
int pop()
{
	return stack[top--];
}
void main()
{
		i=0;
		top=-1;
		printf("ENTER POSTFIX EXPRESSION:");
		scanf("%s",post);
		while(post[i]!='\0')
		{
 			switch(post[i])
 			{
				case '/':
					op2=pop();
					op1=pop();
					push(op1/op2);
					break;
				case '*':
					op2=pop();
					op1=pop();
					push(op1*op2);
					break;
				case '+':
					op2=pop();
					op1=pop();
					push(op1+op2);
					break;
				case '-':
					op2=pop();
					op1=pop();
					push(op1-op2);
					break;
				default:
					temp=post[i];
					push(atoi(&temp));
					break;
			}
 			i++;
		}
		printf("EVALUATED OPERATION = %d",stack[top]);


}
