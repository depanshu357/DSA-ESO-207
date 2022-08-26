#include <stdio.h>
#include <stdlib.h>
struct stud
{
    int x;
    int y;
    int value;
    struct stud *right;
    struct stud *down;
};
typedef struct stud node;

int main()
{
    int n;
    scanf("%d", &n);
    node *row_head1[n + 1], *p, *q, *row_head2[n + 1];
    node *column_head1[n + 1];
    node *column_head2[n + 1];
    // for (int i = 0; i <= n; i++)
    // {
    // p[i]=(node *)malloc(sizeof(node));
    // q[i]=(node *)malloc(sizeof(node));
    // row_head1[i]=p[i];
    // row_head2[i]=q[i];
    // }
    node *head1 = (node *)malloc(sizeof(node));
    node *head2 = (node *)malloc(sizeof(node));
    p = head1;
    q = head2;
    while (1)
    {
        int mnum, x, y, value;
        int currx1 = 0;
        int currx2 = 0;
        scanf("%d", &mnum);
        if (mnum == 0)
            break;
        scanf("%d %d %d", &x, &y, &value);
        if (mnum == 1)
        {
            if (currx1 < x)
            {   
                // row_head2[x-1]->right=NULL;   
                row_head1[x] = p;
                currx1 = x;
            }
            p->x = x;
            p->y = y;
            p->value = value;
            p->right = (node *)malloc(sizeof(node));
            p = p->right;
        }
        else
        {
            if (currx2 < x)
            {  
                //  row_head2[x-1]->right=NULL;
                row_head2[x] = q;
                currx2 = x;
            }
            q->x = x;
            q->y = y;
            q->value = value;
            q->right = (node *)malloc(sizeof(node));
            q = q->right;
        }
    }
    p->x=0;p->y=0;q->x=0;q->y=0;q->value=0;p->value=0;
    p->right = NULL;
    q->right = NULL;
    // while(head1->right!=NULL)
    // {
    // printf("%d ", head1->value);
    // head1 = head1->right;
    // }
    // while(head2->right!=NULL)
    // {
    // printf("%d ", head2->value);
    // head2 = head2->right;
    // }
    printf("%d",row_head1[2]->value);
}