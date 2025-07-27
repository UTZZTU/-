#include <bits/stdc++.h>
using namespace std;
int t,n,vis[200010];
struct node
{
	int x,y,res,pos;
}s[200010];
bool cmp(node a,node b)
{
	if(a.res!=b.res)
	return a.res>b.res;
	else return a.pos<b.pos;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&s[i].x);
			s[i].pos=i;
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&s[i].y);
			s[i].res=s[i].x-s[i].y;
		}
		sort(s+1,s+1+n,cmp);
		int r=s[1].res;
		vector<int> vec;
		for(int i=1;i<=n;i++)
		{
			if(s[i].res==r)
			{
				vec.push_back(s[i].pos);
			}
			else break;
		}
		printf("%d\n",vec.size());
		for(int i=0;i<vec.size();i++)
		{
			cout<<vec[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}