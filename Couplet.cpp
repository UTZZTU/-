#include <bits/stdc++.h>
using namespace std;
int n,f[100010];
unordered_map<int,bool> mp1;
unordered_map<int,int> mp2;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
		mp1[f[i]]=true;
	}
	int res=1;
	for(int i=1;i<=n;i++)
	{
		if(mp2[f[i]]) printf("%d ",mp2[f[i]]);
		else
		{
			while(mp1[res]) res++;
			printf("%d ",res);
			mp1[res]=true;
			mp2[f[i]]=res;
		}
	}
	return 0;
}