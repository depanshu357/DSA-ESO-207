#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct LinkedList
{
    int value;
    struct LinkedList *next;
};

typedef struct LinkedList *node;

node Push(int token, node stack_head)
{
    node help = (node)malloc(sizeof(struct LinkedList));
    help->value = token;
    help->next = stack_head;
    stack_head = help;

    return stack_head;
}

node Pop(node top)
{

    if (top != NULL)
    {
        node temp = top;
        if (top->next != NULL)
        {
            top = top->next;
        }
        else
        {
            top = NULL;
        }
        free(temp);
    }

    return top;
}

void Top(node top)
{
    if (top != NULL)
    {
        printf("%d\n", top->value);
    }
    else
    {
        printf("!\n");
    }
}

int InsideStackPriority(char inside_stack)
{
    if (inside_stack == '+' || inside_stack == '-')
        return 1;
    if (inside_stack == '*' || inside_stack == '/')
        return 2;
    if (inside_stack == '^')
        return 3;
    if (inside_stack == '(')
        return 0;
    return 0;
}
int OutsideStackPriority(char outside_stack)
{
    if (outside_stack == '+' || outside_stack == '-')
        return 1;
    if (outside_stack == '*' || outside_stack == '/')
        return 2;
    if (outside_stack == '^')
        return 4;
    if (outside_stack == '(')
        return 5;
    return 0;
}
int power(int x, int y)
{
    if (y == 0)
        return 1;
    if (y % 2 == 0)
        return power(x, y / 2) * power(x, y / 2);
    else
        return power(x, y / 2) * power(x, y / 2) * x;
}
int Evaluate(int x, int y, char value)
{
    if (value == '+')
        return x + y;
    if (value == '-')
        return x - y;
    if (value == '*')
        return x * y;
    if (value == '/')
        return x / y;
    if (value == '^')
        return power(x, y);
    return 0;
}
int main()
{
    int n;
    scanf("%d\n", &n);
    node number_stack = NULL, operator_stack = NULL;
    int flag = 0;
    char token, pretoken = '$', f = 1;
    int ans;
    while (n)
    {
        scanf("%c", &token);
        n--;
        if (token >= '0' && token <= '9')
        {
            if (pretoken >= '0' && pretoken <= '9')
            {
                number_stack->value = (number_stack->value) * f + (int)(token - '0');
                f = 10;
            }
            else
            {

                number_stack = Push(token - '0', number_stack);
                f = 10;
            }
            int flag = 0;
        }
        else if (token == ')')
        {
            while (operator_stack->value != '(')
            {
                int x, y;
                x = number_stack->value;
                number_stack = Pop(number_stack);
                y = number_stack->value;
                int k = Evaluate(y, x, operator_stack->value);
                number_stack->value = k;
                operator_stack = Pop(operator_stack);
            }
            operator_stack = Pop(operator_stack);
        }
        else
        {

            while (operator_stack != NULL && InsideStackPriority(operator_stack->value) > OutsideStackPriority(token))
            {
                int x, y;
                if (number_stack != NULL)
                {
                    x = number_stack->value;
                    number_stack = Pop(number_stack);
                    y = number_stack->value;
                    number_stack = Pop(number_stack);
                    ans = Evaluate(y, x, operator_stack->value);

                    number_stack = Push(ans, number_stack);
                    operator_stack = Pop(operator_stack);
                }
            }
            operator_stack = Push(token, operator_stack);
        }
        pretoken = token;
    }
    while (operator_stack != NULL)
    {
        int x, y;
        x = number_stack->value;
        number_stack = Pop(number_stack);
        y = number_stack->value;
        number_stack = Pop(number_stack);
        ans = Evaluate(y, x, operator_stack->value);

        number_stack = Push(ans, number_stack);
        operator_stack = Pop(operator_stack);
    }
    operator_stack = Pop(operator_stack);
    printf("%d", number_stack->value);
    return 0;
}