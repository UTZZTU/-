#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k,p[1000100],prim[1000100],n,a,maxn=1000000;
void find_prime()//素数打表
{
    k=0;
    for(ll i=2;i<maxn;i++)
    {
        if(!p[i])
        {
            prim[k++]=i;//储存质素
            for(ll j=i*2;j<maxn;j+=i)
            {
                p[j]=1;
            }
        }
    }
}
bool slove(ll a)
{
    ll s=1;
    for(int i=0;i<k&&a;i++)
    {
        ll x=0;
        if(prim[i]>a)
            break;
        //核心代码 按顺序对素数取余,得到该素数的指数
        while(a%prim[i]==0)//注意是while啊!
        {
            a/=prim[i];
            x++;
        }
        s*=(x+1);//得到一个素数的指数后用公式
		if(s>3)
		return false;
    }
    if(a>1)
    {
        s*=(1+1);//如果a不能被整分，说明a还有一个素数是它的约数，此时x=1,所以是1+1,
    }
    return s==3;
}
int main ()
{
	p[1]=1;
	find_prime();
	scanf("%lld",&n);
	while(n--)
	{
		scanf("%lld",&a);
		ll u=floor(sqrt(a));
		if(u*u!=a||p[u])
		{
			cout<<"NO"<<endl;
			continue;
		}
		if(slove(a))
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}
	return 0;
}