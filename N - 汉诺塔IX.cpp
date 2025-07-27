#include<stdio.h>

int main()
{
    long long n, m, k;  // 2的63次方，超过int类型范围

    while(scanf("%lld%lld", &n, &m), n+m)
    {
        k = 1;
        while(m % 2 != 1)
        {
            k++;
            m /= 2;
        }
        printf("%lld\n", k);
    }
    return 0;
}