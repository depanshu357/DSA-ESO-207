#include <stdio.h>
#include <stdlib.h>

struct stud
{
    int element;
    struct stud *left;
    struct stud *right;
};

typedef struct stud node;

node *Ins(node *root, int x)
{
    node *curr = root;
    node *pre = curr;
    node *temp = (node *)malloc(sizeof(node));
    temp->element = x;
    temp->left = NULL;
    temp->right = NULL;
    while (curr != NULL)
    {
        if (x < curr->element)
        {
            pre = curr;
            curr = curr->left;
        }
        else
        {
            pre = curr;
            curr = curr->right;
        }
    }
    if (pre == NULL)
    {
        root = temp;
        // printf("activated ");
    }
    else
    {
        // printf("%d", pre->element);

        if (x < pre->element)
        {
            pre->left = temp;
            // printf("l ");
        }
        else
        {
            pre->right = temp;
            // printf("r ");
        }
    }
    return root;
}

node *Traversal(node *root)
{
    if (root == NULL)
        return root;
    node *pre = root;
    Traversal(root->left);
    if (root != NULL)
        printf("%d ", root->element);
    Traversal(root->right);
    return root;
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    node *root;
    root = NULL;
    // root = (node *)malloc(sizeof(node));
    for (int i = 0; i < n; i++)
    {
        root = Ins(root, arr[i]);
    }
    if (root == NULL)
        printf("What t f");
    Traversal(root);
    return 0;
}