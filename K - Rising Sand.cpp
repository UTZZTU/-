#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int t,n,k;
int a[N];
signed main()
{
  
    scanf("%lld",&t);
    while(t--)
    {
        int sum=0;
        scanf("%lld %lld",&n,&k);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
        }
        if(k==1)
            sum=(n-1)/2;
        else
        {
            for(int i=2;i<=n-1;i++)
            {
                if(a[i]>a[i-1]+a[i+1])
                    sum++;
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}