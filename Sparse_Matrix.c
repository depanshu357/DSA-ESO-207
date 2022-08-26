#include <stdio.h>
#include <stdlib.h>
struct stud
{
    int x, y, value;
    struct stud *right;
    struct stud *bottom;
};
typedef struct stud node;
int main()
{   
    // Matrix Formation
    int n,flag=0;
    scanf("%d", &n);
    node *row1[n + 1], *column1[n + 1], *p1[n + 1], *q1[n + 1];
    node *row2[n + 1], *column2[n + 1], *p2[n + 1], *q2[n + 1];
    for (int i = 0; i <= n; i++)
    {
        row1[i] = (node *)malloc(sizeof(node));
        // row2[i] = (node *)malloc(sizeof(node));
        // column1[i] = (node *)malloc(sizeof(node));
        column2[i] = (node *)malloc(sizeof(node));
        p1[i] = row1[i];
        // q1[i] = column1[i];
        // p2[i] = row2[i];
        q2[i] = column2[i];
        row1[i]->x = i;
        row1[i]->y = 0;
        row1[i]->value = 0;
        // column1[i]->x = 0;
        // column1[i]->y = i;
        // column1[i]->value = 0;
        // row2[i]->x = i;
        // row2[i]->y = 0;
        // row2[i]->value = 0;
        column2[i]->x = 0;
        column2[i]->y = i;
        column2[i]->value = 0;
    }
    while (1)
    {
    int mnum, x, y, value;
        scanf("%d", &mnum);
        if (mnum == 0)
            break;
        scanf("%d %d %d", &x, &y, &value);
        if (mnum == 1)
        {
            node *help = (node *)malloc(sizeof(node));
            help->x = x;
            help->y = y;
            help->value = value;
            p1[x]->right = help;
            // q1[y]->bottom = help;
            p1[x] = p1[x]->right;
            // q1[y] = q1[y]->bottom;
        }
        else
        {
            node *help = (node *)malloc(sizeof(node));
            help->x = x;
            help->y = y;
            help->value = value;
            // p2[x]->right = help;
            q2[y]->bottom = help;
            // p2[x] = p2[x]->right;
            q2[y] = q2[y]->bottom;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        p1[i]->right = NULL;
        // q1[i]->bottom = NULL;
        // p2[i]->right = NULL;
        q2[i]->bottom = NULL;
    }
    // node *test = column1[1];
    // while (test != NULL)
    // {
    //     printf("%d ", test->value);
    //     test = test->bottom;
    // }

    // Matrix Multiplication
    for(int i=1;i<=n;i++){
            if(row1[i]->right==NULL)continue;
        for(int j=1;j<=n;j++){
            if(column2[j]->bottom==NULL)continue;
            node *temprow=row1[i],*tempcolumn=column2[j];
            int sum=0;
            while(temprow!=NULL && tempcolumn!=NULL){
                if((temprow->y)==(tempcolumn->x)){
                    sum+=((temprow->value)*(tempcolumn->value));
                    // printf("%d ",(temprow->value)*(tempcolumn->value));
                    temprow=temprow->right;
                    tempcolumn=tempcolumn->bottom;
                }else{
                    if((temprow->y)>(tempcolumn->x)){
                        tempcolumn=tempcolumn->bottom;
                    }else{
                        temprow=temprow->right;
                    }
                }
            }
            if(sum!=0){
            printf("%d %d %d\n",i,j,sum);
            flag=1;
            }
            
        }
    }
    if(flag==0){
        printf("NULL MATRIX!");
    }

}