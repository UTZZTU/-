#include <bits/stdc++.h>
using namespace std;
int t,n,a[110],b[110];
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		vector<int> vec[110];
		scanf("%d",&n);
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			b[i]=a[i];
			vec[a[i]].push_back(i);
		}
		for(int i=1;i<=100;i++)
		{
			if(vec[i].size()>=2&&cnt<=1)
			{
				int l=vec[i].size();
				if(cnt==0)
				{
					for(int j=0;j<l;j++)
					{
						b[vec[i][j]]=1;
					}
					b[vec[i][l-1]]=2;
				}
				else if(cnt==1)
				{
					for(int j=0;j<l;j++)
					{
						b[vec[i][j]]=1;
					}
					b[vec[i][l-1]]=3;
				}
				cnt++;
			}
			else if(vec[i].size()>=1)
			{
				int l=vec[i].size();
				for(int j=0;j<l;j++)
				{
					b[vec[i][j]]=1;
				}
			}
		}
		if(cnt>=2)
		{
			for(int i=1;i<=n;i++) printf("%d ",b[i]);
			printf("\n");
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
}