#include <bits/stdc++.h>
using namespace std;
int n,m;
struct foods
{
	int v,c;
	double b;
}s[1010];
bool cmp(foods a,foods b)
{
	return a.b>b.b;
}
inline bool check(double r)
{
	for(int i=1;i<=n;i++)
    s[i].b=s[i].v-r*s[i].c;
    sort(s+1,s+1+n,cmp);
    double tot=0;
    for(int i=1;i<=m;i++)
    tot+=s[i].b;
    return tot>=0;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	double l=0,mid,r;
	for(int i=1;i<=n;i++)
	cin>>s[i].v;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].c;
		r=r<s[i].v*1.0/s[i].c?s[i].v*1.0/s[i].c:r;
	}
	while(r-l>1e-6)
	{
		mid=(l+r)/2;
		if(check(mid))
		l=mid;
		else
		r=mid;
	}
	printf("%.3f",l);
	return 0;
}