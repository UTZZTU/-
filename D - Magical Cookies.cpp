#include <bits/stdc++.h>
using namespace std;
int h,w,f[2010][2010],res,cnt,vis[2010][2010];
string s[2010];
int main ()
{
	cin>>h>>w;
	for(int i=0;i<h;i++)
	{
		cin>>s[i];
	}
	while(1)
	{
		int flag=0;
		if(!flag)
		{
			break;
		}
	}
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(!f[i][j]) res++;
		}
	}
	cout<<res;
	return 0;
}
/*
iiiooiii
iiioiiii
iiiooiii

iiiiii
iiioiiii
iiiiii
oio
*/