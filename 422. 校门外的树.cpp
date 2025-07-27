#include <bits/stdc++.h>
using namespace std;
int l,m,x,y,f[10010],ans;
int main ()
{
	cin>>l>>m;
	ans=l+1;
	for(int i=0;i<=l;i++)
	f[i]=1;
	while(m--)
	{
		cin>>x>>y;
		for(int i=x;i<=y;i++)
		{
			if(f[i])
			{
				f[i]=0;
				ans--;
			}
		}
	}
	cout<<ans;
	return 0;
}