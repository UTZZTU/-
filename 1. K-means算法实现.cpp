#include <bits/stdc++.h>
using namespace std;
int n,m,k,w,judge=1,pre[100010];
struct Node{
	vector<double> vec;
	vector<double> v;
	int num;
}s[100010],t[100010];
double query(vector<double> a,vector<double> b)
{
	double x=0;
	for(int i=0;i<a.size();i++)
	{
		x+=(a[i]-b[i])*(a[i]-b[i]);
	}
	return (double)sqrt(x);
}
int main ()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		pre[i]=-1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&w);
			s[i].vec.push_back(w);
		}
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&w);
		t[i].vec=s[w].vec;
		t[i].num=0;
	}
	while(judge)
	{
		judge=0;
		for(int i=1;i<=n;i++)
		{
			double minn=1234567890,pos=-1;
			for(int j=1;j<=k;j++)
			{
				double x=query(s[i].vec,t[j].vec);
				if(x<minn)
				{
					pos=j;
					minn=x;
				}
			}
			if(pre[i]!=pos)
			{
				judge=1;
				pre[i]=pos;
			}
		}
		if(!judge) break;
		for(int i=1;i<=k;i++)
		{
			for(int j=0;j<t[i].vec.size();j++)
			{
				t[i].vec[j]=0;
			}
			t[i].num=0;
		}
		for(int i=1;i<=n;i++)
		{
			int pos=pre[i];
			for(int j=0;j<s[i].vec.size();j++)
			{
				t[pos].vec[j]+=s[i].vec[j];
			}
			t[pos].num++;
		}
		for(int i=1;i<=k;i++)
		{
			for(int j=0;j<t[i].vec.size();j++)
			{
				t[i].vec[j]=t[i].vec[j]*1.0/t[i].num;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		int pos=pre[i];
		t[pos].v.push_back(i);
	}
	for(int i=1;i<=k;i++)
	{
		printf("cluster%d:",i);
		for(int j=0;j<t[i].v.size();j++)
		{
			if(j) cout<<",";
			cout<<t[i].v[j];
		}
		cout<<endl;
	}
	return 0;
}