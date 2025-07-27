#include <bits/stdc++.h>
using namespace std;
int main ()
{
	set<int> p;
	int n;
	cin>>n;
	for(int i=1,k;i<=n;i++)
	{
		cin>>k;
		set<int>::iterator it=p.lower_bound(k);
		if(it!=p.end())
		{
			p.erase(it);
			p.insert(k);
		}
		else
		p.insert(k);
	}
	cout<<p.size();
	return 0;
}