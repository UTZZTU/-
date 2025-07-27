#include <bits/stdc++.h>
using namespace std;
#define int long long
int N,H,f[1000010],l,h,t[1000010],minn;
signed main ()
{
	scanf("%lld%lld",&N,&H);
	for(int i=1;i<=N;i++)
	{
		scanf("%lld%lld",&l,&h);
		f[l+1]--,f[h+2]++;
	}
	int res=0;
	for(int i=1;i<=N;i++)
	{
		res+=f[i];
		t[i]=res;
		t[i]+=t[i-1];
//		cout<<res<<endl;
	}
	for(int i=H;i<=N;i++)
	{
		if(i==H) minn=t[i]-t[i-H];
		else minn=min(minn,t[i]-t[i-H]);
	}
	cout<<minn+H*N;
	return 0;
}