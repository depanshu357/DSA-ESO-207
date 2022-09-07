#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct stud
{
    int element;
    int size;
    struct stud *next;
};
typedef struct stud node;

node *Push(node *top,node *ele)
{

    if (top != NULL)
    {
        ele->size = top->size + 1;
        ele->next = top;
        top = ele;
    }
    else
    {
        ele->next = top;
        ele->size = 1;
        top = ele;
    }
    return top;
}

node *Pop(node *top)
{

    if (top != NULL)
    {
        node *diehard = top;
        if (top->size != 1){
            top = top->next;
        }
        else{
            top = NULL;
        }
            printf("%d\n",diehard->element);
        free(diehard);
    }
    else
    {
        printf("!\n");
    }
    return top;
}

void Top(node *top)
{
    if (top != NULL)
    {
        printf("%d\n", top->element);
    }
    else
    {
        printf("!\n");
    }
}

void Size(node *top)
{
    if (top != NULL)
    {
        printf("%d\n", top->size);
    }
    else
        printf("0\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    node *top=NULL;
    while (n--)
    {
        int instruction;
        scanf("%d", &instruction);
        if (instruction == 0)
        {
            int element;
            scanf("%d", &element);
            node *ele = (node *)malloc(sizeof(node));
            ele->element = element;
            top = Push(top,ele);
        }
        else if (instruction == 1)
        {
            top = Pop(top);
        }
        else if (instruction == 2)
        {
            Top(top);
        }
        else if (instruction == 3)
        {
            Size(top);
        }
    }
    return 0;
}