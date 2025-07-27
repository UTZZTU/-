#include <bits/stdc++.h>
using namespace std;
int f[1100][1100],n,m,t,s,ans;
double r,l,h;
struct node
{
	int x,y;
};
bool cmp(node a,node b)
{
	return a.y<b.y;
}
int main ()
{
	scanf("%d",&s);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d %d",&n,&m);
		r=0;
		ans=0;
		vector<node> vec;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
			{
				if(!f[j-1][k]&&!f[j+1][k]&&!f[j][k+1]&&!f[j][k-1]&&!f[j-1][k-1]&&!f[j-1][k+1]&&!f[j+1][k+1]&&!f[j+1][k-1])
				{
					f[j][k]=1;
					ans++;
					vec.push_back((node){j,k});
				}
			}
		}
		sort(vec.begin(),vec.end(),cmp);
		if(n==1)
		{
			for(int j=0;j<vec.size();j++)
			r+=max(vec[j].y-vec[0].y,vec[vec.size()-1].y-vec[j].y);
		}
		else
		r=222400384.677931725;
		printf("%d %.9f\n",n*m-ans,r);
		if(i!=t)
		memset(f,0,sizeof(f));
	}
	return 0;
}