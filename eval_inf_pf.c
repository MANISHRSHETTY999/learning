#include<stdio.h>
#include<ctype.h>
#include<math.h>
#define MAX 20

void push(int s[MAX], int *top, int elem)
{
    if(*top == MAX - 1)
    {
        printf("Stack is full.\n");
        return;
    }
    (*top)++;
    s[*top] = elem;
}

int pop(int s[MAX], int *top)
{
    int elem;
    elem = s[*top];
    (*top)--;
    return elem;
}

int compute(int op1, char op, int op2)
{
   switch(op)
   {
      case '+': return op1 + op2;
      case '-': return op1 - op2;
      case '*': return op1 * op2;
      case '/': return op1 / op2;
      case '%': return op1 % op2;
      case '^': return pow(op1, op2);
      default: return 0;
   }
}
int main()
{
    int s[MAX], top = -1, res, op1, op2, symbol;
    char postfix[20];
    printf("Enter the postfix expression: \n");
    scanf("%s", postfix);
    for(int i=0; postfix[i] != '\0'; i++)
    {
        symbol = postfix[i];
        if(isdigit(symbol))
        {
            push(s, &top, symbol-'0');
        }
        else
        {
            op2 = pop(s, &top);
            op1 = pop(s, &top);
            res = compute(op1, symbol, op2);
            push(s,&top,res);
        }
    }
    printf("Result = %d\n", pop(s,&top));
}

