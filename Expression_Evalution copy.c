#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct stud
{
    char operator;
    int number;
    int size;
    struct stud *next;
};

typedef struct stud node;

node *Push(node *top, node *ele)
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
        if (top->size != 1)
        {
            top = top->next;
        }
        else
        {
            top = NULL;
        }
        if (diehard->operator== '0')
            printf("%d", diehard->number);
        else
            printf("%c", diehard->operator);
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
        printf("%d\n", top->operator);
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

int InsideStackPriority(char instack)
{
    if (instack == '+' || instack == '-')
        return 1;
    if (instack == '*' || instack == '/')
        return 2;
    if (instack == '^')
        return 3;
    if (instack == '(')
        return 0;
    return 0;
}
int OutsideStackPriority(char outstack)
{
    if (outstack == '+' || outstack == '-')
        return 1;
    if (outstack == '*' || outstack == '/')
        return 2;
    if (outstack == '^')
        return 4;
    if (outstack == '(')
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
int Evaluate(int x, int y, char operator)
{
    if (operator== '+')
        return x + y;
    if (operator== '-')
        return x - y;
    if (operator== '*')
        return x * y;
    if (operator== '/')
        return x / y;
    if (operator== '^')
        return power(x, y);
    return 0;
}
int main()
{
    int n;
    scanf("%d\n", &n);
    node *Ntop = NULL, *Otop = NULL;
    char token;
    int flag = 0;
    // printf("%c",token);
    node *ele = (node *)malloc(sizeof(node));
    ele->operator= '$';
    Otop = Push(Otop, ele);
    // printf("%c",Otop->operator);
    while (n)
    {
        scanf("%c", &token);
        // printf("%c-main ",token);
        int number = 0, f = 1;
        while (token >= '0' && token <= '9')
        {
            if (n != 1)
            {
                number = (token - '0') + number * f;
                f = f * 10;
                scanf("%c", &token);
                flag = 1;
                // printf(" %c-cha ",token);
                // printf("%d-ka ",number);
            }
            else
            {

                scanf("%c", &number);
                // printf("%c-da ",token);
                number = token - '0';
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            node *ele = (node *)malloc(sizeof(node));
            ele->number = number;
            ele->operator= - 1;
            Ntop = Push(Ntop, ele);
            printf("%d-ins ", number);
            flag = 0;
            n--;
        }
        if (n == 0)
            break;
        if (flag == 0)
        {
            node *ele = (node *)malloc(sizeof(node));
            ele->operator= token;
            ele->operator= '0';
            printf("%c-ins %c ", token,Otop->operator);
            
            if (Otop->operator!= '$')
            {
                printf(" activated ");
                while (InsideStackPriority(Otop->operator) >= OutsideStackPriority(token) || Otop->operator!= '$')
                {
                    int x, y, ans;
                    x = Ntop->number;
                    Ntop = Pop(Ntop);
                    y = Ntop->number;
                    Ntop = Pop(Ntop);
                    printf("%d-kachak-%d", x, y);
                    ans = Evaluate(x, y, Otop->operator);
                    node *sub = (node *)malloc(sizeof(node));
                    sub->number = ans;
                    Push(Ntop, sub);
                    Otop = Pop(Otop);
                }
            }

            Push(Otop, ele);
            n--;
        }
        if (n == 0)
            break;
    }
    while (Otop->operator!= '$')
    {  
        printf("activated2");
        int x, y, ans;
        x = Ntop->number;
        Ntop = Pop(Ntop);
        y = Ntop->number;
        Ntop = Pop(Ntop);
        printf("%d-kachak-%d", x, y);
        ans = Evaluate(x, y, Otop->operator);
        node *sub = (node *)malloc(sizeof(node));
        sub->number = ans;
        Push(Ntop, sub);
        Otop = Pop(Otop);
    }
    // printf("%d ", Evaluate(4, 5, '^'));
    printf("\n%d ", Ntop->number);
    return 0;
}