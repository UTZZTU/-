#include <bits/stdc++.h>
using namespace std;
set<int> p;
int main ()
{
	int n;
	cin>>n;
	for(int i=1,k;i<=n;i++)
	{
		cin>>k;
		p.insert(k);
	}
	for(auto it=p.begin();it!=p.end();it++)
	{
		if(it!=p.begin())
		cout<<" ";
		cout<<*it;
	}
	return 0;
}