#include <bits/stdc++.h>
using namespace std;
int t,n,a[200010];
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		int i=0;
		int p=a[1],q=a[n];
		if(p==q)
		{
			printf("0\n");
			continue;
		}
		vector<int> final;
		while(p!=q)
		{
			if(p%2==0&&q%2==1)
			{
				p=p>>1,q=q>>1;
				final.push_back(0);
			}
			else
			{
				p=p+1>>1,q=q+1>>1;
				final.push_back(1);
			}
		}
		printf("%d\n",final.size());
		if(final.size()<=n)
		{
			for(int j=0;j<final.size();j++)
			{
				printf("%d ",final[j]);
			}
			printf("\n");
		}
	}
	return 0;
}