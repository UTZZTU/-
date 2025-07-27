#include <bits/stdc++.h>
using namespace std;
struct node
{
	char st;
	int pi;
}e[1010];
int n,minn=0x3f3f3f3f,ans;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>e[i].st>>e[i].pi;
	for(int i=1;i<=n;i++)
	{
		ans=0;
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			continue;
			if(e[j].st=='G')
			{
				if(e[j].pi>e[i].pi)
				ans++;
			}
			else
			{
				if(e[j].pi<e[i].pi)
				ans++;
			}
		}
		minn=min(minn,ans);
	}
	cout<<minn;
	return 0;
}