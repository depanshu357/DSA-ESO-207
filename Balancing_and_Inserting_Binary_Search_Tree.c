#include <stdio.h>
#include <stdlib.h>

struct stud
{
    int element;
    struct stud *left;
    struct stud *right;
};

typedef struct stud node;
node *globalArr[1000000];

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

int MakeArr(node *root, int *count)
{
    if (root == NULL)
    {
        return *count;
    }
    node *pre = root;
    MakeArr(root->left, count);
    if (root != NULL)
    {
        globalArr[*count] = root;
        // printf("%d ",root->element);
        (*count)++;
    }
    MakeArr(root->right, count);
    return *count;
}
void MakeBST(node *root, int start, int end)
{
    if (start == end)
    {   
        globalArr[start]->left=NULL;
        globalArr[start]->right=NULL; 
        if (root->element > globalArr[start]->element)
        {
            root->left = globalArr[start];
        }
        else if(root->element > globalArr[start]->element){
            root->right = globalArr[start];
        }
        return;
    }
    int mid = (start + end) / 2;
    if(root->element>globalArr[mid]->element){
        root->left = globalArr[mid];
    }else{
        root->right = globalArr[mid];
    }
    if(mid!=start)
    MakeBST(globalArr[mid],start,mid-1);
    if(mid!=end)
    MakeBST(globalArr[mid],mid+1,end);
}

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
    // if (LeftCount > 3 * RightCount+1)
    // {
    //     printf("left is heavy ");
    // }
    // else if (RightCount > 3 * LeftCount+1)
    // {
    //     printf("Right is heavy ");
    // }
    printf("%d %d \n",LeftCount,RightCount);
    if ((4*(LeftCount+RightCount) > 3 * RightCount +1) || (4*(RightCount+LeftCount) > 3 * LeftCount +1))
    {
        int count = 0;
        count = MakeArr(root, &count);
        printf("%d ", count);
        MakeBST(root, 0, count - 1);
        // Traversal(root);    
        // for(int i=0;i<count ;i++) printf("%d ",globalArr[i]->element);
        // printf("\n");
        // printf("%d",Count(root));
        // printf("activated");
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
    // printf("\n%d\n", Count(root));
    // for (int i = 0; i < Count(root); i++)
        // printf("%d ", globalArr[i]->element);
    // Traversal(root, &count);
    // printf("%d",root->element);

    return 0;
}