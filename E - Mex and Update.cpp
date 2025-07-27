#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int> mp;
int n,q,a[200010],mex,ix,x;
int main ()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mp[a[i]]++;
	}
	while(mp[mex]>=1)
	{
		mex++;
	}
	while(q--)
	{
		scanf("%d%d",&ix,&x);
		int u=a[ix];
		mp[a[ix]]--;
		a[ix]=x;
		mp[a[ix]]++;
		if(mp[u]==0&&u<mex)
		{
			mex=u;
		}
		else
		{
			while(mp[mex]>=1)
			{
				mex++;
			}
		}
		printf("%d\n",mex);
	}
	return 0;
}