#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
int main ()
{
	map<string,int> mp;
	char e[50];
	int n,m,i=1,k,sum=0,pd=0;
	double s;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",e);
		mp[e]=-1;
	}
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		getchar();
		scanf("%s %d",e,&k);
		sum+=k;
		if(mp.find(e)==mp.end())
		{
			mp[e]=k;
		}
	}
	s=sum*1.0/m;
	map<string,int> ::iterator it;
	for(it=mp.begin();it!=mp.end();it++)
	{
		if(it->second>=s)
		{
			pd=1;
			cout << (it -> first) << endl;
		}
	}
	if(pd==0)
	printf("Bing Mei You");
	return 0;
}