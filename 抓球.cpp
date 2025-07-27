#include <iostream>
using namespace std;
typedef long long ll;
ll ow(ll a,ll b)
{
    ll x,y,c;
    x=max(a,b);
    y=min(a,b);
    while(y!=0)
    {
        c=x%y;
        x=y;
        y=c;
    }
    return x;
}
ll fastpower(ll a,ll b,ll p)
{
	ll result=1;
	while(b)
	{
		if(b&1)
		result=result*a%p;
		b>>=1;
		a=a*a%p;
	}
	return result;
}
ll fun(int a,int b,int c,int d)
{
    ll n,s=1,x=1,t;
    n=a+b;
    while(c)
    {
        s=s*a%1000000007;
        x=x*n%1000000007;
        n--;
        a--;
        c--;
    }
    t=ow(s,x);
    s/=t;
    x/=t;
    s=fastpower(a,d,1000000007);
    x=fastpower(x,d,1000000007);
    t=ow(s,x);
    s/=t;
    x/=t;
    t=s*x%1000000007;
    return t;
}
int main ()
{
	int n,a,b,c,i;
    ll d,w,m;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a>>b>>c>>d;
        if(c>n)
        {
            printf("0\n");
            continue;
        }
        else
        {
            w=fun(a,b,c,d);
            m=fastpower(w,1000000005,1000000007);
            printf("%lld\n",m);
        }
    }
	return 0;
}