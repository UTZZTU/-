#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int main ()
{
	map<int,int> mp;
	int n,mx=0,wz;
	cin>>n;
	while(n--)
	{
		int k;
		cin>>k;
		map<int,int>::iterator it=mp.find(k);
		if(it==mp.end())
		mp[k]=1;
		else
		mp[k]++;
	}
	for(auto it=mp.begin();it!=mp.end();it++)
	{
       if(it->second>mx)
       {
       	mx=it->second;
       	wz=it->first;
	   }
	}
	printf("%d",wz);
	return 0;
}