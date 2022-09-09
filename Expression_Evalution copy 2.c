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
    int flag = 0;
    char token, pretoken = '$', f = 10;
    while (n)
    {
        scanf("%c", &token);
        n--;
        if (token >= '0' && token <= '9')
        {
            if (pretoken >= '0' && pretoken <= '9')
            {
                Ntop->number = (Ntop->number) * f + (int)(token - '0');
                f = f * 10;
            }
            else
            {
                node *help = (node *)malloc(sizeof(node));
                help->number = token - '0';
                Ntop = Push(Ntop, help);
                printf("%d-ins ", help->number);
                f = 10;
            }
            int flag = 0;
        }
        else
        {
            node *help = (node *)malloc(sizeof(node));
            help->operator= token;
            if(Otop!=NULL)
if(InsideStackPriority(Otop->operator) >= OutsideStackPriority(token))
            {
                int x, y, ans, flag = 0;
                if (Ntop != NULL && Ntop->size >= 2)
                {

                    if (Ntop != NULL)
                    {
                        x = Ntop->number;
                        // Ntop = Pop(Ntop);
                        printf(" %d-xa ", x);
                        flag++;
                    }
                    if (Ntop != NULL)
                    {
                        y = Ntop->next->number;
                        Ntop = Pop(Ntop);
                        printf(" %d-ya ", y);
                        flag++;
                    }
                    if (flag == 2)
                    {

                        ans = Evaluate(y, x, Otop->operator);
                        node *sub = (node *)malloc(sizeof(node));
                        sub->number = ans;
                        printf("%d-ans ", ans);
                        Ntop = Push(Ntop, sub);
                        Otop = Pop(Otop);
                    }
                    flag = 0;
                }
            }
            Otop = Push(Otop, help);
            printf(" %c-ins ", help->operator);
        }
        pretoken = token;
    }
    printf("\n%d %c ", Ntop->number, Otop->operator);
    return 0;
}