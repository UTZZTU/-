#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main ()
{
	set<int> s;
	int n,m,i,k;
	cin>>n>>m;
	while(n--)
	{
		cin>>k;
		s.insert(k);
	}
	while(m--)
	{
		cin>>k;
		s.insert(k);
	}
	set<int>::iterator it;
	for(it=s.begin();it!=s.end();it++)
	{
		printf("%d ",*it);
	}
	return 0;
}