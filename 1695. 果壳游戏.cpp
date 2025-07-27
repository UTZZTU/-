#include <bits/stdc++.h>
using namespace std;
struct node
{
	int x,y,z;
};
vector<node> vec;
int a[4],maxn;
int main ()
{
	int n;
	cin>>n;
	for(int i=1,x,y,z;i<=n;i++)
	{
		cin>>x>>y>>z;
		vec.push_back((node){x,y,z});
	}
	for(int i=1;i<=3;i++)
	{
		int js=0;
		memset(a,0,sizeof(a));
		a[i]=1;
		for(int j=0;j<vec.size();j++)
		{
			node u=vec[j];
			int c;
			c=a[u.x];
			a[u.x]=a[u.y];
			a[u.y]=c;
			if(a[u.z])
			js++;
		}
		maxn=max(maxn,js);
	}
	cout<<maxn;
	return 0;
}