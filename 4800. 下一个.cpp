#include <bits/stdc++.h>
using namespace std;
int x;
bool judge(int x)
{
	map<int,int> mp;
	while(x)
	{
		mp[x%10]++;
		if(mp[x%10]>1)
		return false;
		x/=10;
	}
	return true;
}
int main ()
{
	cin>>x;
	for(int i=x+1;;i++)
	{
		if(judge(i))
		{
			cout<<i;
			return 0;
		}
	}
	return 0;
}