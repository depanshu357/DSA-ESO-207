#include <stdio.h>
#include <time.h>
int A[100][5];
int ans[5];
long long int RFib(long long n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return (RFib(n - 1) + RFib(n - 2)) % 2022;
}
long long int IFib(long long int n)
{
    int a = 0, b = 1;
    if (n == 1)
        return 1;
    if (n == 0)
        return 0;
    for (long long int i = 2; i <= n; i++)
    {
        int temp = b % 2022;
        b = (a + b) % 2022;
        a = temp;
    }
    return b % 2022;
}
int main()
{
    long long int n;
    scanf("%lld", &n);
    clock_t start_t, end_t;
    double total_t;
    start_t = clock();

    printf("%lld\n",IFib(n));
    // printf("%lld\n",RFib(n));
    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    // CLOCKS_PER_SEC is a constant defined in time.h and its value is 10^6.
    printf("Total time taken: %f\n", total_t);

    return 0;
}