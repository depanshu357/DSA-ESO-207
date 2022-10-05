#include <stdio.h>
#include <stdlib.h>

struct stud
{
    int element;
    int subtree_size;
    struct stud *left;
    struct stud *right;
};

typedef struct stud node;

node *Traversal(node *root, int *count)
{
    // To print all elements from left to right
    if (root == NULL)
    {
        return root;
    }
    node *pre = root;
    root = Traversal(root->left, count);
    if (root != NULL)
    {
        (*count)++;
        printf("%d ", root->element);
    }
    root = Traversal(root->right, count);
    return root;
}

void FreeMemory(node *root)
{
    // To print all elements from left to right
    if (root == NULL)
    {
        return ;
    }
    node *pre = root;
    root = Traversal(root->left, 0);
    if (root != NULL)
    {

        free(root);
    }
    root = Traversal(root->right, 0);
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

node *EmptyNode()
{
    node *temp = (node *)malloc(sizeof(node));
    temp->left = NULL;
    temp->right = NULL;
    temp->element = 0;
    return temp;
}
int ConvertBSTtoArray(node *root, int arr[], int pos)
{
    if (root->left != NULL)
    {
        pos = ConvertBSTtoArray(root->left, arr, pos);
    }

    arr[pos++] = root->element;

    if (root->right != NULL)
    {
        pos = ConvertBSTtoArray(root->right, arr, pos);
    }

    return pos;
}

node *ConvertArrayToBST(int arr[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    //  Get the middle element and make it root
    int mid = (start + end) / 2;
    node *root = EmptyNode();
    root->element = arr[mid];
    root->subtree_size = end - start;
    // Recursively construct the left subtree and make left child of root
    root->left = ConvertArrayToBST(arr, start, mid - 1);

    //  Recursively construct the right subtree and make it   right child of root
    root->right = ConvertArrayToBST(arr, mid + 1, end);

    return root;
}

node *ConvertToPerfectlyBalanced(node *root)
{
    int arr[100];

    ConvertBSTtoArray(root, arr, 0);
    FreeMemory(root);
    node *temp = ConvertArrayToBST(arr, 0, root->subtree_size);
    return temp;
}

int Count(node *root)
{
    // To count number of nodes in Tree
    int count = 0;
    return CountHelp(root, &count);
}

node *Ins(node *root, int x)
{
    node *curr = root;
    node *pre = curr;
    node *temp = (node *)malloc(sizeof(node));
    temp->element = x;
    temp->left = NULL;
    temp->right = NULL;
    temp->subtree_size = 0;

    while (curr != NULL)
    {
        if (x < curr->element)
        {
            (curr->subtree_size)++;
            if (4 * (curr->subtree_size) <= 3 * (pre->subtree_size))
            {
                curr = ConvertToPerfectlyBalanced(curr);
            }
            pre = curr;
            curr = curr->left;
        }
        else
        {
            (curr->subtree_size)++;
            if (4 * (curr->subtree_size) <= 3 * (pre->subtree_size))
            {
                curr = ConvertToPerfectlyBalanced(curr);
            }
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
            temp->subtree_size = pre->subtree_size - 1;
            // printf("l ");
        }
        else
        {
            pre->right = temp;
            temp->subtree_size = pre->subtree_size - 1;
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
    // Traversal(root, &count);
    printf("%d ", Count(root));
    return 0;
}