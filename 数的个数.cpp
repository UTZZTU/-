#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main ()
{
	int n;
	while(cin>>n)
	{
		if(n==0)
		break;
		set<int> p;
		int i,k;
		for(i=1;i<=n;i++)
		{
			cin>>k;
			p.insert(k);
		}
		cout<<p.size()<<endl;
	}
	return 0;
}