#include <bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int ans,num;
}s[1000010];
int get_num(int x)
{
	int res=0;
	while(x)
	{
		res+=x%10;
		x/=10;
	}
	return res;
}
bool cmp(node a,node b)
{
	if(a.ans!=b.ans)
	return a.ans<b.ans;
	else
	return a.num<b.num;
}
int main ()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		s[i].ans=get_num(i);
		s[i].num=i;
	}
	sort(s+1,s+1+n,cmp);
	cout<<s[m].num;
	return 0;
}