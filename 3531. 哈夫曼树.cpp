#include <bits/stdc++.h>
using namespace std;
int res;
priority_queue<int,vector<int>,greater<int>> p;
int  main ()
{
	int n;
	cin>>n;
	for(int i=1,k;i<=n;i++)
	{
		cin>>k;
		p.push(k);
	}
	while(p.size()>1)
	{
		int u=p.top();p.pop();
		int v=p.top();p.pop();
		p.push(u+v);
		res+=u+v;
	}
	cout<<res;
	return 0;
}