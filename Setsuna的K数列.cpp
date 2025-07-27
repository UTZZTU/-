#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
ll fastlower(int n)
{
    ll result=1,a=2;
    while(n)
    {
        if(n&1)
            result=result*a%1000000007;
        n>>=1;
        a=a*a%1000000007;
    }
    return result;
}
int main ()
{
    ll n,k,i,sum=1,ws=1,zh=1,cha,a[10000],q=0,xs,j;
    cin>>n>>k;
    while(sum<n)
    {
        sum+=fastlower(ws-1)-1;
        sum++;
        ws++;
    }
    if(sum==n)
    {
        for(i=1;i<ws;i++)
        {
            zh*=k;
            zh%=1000000007;
        }
        printf("%lld",zh);
    }
    else
    {
    	ws--;
    	sum--;
        for(i=1;i<ws;i++)
        {
            zh*=k;
            zh%=1000000007;
        }
        cha=sum-n;
        cha=fastlower(ws-1)-1-cha;
        while(cha!=0)
        {
            a[q]=cha%2;
            cha/=2;
            q++;
        }
        q--;
        for(q;q>=0;q--)
        {
            xs=1;
            if(a[q])
            {
                for(j=1;j<=q;j++)
                {
                    xs*=k;
                    xs%=1000000007;
                }
                zh+=xs;
                zh%=1000000007;
            }
        }
        printf("%lld",zh);
    }
    return 0;
}