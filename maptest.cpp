#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
int main ()
{
	int n,k;
	cin>>n;
	while(n--)
	{
		cin>>k;
		mp[k]++;
	}
	cout<<mp.size();
	return 0;
}