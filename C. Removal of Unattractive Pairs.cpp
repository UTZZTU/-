#include <bits/stdc++.h>
using namespace std;
int n,cnt[30],maxx;
char u[200010];
void solve()
{
	maxx=0;
	scanf("%d",&n);
	getchar();
	scanf("%s",u);
	memset(cnt,0,sizeof cnt);
	maxx=0;
	for(int i=0;i<n;i++)
	{
		cnt[u[i]-'a']++;
		maxx=max(maxx,cnt[u[i]-'a']);
	}
	if(maxx>n-maxx)
	{
		printf("%d\n",2*maxx-n);
	}
	else printf("%d\n",n%2);
}
int main ()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		solve();
	}
	return 0;
}