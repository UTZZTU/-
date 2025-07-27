#include <stdio.h>
typedef long long ll;
ll fun(ll a,ll b)
{
    ll c;
    if(a<b)
    {
        c=a;
        a=b;
        b=c;
    }
    while(b!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main ()
{
    ll n,a,b,c,d,i,t,pd=0;
    scanf("%lld",&n);
    scanf("%lld/%lld",&a,&b);
    for(i=1;i<n;i++)
    {
        scanf("%lld/%lld",&c,&d);
        t=b/fun(b,d)*d;
        a*=t/b;
        c*=t/d;
        a+=c;
        b=t;
        t=fun(a,b);
        a/=t;
        b/=t;
    }
    if(a<0)
    {
        a*=-1;
        if(a>=b)
        {
            printf("-%d",a/b);
            a%=b;
            pd=1;
        }
        if(a!=0)
        {
            if(pd==1)
                printf(" ");
            printf("-%d/%d",a,b);
        }
		else
        {
            if(pd==0)
                printf("0");
        }   
    }
    else
    {
        if(a>=b)
        {
            printf("%d",a/b);
            a%=b;
            pd=1;
        }
        if(a!=0)
        {
            if(pd==1)
                printf(" ");
            printf("%d/%d",a,b);
        }
		else
        {
            if(pd==0)
                printf("0");
        } 
    }
    return 0;
}