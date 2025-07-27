#include <bits/stdc++.h>
using namespace std;
int n,p[1000010],minn,p1[1000010],p2[100010],cnt1[1000010],cnt2[1000010];
void pre()
{
	for(int i=2;i<=n;i++)
	{
		if(p1[i]>p1[i-1])
		{
			;
		}
		else
		{
			int j=i-1,k=i;
			while(k<=n&&p1[k]<p1[k-1])
			{
				k++;
			}
			k--;
			cnt1[j-1]++;
			cnt1[k]++;
			i=k+1;
			while(j<=k)
			{
				swap(p1[j],p1[k]);
				j++,k--;
			}
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(p1[i]!=p1[i-1]+1)
		{
			cnt1[i-1]++;
		}
	}
	int res=0;
	for(int i=1;i<n;i++)
	{
		if(cnt1[i]) res++;
//		printf("%d ",cnt1[i]);
	}
	minn=min(minn,res);
//	cout<<endl<<res<<endl;
}
void post()
{
	for(int i=2;i<=n;i++)
	{
		if(p2[i]<p2[i-1])
		{
			;
		}
		else
		{
			int j=i-1,k=i;
			while(k<=n&&p2[k]>p2[k-1])
			{
				k++;
			}
			k--;
			cnt2[j-1]++;
			cnt2[k]++;
			i=k+1;
			while(j<=k)
			{
				swap(p2[j],p2[k]);
				j++,k--;
			}
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(p2[i]!=p2[i-1]-1)
		{
			cnt2[i-1]++;
		}
	}
	int res=0;
	for(int i=1;i<n;i++)
	{
		if(cnt2[i]) res++;
//		printf("%d ",cnt2[i]);
	}
	minn=min(minn,res);
//	cout<<endl<<res<<endl;
}
int main ()
{
	scanf("%d",&n);
	minn=n-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		p1[i]=p2[i]=p[i];
	}
	pre();
	post();
	cout<<minn;
	return 0;
}
/*
7
1 7 6 3 2 5 4
*/