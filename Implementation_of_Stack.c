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
void Size(node top)
{
    if (top == NULL)
        printf("0\n");
    else
    {
        node temp = top;
        int count = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        printf("%d\n", count);
    }
}
int main()
{
    int n;
    scanf("%d\n", &n);
    node stack = NULL;
    while (n--)
    {
        int instruction;
        scanf("%d", &instruction);
        if (instruction == 0)
        {
            int number;
            scanf("%d", &number);
            stack = Push(number, stack);
        }
        else if (instruction == 1)
        {
            if (stack != NULL)
                printf("%d\n", stack->value);
            else
                printf("!\n");
            stack = Pop(stack);
        }
        else if (instruction == 2)
        {
            Top(stack);
        }
        else
        {
            Size(stack);
        }
    }
}
