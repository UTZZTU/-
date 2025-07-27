#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p1[10010],p2[10010],h1[10010],h2[10010];
char s1[10010],s2[10010];
ll P = 131,n,m;
ll get(int l,int r,int pos)
{
	if(pos) return h1[r]-h1[l-1]*p1[r-l+1];
	return h2[r]-h2[l-1]*p2[r-l+1];
}
bool check(int x)
{
	unordered_set<ll> hash;
	for(int i=1;i+x-1<=n;i++)
	{
		hash.insert(get(i,i+x-1,1));
	}
	for(int i=1;i+x-1<=m;i++)
	{
		if(hash.count(get(i,i+x-1,0))) return true;
	}
	return false;
}
int main ()
{
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	n=strlen(s1+1),m=strlen(s2+1);
	p1[0]=p2[0]=1;
	for(int i=1;i<=n;i++)
	{
		p1[i]=p1[i-1]*P;
		if(isdigit(s1[i]))
		{
			s1[i]='#';
		}
		h1[i]=h1[i-1]*P+s1[i];
	}
	for(int i=1;i<=m;i++)
	{
		p2[i]=p2[i-1]*P;
		if(isdigit(s2[i]))
		{
			s2[i]='$';
		}
		h2[i]=h2[i-1]*P+s2[i];
	}
	int l=0,r=min(n,m);
	while(l<r)
	{
		int mid=l+r+1>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}