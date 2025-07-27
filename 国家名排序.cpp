#include <iostream>
#include <vector> 
#include <algorithm>
#include <string>
using namespace std;
int main ()
{
	int n;
	while(cin>>n)
	{
		string a;
		vector<string> p;
		for(int i=1;i<=n;i++)
		{
			cin>>a;
			p.push_back(a);
		}
		sort(p.begin(),p.end());
		vector<string>::iterator it;
		for(it=p.begin();it!=p.end();it++)
		{
			if(it==p.begin())
			cout<<*it;
			else
			cout<<" "<<*it;
		}
		cout<<endl;
	}
	return 0;
 } 
