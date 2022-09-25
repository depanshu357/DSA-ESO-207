#include <stdio.h>
#include <stdlib.h>
// To show root is not updated in function, root will not shift to temp it will remain root
struct stud
{
    int element;
    struct stud *next;
};
typedef struct stud node;
void Test(node *root)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->element = 45;
    root->next = temp;
    root = root->next;
}
int main()
{
    node *root = (node *)malloc(sizeof(node));
    root->element = 23;
    Test(root);
    printf("%d", root->next->element);
    return 0;
}