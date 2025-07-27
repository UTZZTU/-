#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+10;
int tr[N],n,m,k,t,cnt,f[N],maxx,uu[N],pre[N];
bool check(int x,int mb)
{
	if(f[mb]<=x)
	{
		int pos1=lower_bound(uu+1,uu+1+m,x)-uu;
		int yy=pre[m]-pre[pos1-1]-(m-pos1+1)*x;
//		cout<<pre[m]<<" "<<pre[pos1-1]<<endl;
		if(yy<0) return false;
//		cout<<"yy1:"<<yy<<endl;
		return yy<=k;
	}
	else
	{
		int pos1=lower_bound(uu+1,uu+1+m,x)-uu;
		int yy=pre[m]-pre[pos1-1]-(m-pos1+1)*x-(f[mb]-x);
//		cout<<pre[m]<<" "<<pre[pos1-1]<<endl;
//		cout<<"yy2:"<<yy<<endl;
		if(yy<0) return false;
		return yy<=k;
	}
}
signed main ()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&t);
		f[t]++;
		maxx=max(maxx,f[t]);
	}
	for(int i=1;i<=m;i++)
	{
		uu[i]=f[i];
	}
	sort(uu+1,uu+1+m);
	for(int i=1;i<=m;i++)
	{
		pre[i]=pre[i-1]+uu[i];
	}
	for(int i=1;i<=m;i++)
	{
		if(n-f[i]<k)
		{
			printf("-1 ");
			continue;
		}
		else if(n-f[i]==k)
		{
			printf("0 ");
			continue;
		}
		else
		{
			int l=1,r=maxx;
			while(l<r)
			{
				int mid=l+r>>1;
				if(check(mid,i)) r=mid;
				else l=mid+1;
//				cout<<l<<" "<<r<<endl;
			}
			printf("%lld ",l);
		}
	}
	return 0;
}
/*
7 2 1
1 1 1 2 2 2 2
*/