#include <bits/stdc++.h>
using namespace std;
struct node
{
	int start,end;
}s[110];
bool cmp(node a,node b)
{
	return a.end<b.end;
}
int n;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d %d",&s[i].start,&s[i].end);
	sort(s+1,s+1+n,cmp);
	int endtime=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i].start>=endtime)
		{
			endtime=s[i].end;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}