#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int n,t;
	cin>>t;
	while(t--)
	{
		vector<int> p;
		cin>>n;
		for(int i=1;i<=n;i++)
		p.push_back(i);
		int js=0;
		while(p.size()>3)
		{
		    vector<int>::iterator it;
			for(it=p.begin();it!=p.end();)
			{
				js++;
				if(js==2)
				{
					js=0;
					it=p.erase(it);
				}
				else
				it++;
			}
			if(p.size()<=3)
			break;
            js=0;
			for(it=p.begin();it!=p.end();)
			{
				js++;
				if(js==3)
				{
					js=0;
					it=p.erase(it);
				}
				else
				it++;
			}
		js=0;
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