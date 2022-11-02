#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
int arr[1000001];
// int C[10000001];
int mergesortComparison = 0;
int quicksortComparison = 0;

// #include <random>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    return;
}
void Merge(int arr[], int l, int r, int *C)
{
    int mid = (l + r) / 2;
    int start1 = l, start2 = mid + 1;
    int k = 0;
    while (start1 <= mid && start2 <= r)
    {
        mergesortComparison++;
        if (arr[start1] > arr[start2])
        {
            // printf("hello");
            C[k++] = arr[start2++];
        }
        else
        {
            C[k++] = arr[start1++];
        }
    }
    while (start1 <= mid)
    {
        C[k++] = arr[start1++];
    }
    while (start2 <= r)
    {
        C[k++] = arr[start2++];
    }
}
void MergeSort(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    // printf("working ");
    int *C = (int *)malloc(sizeof(int) * (r - l + 1));
    MergeSort(arr, l, mid);
    MergeSort(arr, mid + 1, r);
    // int C[r - l + 1];
    Merge(arr, l, r, C);
    for (int i = l; i <= r; i++)
    {
        arr[i] = C[i - l];
    }
    free(C);
    return;
}
int Partition(int arr[], int l, int r)
{

    int key = arr[l];
    int i = l;
    for (int j = l + 1; j <= r; j++)
    {
        quicksortComparison++;
        if (arr[j] <= key)
        {
            i++;
            swap(arr + j, arr + i);
        }
    }
    swap(arr + i, arr + l);
    // printf("%d ",i);
    return i;
}
void QuickSort(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int p = Partition(arr, l, r);
    // printf("%d-start %d-end ",l,r);
    // for(int i=l;i<=r;i++){
    //     printf("%d ",arr[i]);
    // }
    // printf("\n");
    QuickSort(arr, l, p - 1);
    QuickSort(arr, p + 1, r);
    return;
}
int main()
{

    int n;
    int Max_Range = 100000;
    scanf("%d", &n);
    FILE *fpt;
    fpt = fopen("slowerMergeSortComparisonNE6.csv", "w+");

    // int arr[500];
    time_t t1;
    srand((unsigned)time(&t1));
    for (int j = 0; j < 500; j++)
    {

        quicksortComparison = 0;
        mergesortComparison = 0;
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand();
            // arr[i] = rand() / RAND_MAX * Max_Range;
            // printf("%d ", arr[i]);
        }
        // MergeSort(arr,0,n-1);
        time_t t;
        time_t time_taken;
        t = clock();
        // QuickSort(arr, 0, n - 1);
        MergeSort(arr, 0, n - 1);
        time_taken = clock() - t;
        int time_taken_microseconds = ((double)time_taken * 1000000) / (double)CLOCKS_PER_SEC;
        // for (int i = 0; i < n; i++)
        //     fprintf(fpt, "%d ", arr[i]);
        // printf("%d ",time_taken_microseconds);
        // fprintf(fpt, "%d\n ", time_taken_microseconds);
        fprintf(fpt, "%d\n ", mergesortComparison);

        // fprintf(fpt, "\n");
    }
    fclose(fpt);
    return 0;
}