#include<stdio.h>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main ()
{
	vector<int> a;
	int n,k,i,j,w,e1,e2,e3;
	char s;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&w);
		a.push_back(w);
	}
	for(i=1;i<=k;i++)
	{
		cin>>s;
		if(s=='Z')
		{
			scanf("%d%d",&e1,&e2);
			if(e1>a.size())
			{
				a.push_back(e2);
			}
			else
			{
				a.insert(a.begin()+e1,e2);
			}
		}
		else if(s=='D')
		{
			scanf("%d",&e3);
			if(e3<a.size())
			{
				a.erase(a.begin()+e3);
			}
		}
	}
	printf("%d\n",a.size());
	for(i=0;i<a.size()-1;i++)
	printf("%d ",a[i]);
	printf("%d",a[i]);
	return 0;
 } 
