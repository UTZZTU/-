#include <bits/stdc++.h>
using namespace std;
int n,m,u,v,pp[1000010];
vector<int> vec[1000010];
int main ()
{
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d",&u,&v);
		vec[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
	{
		if(vec[i].empty()) continue;
		for(int j=0;j<vec[i].size();j++)
		{
			int k=vec[i][j];
//			cout<<i<<" "<<j<<" "<<k<<endl;
			pp[i]+=vec[k].size();
		}
	}
	for(int i=1;i<=n;i++)
	printf("%d ",pp[i]);
	return 0;
}