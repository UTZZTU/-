#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	string s;
	cin>>s;
	int n=s.size();
	s=s+s;
	int cnt=0,num=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1')
		{
			cnt++;
			num=max(num,cnt);
		}
		else cnt=0;
	}
	num=max(num,cnt);
	if(num==0)
	{
		puts("0");
		return;
	}
	if(num==1)
	{
		puts("1");
		return;
	}
	if(num>=n)
	{
		printf("%lld\n",n*n);
		return;
	}
	num++;
	printf("%lld\n",(num/2)*(num-num/2));
	return;
}
signed main ()
{
	int t;
	scanf("%lld",&t);
	while(t--)
	{
		solve();
	}
	return 0;
}