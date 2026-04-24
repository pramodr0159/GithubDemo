#include <stdio.h> #include <ctype.h>
#define SIZE 10 /* Size of Stack */
char stack [SIZE]; /* Global declarations of stack and its top*/
int top = -1;
void push (char symbol)
{
stack [++top] = symbol;
}
char pop ()
{
return ( stack [top--] );
}
int priority (char op) /* Function for precedence */
{
switch (op)
{
case '#': return 0;
case '(': return 1; case '+':
case '-': return 2;
case '*':
case '/': return 3;
}
}
void infixToPostfix (char infix[], char postfix [] )
{
char symbol, brace; int i = 0, k = 0;
push ('#'); /* Mark bottom of stack */
while ( ( symbol = infix[i++] ) != '\0')
{
if ( isalnum (symbol) ) postfix [k++] = symbol;
else if (symbol == '(') push (symbol);
else if (symbol == ')')
{
while (stack[top] != '(')
postfix [k++] = pop ();
brace = pop (); /* Remove open brace '(' */
}
else /* Operator */
{
while ( priority(stack[top]) >= priority(symbol) ) postfix [k++] = pop ();
push (symbol);
}
}
while (stack[top] != '#' ) /* Pop() from stack till empty */ postfix [k++] = pop ();
postfix[k] = '\0';
}
void main()
{
char infix [50], postfix [50];
top = -1; /* Initialize stack to empty */ printf ("\n Input the Infix Expression: ");
scanf ("%s", infix); /* Read infix expression */
infixToPostfix (infix, postfix); /* Convert the expression */ printf ("\n Postfix Expression: %s", postfix); /* Display postfix expression */
}