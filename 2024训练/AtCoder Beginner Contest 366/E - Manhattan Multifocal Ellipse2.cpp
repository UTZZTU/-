#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d;
ll tr1[1000010],tr2[1000010];
ll fx[200010],fy[200010],num;
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>fx[i]>>fy[i];
	}
	sort(fx+1,fx+1+n);
	sort(fy+1,fy+1+n);
	ll res=0;
	for(int i=1;i<=n;i++)
	{
		res+=abs(fy[i]-fy[(n+1)/2]);
	}
//	cout<<res<<endl;
	if(res<=d)
	{
//		cout<<fy[(n+1)/2]<<" "<<res<<endl;
		tr1[res]++;
	}
	ll tt=res;
	ll l=(n+1)/2;
	ll r=n-l;
	ll i=(n+1)/2+1,j=fy[(n+1)/2]+1;
//	cout<<"------------"<<endl;
	while(i<=n&&fy[i]==fy[i-1]) 
	{
		l++,r--;
		i++;
	}
//	cout<<"------------"<<endl;
	for(i,j;j<=3000000;j++)
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
			tr1[tt]++;
//			cout<<j<<" "<<tt<<endl;
		}
	}
	
	tt=res;
	l=(n+1)/2-1;
	r=n-l;
	i=(n+1)/2-1,j=fy[(n+1)/2]-1;
	while(i>=1&&fy[i]==fy[i+1]) 
	{
		l--,r++;
		i--;
	}
	for(i,j;j>=-3000000;j--)
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
			 tr1[tt]++;
//			 cout<<j<<" "<<tt<<endl;
		}
	}
	
//	cout<<"------------"<<endl;
	
	res=0;
	for(int i=1;i<=n;i++)
	{
		res+=abs(fx[i]-fx[(n+1)/2]);
	}
	if(res<=d)
	{
//		cout<<fx[(n+1)/2]<<endl;
		tr2[res]++;
	}
	tt=res;
	l=(n+1)/2;
	r=n-l;
	i=(n+1)/2+1,j=fx[(n+1)/2]+1;
	while(i<=n&&fx[i]==fx[i-1])
	{
		l++,r--;
		i++;
	}
	for(i,j;j<=3000000;j++)
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
			tr2[tt]++;
		}
	}
	
	tt=res;
	l=(n+1)/2-1;
	r=n-l;
	i=(n+1)/2-1,j=fx[(n+1)/2]-1;
	while(i>=1&&fx[i]==fx[i+1]) l--,r++,i--;
	for(i,j;j>=-3000000;j--)
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
			tr2[tt]++;
		}
	}
	
	for(int i=1;i<=d;i++)
	{
		tr1[i]+=tr1[i-1];
//		tr2[i]+=tr2[i-1];
	}
	for(int i=0;i<=d;i++)
	{
		if(tr2[i])
		{
			num+=tr2[i]*tr1[d-i];
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