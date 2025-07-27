#include <bits/stdc++.h>
using namespace std;
int n,x,y[100010];
int main ()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>y[i];
	}
	sort(y+1,y+1+n);
	if(y[n]>=x) puts("no");
	else puts("yes");
	return 0;
}