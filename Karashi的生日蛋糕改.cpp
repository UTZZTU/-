#include <bits/stdc++.h>
using namespace std;
int n,k,t=1;
vector<int> vec[1000010];
int main ()
{
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	{
		vec[i].push_back(0);
		for(int j=1;j<=n;j++)
		{
			vec[i].push_back(j/k);
		}
	}
	for(int i=1;i<=n;i++)
	{
		int temp=i%k;
		for(int j=1;j<=temp;j++,t=t%k+1) vec[t][i]++;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		printf("%d ",vec[i][j]);
		printf("\n");
	}
	return 0;
}
