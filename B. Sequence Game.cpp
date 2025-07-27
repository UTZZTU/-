#include <bits/stdc++.h>
using namespace std;
int t,n,b[200010];
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		vector<int> vec;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&b[i]);
		}
		for(int i=1;i<=n;i++)
		{
			if(b[i]>=b[i-1]) vec.push_back(b[i]);
			else
			{
				vec.push_back(min(b[i-1]-1,b[i]));
				vec.push_back(b[i]);
			}
		}
		printf("%d\n",vec.size());
		for(int i=0;i<vec.size();i++)
		{
			printf("%d ",vec[i]);
		}
		printf("\n");
	}
	return 0;
}