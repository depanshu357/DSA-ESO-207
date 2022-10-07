#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n;
int arr[10000000];
struct stud
{
    int element;
    int subtree_size;
    struct stud *left;
    struct stud *right;
};

typedef struct stud node;

node *Traversal(node *root)
{
    // To print all elements from left to right
    if (root == NULL)
    {
        return root;
    }
    node *pre = root;
    Traversal(root->left);
    if (root != NULL)
    {
        printf("%d ", root->element);
    }
    Traversal(root->right);
    return root;
}

int ConvertBSTtoArray(node *root, node *arr[], int pos)
{
    if (root->left != NULL)
    {
        pos = ConvertBSTtoArray(root->left, arr, pos);
    }

    arr[pos++] = root;

    if (root->right != NULL)
    {
        pos = ConvertBSTtoArray(root->right, arr, pos);
    }

    return pos;
}

node *ConvertArrayToBST(node *arr[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    //  Get the middle element and make it root
    int mid = (start + end) / 2;
    node *root;
    root = arr[mid];
    root->subtree_size = end - start;

    // Recursively construct the left subtree and make left child of root
    root->left = ConvertArrayToBST(arr, start, mid - 1);

    //  Recursively construct the right subtree and make it   right child of root
    root->right = ConvertArrayToBST(arr, mid + 1, end);

    return root;
}

node *ConvertToPerfectlyBalanced(node *root)
{
    node *arr[n];
    ConvertBSTtoArray(root, arr, 0);

    node *temp = ConvertArrayToBST(arr, 0, root->subtree_size);
    return temp;
}

void IsBalanced(node *root, int x)
{
    if (root = NULL)
    {
        return;
    }
    node *pre = root;
    node *curr = root;
    while (curr != NULL)
    {
        if (4 * (curr->left ? curr->left->subtree_size : -1) > 3 * curr->subtree_size || 4 * (curr->right ? curr->right->subtree_size : -1) > 3 * curr->subtree_size)
        {
            node *temp = ConvertToPerfectlyBalanced(curr);
            if (curr->element < pre->element)
            {
                pre->left = temp;
                curr = temp;
            }
            else
            {
                pre->right = temp;
                curr = temp;
            }
        }
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
            pre = curr;
            curr = curr->left;
        }
        else
        {

            (curr->subtree_size)++;
            pre = curr;
            curr = curr->right;
        }
    }
    if (pre == NULL)
    {
        root = temp;
    }
    else
    {
        if (x < pre->element)
        {
            pre->left = temp;
        }
        else
        {
            pre->right = temp;
        }
    }
    return root;
}

int main()
{
    // int n;
    scanf("%d", &n);
    // int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i]=i+1;
    }
    node *root;
    root = NULL;

    FILE *fpt;
    fpt = fopen("Time_Required1.csv","w+");
    fprintf(fpt,"Number_Inserted,Time_Taken\n");
    
        double total_t=0;
    for (int i = 0; i < n; i++)
    {
        clock_t start_t, end_t;
        start_t = clock();
        root = Ins(root, arr[i]);
        IsBalanced(root, arr[i]);
        end_t = clock();
        // CLOCKS_PER_SEC is a constant defined in time.h and its value is 10^6.
        total_t += ((double)(end_t - start_t) / CLOCKS_PER_SEC);
        if((i+1)%(50000)==0 ){
        fprintf(fpt,"%d, %f\n",i+1,total_t);
        }
    }
    fclose(fpt);
    // Traversal(root);  
    return 0;
}