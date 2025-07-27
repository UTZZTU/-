#include <bits/stdc++.h>
using namespace std;
struct node
{
	int x,y;
}e[100010];
int ans=0,bj;
int main ()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	scanf("%d %d",&e[i].x,&e[i].y);
	for(int i=2;i<=n-1;i++)
	{
		if(abs(e[i-1].x-e[i].x)+abs(e[i-1].y-e[i].y)+abs(e[i].x-e[i+1].x)+abs(e[i].y-e[i+1].y)-(abs(e[i-1].x-e[i+1].x)+abs(e[i-1].y-e[i+1].y))>ans)
		{
			ans=abs(e[i-1].x-e[i].x)+abs(e[i-1].y-e[i].y)+abs(e[i].x-e[i+1].x)+abs(e[i].y-e[i+1].y)-(abs(e[i-1].x-e[i+1].x)+abs(e[i-1].y-e[i+1].y));
			bj=i;
		}
	}
	int qx=e[1].x,qy=e[1].y;
	ans=0;
	for(int i=2;i<=n;i++)
	{
		if(i==bj)
		continue;
		ans+=abs(qx-e[i].x)+abs(qy-e[i].y);
		qx=e[i].x,qy=e[i].y;
	}
	cout<<ans;
	return 0;
}