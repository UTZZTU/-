#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>
using namespace std;
int f[200010];
int main ()
{
	memset(f,0xf,sizeof(f));
	vector<int> p;
	int m,i,j;
	cin>>m;
	for(i=1;i<=m;i++)
	{
		if(pow(i,4)<=m)
		p.push_back(pow(i,4));
		else
		break;
	}
	f[0]=0;
	for(auto it=p.begin();it!=p.end();it++)
	{
		for(j=*it;j<=m;j++)
		{
			f[j]=min(f[j],f[j-*it]+1);
		}
	}
	cout<<f[m];
	return 0;
}