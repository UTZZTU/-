#include <bits/stdc++.h>
using namespace std;
int n,cnt=1,maxx;
struct node
{
	int p1,p2;
}s[1010];
bool cmp(node x,node y)
{
	if(x.p2!=y.p2) return x.p2<y.p2;
	return x.p1<y.p1;
}
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].p1>>s[i].p2;
	}
	sort(s+1,s+1+n,cmp);
	int level;
	if(n==1) level=1;
	else if(n==4) level=2;
	else if(n==9) level=3;
	else level=4;
	maxx=2*level-1;
	for(int i=1;i<=level;i++)
	{
		int num=2*i-1;
		for(int j=1;j<=3*(maxx/2-num/2);j++) cout<<" ";
		for(int j=1;j<=num;j++)
		{
			printf("%02d ",s[cnt++].p1);
		}
		cout<<endl;
	}
	return 0;
}