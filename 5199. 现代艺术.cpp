#include <bits/stdc++.h>
using namespace std;
int n,m,k,f1[5000100],f2[5000100],cnt,t;
long long res;
string c;
int main ()
{
	scanf("%d%d%d",&m,&n,&k);
	getchar();
	while(k--)
	{
		cin>>c>>t;
		if(c=="R") f1[t]++;
		else f2[t]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(f2[i]&1) cnt++;
	}
	for(int i=1;i<=m;i++)
	{
		if(f1[i]&1) res+=n-cnt;
		else res+=cnt;
	}
	cout<<res;
	return 0;
}