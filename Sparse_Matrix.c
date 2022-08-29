#include <stdio.h>
#include <stdlib.h>

struct LinkedList
{
    int index_x, index_y, value;
    struct LinkedList *right;
    struct LinkedList *bottom;
};
typedef struct LinkedList *node;

//Making pointers to linked list and making connections in right and bottom direction
node CreateNode(node row_pointer[], node col_pointer[], int index_x, int index_y, int value, node prev_node_x, node prev_node_y)
{

    node temp = (node)malloc(sizeof(struct LinkedList));
    temp->value = value;
    temp->index_x = index_x;
    temp->index_y = index_y;
    temp->right = NULL;
    temp->bottom = NULL;

    if (col_pointer[index_y] != NULL)
    {
        prev_node_y->bottom = temp;
    }

    if (row_pointer[index_x] != NULL)
    {
        prev_node_x->right = temp;
    }

    if (col_pointer[index_y] == NULL)
    {
        col_pointer[index_y] = temp;
    }

    if (row_pointer[index_x] == NULL)
    {
        row_pointer[index_x] = temp;
    }
    return temp;
}

int main()
{
    // Matrix Formation
    int n, matrix_no, row, col, k, value, flag = 0, check = 1;
    scanf("%d", &n);
    node m1_row_pointer[n + 1], m1_col_pointer[n + 1];
    node m2_row_pointer[n + 1], m2_col_pointer[n + 1];
    node m1_prev_node_x[n + 1], m1_prev_node_y[n + 1];
    node m2_prev_node_x[n + 1], m2_prev_node_y[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        m1_row_pointer[i] = NULL;
        m1_col_pointer[i] = NULL;

        m1_prev_node_x[i] = NULL;
        m1_prev_node_y[i] = NULL;

        m2_row_pointer[i] = NULL;
        m2_col_pointer[i] = NULL;

        m2_prev_node_x[i] = NULL;
        m2_prev_node_y[i] = NULL;
    }

    while (check)
    {
        for (int i = 0; i < 4; i++)
        {
            //scanning all the 4 datas in a given line
            scanf("%d", &k);
            if (k == 0)
            {
                check = 0;
                break;
            }
            if (i == 0)
            {
                matrix_no = k;
            }
            else if (i == 1)
            {
                row = k;
            }
            else if (i == 2)
            {
                col = k;
            }
            else
            {
                value = k;
            }
        }

        if (check)
        {
            if (matrix_no == 1)
            {
                node temp = CreateNode(m1_row_pointer, m1_col_pointer, row, col, value, m1_prev_node_x[row], m1_prev_node_y[col]);
                m1_prev_node_x[row] = temp;
                m1_prev_node_y[col] = temp;
            }
            else if (matrix_no == 2)
            {
                node temp = CreateNode(m2_row_pointer, m2_col_pointer, row, col, value, m2_prev_node_x[row], m2_prev_node_y[col]);
                m2_prev_node_x[row] = temp;
                m2_prev_node_y[col] = temp;
            }
        }
    }

    // Matrix Multiplication
    for (int i = 1; i <= n; i++)
    {
        if (m1_row_pointer[i] == NULL)
            continue;// To skip null rows
        for (int j = 1; j <= n; j++)
        {
            if (m2_col_pointer[j] == NULL)
                continue;//To skip null columns
            node temp_row_pointer = m1_row_pointer[i], temp_col_pointer = m2_col_pointer[j];
            int sum = 0;
            while (temp_row_pointer != NULL && temp_col_pointer != NULL)
            {
                if ((temp_row_pointer->index_y) == (temp_col_pointer->index_x))
                {
                //Matching the condition when there are non-zero elements in positions which can be multiplied
                    sum += ((temp_row_pointer->value) * (temp_col_pointer->value));

                    temp_row_pointer = temp_row_pointer->right;
                    temp_col_pointer = temp_col_pointer->bottom;
                }
                else
                {
                    //else moving to next positions in x and/or y directions
                    if ((temp_row_pointer->index_y) > (temp_col_pointer->index_x))
                    {
                        temp_col_pointer = temp_col_pointer->bottom;
                    }
                    else
                    {
                        temp_row_pointer = temp_row_pointer->right;
                    }
                }
            }
            if (sum != 0)
            {
                printf("%d %d %d\n", i, j, sum);
                flag = 1;
            }
        }
    }
    if (flag == 0)
    {
        printf("NULL MATRIX!");
    }
    // m nodes are created which is equal to the number of total non-zero enteries in matrix 1 and 2;
    // hence space complexity is O(m)
    return 0;
}