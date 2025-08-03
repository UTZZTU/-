#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d;
ll tr[1000010];
ll lowbit(ll x)
{
    return x & -x;
}
void add(ll x,ll c)
{
    for(int i=x;i<=1000000;i+=lowbit(i)) tr[i]+=c;
}
ll sum(ll x)
{
    ll res=0;
    for(int i=x;i;i-=lowbit(i)) res+=tr[i];
    return res;
}
ll fx[200010],fy[200010],num;
void solve()
{
	cin>>n>>d;
	d+=2;
	for(int i=1;i<=n;i++)
	{
		ll x,y;
		cin>>x>>y;
		x+=2e6;
		y+=2e6;
		fx[i]=x;
		fy[i]=y;
	}
	sort(fx+1,fx+1+n);
	sort(fy+1,fy+1+n);
	ll res=0;
	for(int i=1;i<=n;i++)
	{
		res+=abs(fy[i]-fy[(n+1)/2]);
	}
	res++;
//	cout<<res<<endl;
	if(res<=d)
	{
//		cout<<fy[(n+1)/2]<<" "<<res<<endl;
		add(res,1);
	}
	ll tt=res;
	ll l=(n+1)/2,r=n-(n+1)/2;
	ll i=(n+1)/2+1,j=fy[(n+1)/2]+1;
//	cout<<"------------"<<endl;
	while(i<=n&&fy[i]==fy[i-1]) l++,r--,i++;
//	cout<<"------------"<<endl;
	for(i,j;j<=6000000;j++)
	{
		tt+=l;
		tt-=r;
		while(i<=n&&fy[i]==j)
		{
			l++,r--;
			i++;
		}
		if(tt<=d) 
		{
			add(tt,1);
//			cout<<j<<" "<<tt<<endl;
		}
	}
	
	tt=res;
	l=(n+1)/2-1;
	r=n-l;
	i=(n+1)/2-1,j=fy[(n+1)/2]-1;
	while(i>=1&&fy[i]==fy[i+1]) l--,r++,i--;
	for(i,j;j>=-2000000;j--)
	{
		tt+=r;
		tt-=l;
		while(i>=1&&fy[i]==j)
		{
			l--,r++;
			i--;
		}
		if(tt<=d)
		{
			 add(tt,1);
//			 cout<<j<<" "<<tt<<endl;
		}
	}
	
//	cout<<"------------"<<endl;
	
	res=0;
	for(int i=1;i<=n;i++)
	{
		res+=abs(fx[i]-fx[(n+1)/2]);
	}
	res++;
	if(res<=d)
	{
//		cout<<fx[(n+1)/2]<<endl;
		num+=sum(d-res);
	}
	tt=res;
	l=(n+1)/2,r=n-(n+1)/2;
	i=(n+1)/2+1,j=fx[(n+1)/2]+1;
	while(i<=n&&fx[i]==fx[i-1]) l++,r--,i++;
	for(i,j;j<=6000000;j++)
	{
		tt+=l;
		tt-=r;
		while(i<=n&&fx[i]==j)
		{
			l++,r--;
			i++;
		}
		if(tt<=d) 
		{
			num+=sum(d-tt);
		}
	}
	
	tt=res;
	l=(n+1)/2-1;
	r=n-l;
	i=(n+1)/2-1,j=fx[(n+1)/2]-1;
	while(i>=1&&fx[i]==fx[i+1]) l--,r++,i--;
	for(i,j;j>=-2000000;j--)
	{
		tt+=r;
		tt-=l;
		while(i>=1&&fx[i]==j)
		{
			l--,r++;
			i--;
		}
		if(tt<=d) 
		{
			num+=sum(d-tt);
		}
	}
	
	cout<<num<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}