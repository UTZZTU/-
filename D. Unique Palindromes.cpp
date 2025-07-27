#include <bits/stdc++.h>
using namespace std;
int n,k,x[22],c[22];
void solve()
{
	string s;
	int t=0;
	scanf("%d%d",&n,&k);
	for(int i=0;i<k;i++)
	{
		scanf("%d",&x[i]);
	}
	for(int i=0;i<k;i++)
	{
		scanf("%d",&c[i]);
	}
	if(c[0]>x[0])
	{
		puts("NO");
		return;
	}
	for(int i=1;i<=c[0]-3;i++)
	{
		s+='a';
	}
	while(s.size()<x[0])
	{
		s+='a'+t;
		t=(t+1)%3;
	}
	for(int i=1;i<k;i++)
	{
		if(c[i]-c[i-1]>x[i]-x[i-1])
		{
			puts("NO");
			return;
		}
		for(int j=1;j<=c[i]-c[i-1];j++)
		{
			s+='c'+i;
		}
		while(s.size()<x[i])
		{
			s+='a'+t;
			t=(t+1)%3;
		}
	}
	while(s.size()<n)
	{
		s+='a'+t;
		t=(t+1)%3;
	}
	puts("YES");
	cout<<s<<endl;
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
/*
ababa  a b aba bab ababa
aaaaa a aa aaa aaaa aaaaa
baab a b aa baab
aaaa a aa aaa aaaa

aaaaabaaaa abcabcabc
*/