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
    int LeftCount = Count(root->left);
    int RightCount = Count(root->right);
    if (LeftCount > 3 * RightCount)
    {
        printf("left is heavy");
    }
    else if (RightCount > 3 * LeftCount)
    {
        printf("Right is heavy");
    }
    return root;
}

node *Traversal(node *root, int *count)
{
    // To print all elements from left to right
    if (root == NULL)
    {
        return root;
    }
    node *pre = root;
    Traversal(root->left, count);
    if (root != NULL)
    {
        (*count)++;
        printf("%d ", root->element);
    }
    Traversal(root->right, count);
    return root;
}

int CountHelp(node *root, int *count)
{

    if (root == NULL)
    {
        return *count;
    }
    node *pre = root;
    CountHelp(root->left, count);
    if (root != NULL)
    {
        (*count)++;
    }
    CountHelp(root->right, count);
    return *count;
}

int Count(node *root)
{
    // To count number of nodes in Tree
    int count = 0;
    return CountHelp(root, &count);
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
        printf("WTF");
    int count = 0;
    Traversal(root, &count);
    printf("%d ", Count(root));
    return 0;
}