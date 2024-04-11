#include<stdio.h>
	char infix[50],post[50],s[50];
	int i=0,top=-1,j=0;
void push(char val)
{
		s[++top]=val;
}
char pop()
{
	return s[top--];
}
void main()
{
	printf("ENTER INFIX EXPRESSION");
	scanf("%s",infix);
	while(infix[i]!='\0')
	{
		switch(infix[i])
		{
			case '/':
			case '*':
				while((s[top]=='/' || s[top]=='*') && top!=-1)
				{
					post[j++]=pop();
				}
				push(infix[i++]);
				break;
			case '+':
			case '-':
				while((s[top]=='+' || s[top]=='-'||s[top]=='/' || s[top]=='*')&&top!=-1)
				{
					post[j++]=pop();
				}
				push(infix[i++]);
				break;
			default:
				post[j++]=infix[i++];
		}
	}
	while(top!=-1)
		post[j++]=pop();
	printf("POSTFIX = %s",post);

}
