#include <bits/stdc++.h>
using namespace std;
int n,k,nn,pp;
struct people{
	int pos,money,ans;
}s[10010];
bool cmp(people a,people b)
{
	if(a.money!=b.money)
	return a.money>b.money;
	else if(a.ans!=b.ans)
	return a.ans>b.ans;
	else
	return a.pos<b.pos;
	
}
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		s[i].pos=i;
		s[i].money=s[i].ans=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>nn>>pp;
			s[nn].money+=pp;
			s[nn].ans++;
			s[i].money-=pp;
		}
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		printf("%d %.2f\n",s[i].pos,s[i].money/100.0);
	}
	return 0;
}
