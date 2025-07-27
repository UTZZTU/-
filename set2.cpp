#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main ()
{
	int n,m,k;
    while(cin>>n>>m)
    {
    	set<int> p;
    	for(int i=1;i<=n+m;i++)
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
		cout<<endl;
	}
	return 0;
}