#include <iostream>
#include <algorithm>
using namespace std;
struct food
{
	int v;
	int c;
	double b;
}s[1010];
bool cmp(food a,food b)
{
	if(a.b!=b.b)
	return a.b>b.b;
	else
	return a.v>b.v;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,ans1=0,ans2=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>s[i].v;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].c;
		s[i].b=s[i].v*1.0/s[i].c;
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=m;i++)
	{
		ans1+=s[i].v;
		ans2+=s[i].c;
	}
	double r;
	r=ans1*1.0/ans2;
	printf("%.3f",r);
	return 0;
}