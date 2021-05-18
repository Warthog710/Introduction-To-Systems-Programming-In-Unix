#include <stdio.h>

int main (void)

{

int op1 = 0;
int op2 = 0;
int sum = 0;

char operator = '+';

printf("Please enter the first operand\n");

scanf("%d", &op1);

printf("Please enter the second operand\n");

scanf("%d", &op2);

printf("Please enter the desired operator\n");

scanf(" %c", &operator);

switch (operator)

{

case '+':
	sum = op1 + op2;
	printf("%d + %d = %d\n", op1, op2, sum);
	break;

case '-':
	sum = op1 - op2;
	printf("%d - %d = %d\n", op1, op2, sum);
	break;

case '*':
	sum = op1 * op2;
	printf("%d * %d = %d\n", op1, op2, sum);
	break;

case '/':
	sum = op1 / op2;
	printf("%d / %d = %d\n", op1, op2, sum);
	break;

default:
	printf("Operator not recognized.\nThe supported operators are +, -, *, /.\n");
	break;
}
}
