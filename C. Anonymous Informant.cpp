#include <bits/stdc++.h>
using namespace std;
int t,n,k,vis[200010],b[200010];
bool judge()
{
	int cnt=0,minn=min(n,k),pos=n;
	int flag=0;
	while(cnt<=minn)
	{
		if(b[pos]>n) break;
		if(vis[pos])
		{
			flag=1;
			break;
		}
		vis[pos]=1;
		int ne=n-b[pos];
		pos+=ne;
		pos%=n;
		if(pos==0) pos=n;
		cnt++;
	}
	if(cnt>=minn||flag) return true;
	else return false;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&b[i]);
			vis[i]=0;
		}
		if(judge())
		{
			puts("Yes");
		}
		else puts("No");
	}
	return 0;
}