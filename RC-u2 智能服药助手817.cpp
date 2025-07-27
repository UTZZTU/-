#include <bits/stdc++.h>
using namespace std;
int n,m,t[1010],cnt[1010],u,v,k;
int main ()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i];
	}
	memset(cnt,-1,sizeof cnt);
	while(m--)
	{
		cin>>u>>v;
		for(int i=1;i<=v;i++)
		{
			cin>>k;
			if(cnt[k]==-1)
			{
				cnt[k]=u;
			}
			else if(t[k]==-1)
			{
				cnt[k]=u;
			}
			else if(u-cnt[k]>=t[k])
			{
				cnt[k]=u;
			}
			else
			{
				cout<<"Don't take "<<k<<" at "<<u<<"!"<<endl;
			}
		}
	}
	return 0;
}