#include <stdio.h>
#include <time.h>
long long int  x1 = 1, x2 = 1, x3 = 1, x4 = 0;
void multiply(long long int  a[], long long int  n)
{
    if (n == 1)
    {
        x1 = 1;
        x2 = 1, x3 = 1, x4 = 0;
        return;
    }
    if (n == 0)
    {
        x1 = 1;
        x2 = 0, x3 = 0, x4 = 1;
        return;
    }
    multiply(a, n / 2);
    long long int  temp1 = x1, temp2 = x2, temp3 = x3, temp4 = x4;
    x1 = (temp1 * temp1 + temp2 * temp3)%2021;
    x3 = (temp3 * temp1 + temp4 * temp3)%2021;
    x2 = (temp1 * temp2 + temp2 * temp4)%2021;
    x4 = (temp3 * temp2 + temp4 * temp4)%2021;
    if (n % 2 != 0)
    {   
        long long int  temp1=x1,temp2=x2,temp3=x3,temp4=x4;
        x1 = (temp1+temp2)%2021;
        x2=temp1%2021;
        x3=(temp3+temp4)%2021;
        x4=temp3%2021;
    }

    return;
}
void Cleverfib(long long int  n)
{
    long long int  a[5];
    a[1] = 1;
    a[2] = 1;
    a[3] = 1;
    a[4] = 0;
    multiply(a, n);
    printf("%d ", x1);
}
 int  main()
{
    long long int  n;
    scanf("%lld", &n);
    clock_t start_t, end_t;
    double total_t;
    start_t = clock();
    long long int  arr[5];
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;
    arr[4] = 0;

    for(int i=0;i<10000;i++){
    if(n==0) printf("0");
    else Cleverfib(n-1);
    }
    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    // CLOCKS_PER_SEC is a constant defined in time.h and its value is 10^6.
    printf("Total time taken: %f\n", total_t);
    return 0;
}