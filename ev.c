
#include<stdio.h>
char expr[20];
char stack[20];int precedence(char a,char b)
{
    if(((a=='+')||(a=='-'))&&((b=='*')||(b=='/')))
    return 0;
    else
    return 1;
}
int i;
int ctr;
int top=-1;
int topOper=-1;
int operate(int a,int b,char oper)
{
    int res=0;
switch(oper)
{
    case '+':res=a+b;break;
    case '-':res=a-b;break;
    case '*':res=a*b;break;
    case '/':res=a/b;break;
}
return res;
}
void postfixConvert()
{
char topsymb,operatorStack[20];
ctr=0;
while(expr[ctr]!='\0')
{
if(expr[ctr]>='0'&&expr[ctr]<='9')
stack[++top]=expr[ctr];
else
{
while(topOper>=0&&precedence(operatorStack[topOper],expr[ctr]))
{
topsymb=operatorStack[topOper--];
stack[++top]=topsymb;
}
operatorStack[++topOper]=expr[ctr];
}
ctr++;
}
while(topOper>=0)
stack[++top]=operatorStack[topOper--];
printf("The Resulting Postfix expression for the given infix expression\n%s\n",stack);
}
int main()
{
printf("\t\tExpression Evaluator\n");
printf("This Program Evaluates Basic Expressions(without brackets) with arithmetic operations(+,-,*,/) on single digit operand length below 20\n");
printf("Enter the Expression\n");
scanf("%s",expr);
postfixConvert();
char oper;
int operand1,operand2;
ctr=0;
int result[2];
int rTop=-1;
while(stack[ctr]!='\0')
{
oper=stack[ctr];
if(oper>='0'&&oper<='9')
result[++rTop]=(int)(oper-'0');
else
{
    operand1=result[rTop--];
    operand2=result[rTop--];
    result[++rTop]=operate(operand2,operand1,oper);
}
ctr++;
}
printf("The result of the expression is\n%d\n",result[0]);
getch();
}
