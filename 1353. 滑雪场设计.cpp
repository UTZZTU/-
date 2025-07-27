#include <bits/stdc++.h>
using namespace std;
int maxx,minn=0x3f3f3f3f,n,f[1010];
int hf=0x3f3f3f3f;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
		maxx=max(maxx,f[i]);
		minn=min(minn,f[i]);
	}
	if(maxx-minn<=17)
	cout<<"0";
	else
	{
		for(int i=0;i<=100-17;i++)
		{
			int ans=0;
			for(int j=1;j<=n;j++)
			{
				if(f[j]<i)
				ans+=pow(i-f[j],2);
				else if(f[j]>i+17)
				ans+=pow(f[j]-i-17,2);
			}
			hf=min(hf,ans);
		}
		cout<<hf;
	}
	return 0;
}