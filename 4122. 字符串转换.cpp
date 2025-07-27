#include <bits/stdc++.h>
using namespace std;
int t,res,minn;
string s,f;
int count(char x,char y)
{
	if(y>=x)
	{
		return min((int)(y-x),(x-'a')+1+('z'-y));
	}
	else
	{
		return min((int)(x-y),(y-'a')+1+('z'-x));
	}
}
int main ()
{
	scanf("%d",&t);
	getchar();
	for(int i=1;i<=t;i++)
	{
		cin>>s>>f;
		res=0;
		for(int j=0;j<s.size();j++)
		{
			minn=0x3f;
			for(int k=0;k<f.size();k++)
			{
				minn=min(minn,count(s[j],f[k]));
			}
			res+=minn;
		}
		printf("Case #%d: %d\n",i,res);
	}
	return 0;
}