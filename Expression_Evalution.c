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
        printf("%d\n", diehard->operator);
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

int main()
{
    int n;
    scanf("%d\n", &n);
    node *Ntop = NULL, *Ctop = NULL;
    char token;
    int flag = 0;
    scanf("%c", &token);
    // printf("%c",token);
    while (n)
    {
        int num = 0, f = 1;
        while (token >= '0' && token <= '9')
        {   
            if(n==1) {
                int a;
                scanf("%d",&a);
                num = a;
                n--;
                flag=1;
                break;
            }else{
            num = (int)(token - '0') + num * f;
            f = f * 10;
            flag = 1;
            scanf("%c", &token);
            }
            // printf("%c",token);
        }
        if (flag == 1 && n!=0)
        {
            n--;
            node *ele = (node *)malloc(sizeof(node));
            ele->number = num;
            printf("%d",num);
            Push(Ntop, ele);
            n--;
            node *ele2 = (node *)malloc(sizeof(node));
            ele2->operator= token;
            Push(Ctop, ele2);
            flag = 0;
        }else if(flag==1 && n==0){
            node *ele=(node *)malloc(sizeof(node));
            ele->number=num;
            Push(Ntop,ele);
            break;
        }
        else
        {
            n--;
            node *ele= (node *)malloc(sizeof(node));
            ele->operator=token;
            Push(Ctop,ele);
        }
        if (n)
        {
            scanf("%d", &token);
        }
    }
    printf("%d %c",Ntop->number,Ctop->operator);
    return 0;
}