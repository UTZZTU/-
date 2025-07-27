#include <iostream>
using namespace std;
int s[1000010],w[1000010];
int main ()
{
    int n,a,b,i,j,sum=0;
    char k;
    cin>>n>>a>>b;
    for(i=1;i<=n;i++)
    {
        cin>>k;
        if(k=='0')
        {
            s[i]=1+s[i-1];
            w[i]=w[i-1];
        }
        else if(k=='1')
        {
            w[i]=1+w[i-1];
            s[i]=s[i-1];
        }
    }
    for(i=1;i<=n-a-b+1;i++)
    {
        for(j=i+a+b-1;j<=n;j++)
        {
            if(s[j]-s[i-1]>=a&&w[j]-w[i-1]>=b)
            {
                sum+=n-j+1;
                break;
            }
        }
    }
    printf("%d",sum);
    return 0;
}