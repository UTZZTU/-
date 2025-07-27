#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef pair<int,int> PII;
PII q[100];
int p[100],res,n;
int get(PII a,PII b)
{
	if(a.x!=b.x&&a.y!=b.y)
	return -1;
	if(a.x==b.x)
	{
		if(a.y<b.y)
		return 0;
		else
		return 2;
	}
	if(a.x<b.x)
	return 1;
	return 3;
}
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>q[i].x>>q[i].y;
	for(int i=1;i<=n;i++)
	p[i]=i;
	do
	{
		int last=get(q[0],q[p[1]]);
		if(last==-1)
		continue;
		for(int i=2;i<=n+1;i++)
		{
			int d=get(q[p[i-1]],q[p[i]]);
			if(d==-1||d==last)
			{
				last=-1;
				break;
			}
			last=d;
		}
		if(last!=-1)
		res++;
	}while(next_permutation(p+1,p+1+n));
	cout<<res;
	return 0;
}