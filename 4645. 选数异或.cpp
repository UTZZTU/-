#include <bits/stdc++.h>
using namespace std;
int n,m,x,pos[2000010],dp[100010],k,l,r;
int main ()
{
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		pos[k]=i;
		dp[i]=max(dp[i-1],pos[k^x]);
	}
	while(m--){
		cin>>l>>r;
		if(dp[r]>=l) puts("yes");
		else puts("no");
	}
	return 0;
}
