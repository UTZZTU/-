#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,f[1000010],pos,tt=1,ou=1,ans;
ll Log[1000010];
void init(ll n){
    Log[1] = 0;
    for(int i = 2;i <= n+1;i++) Log[i] = Log[i/2]+1;
}
ll get_num(ll x)
{
	ll res=0,ans=1;
	while(x+ans<=n)
	{
		res++;
		ans*=2;
	}
	return res;
}
int main ()
{
	cin>>n>>k;
	init(n);
	pos=n;
	if(n==1)
	{
		if(k>0)
		printf("-1");
		else
		printf("1");
	}
	else if(n==2)
	{
		if(k>1)
		printf("-1");
		else if(k==1)
		printf("2 1");
		else
		printf("1 2");
	}else{
		for(int i=2;i<=n;i++){
        ans+=Log[i-1]+1;
    }
        if(ans<k)
        printf("-1");
		else
		{
			while(k)
			{
				int ft=get_num(tt);
				if(k>=ft)
				{
					k-=ft;
					f[pos]=tt;
					tt++;
					pos--;
				}
				else
				{
					f[ou]=tt;
					tt++;
					ou++;
				}
			}
			for(ou;ou<=pos;ou++)
			{
				f[ou]=tt;
				tt++;
			}
			for(int i=1;i<=n;i++)
			{
				printf("%lld ",f[i]);
			}
		}
	}
	return 0;
}