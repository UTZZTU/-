#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main ()
{
	int a,b,c;
	while(cin>>a>>b>>c)
	{
		vector<string> p1,p2;
		string x;
		int i;
		for(i=1;i<=a;i++)
		{
			cin>>x;
			p1.push_back(x);
		}
		for(i=1;i<=b;i++)
		{
			cin>>x;
			vector<string>::iterator it=find(p1.begin(),p1.end(),x);
			if(it!=p1.end())
			{
			p2.push_back(x);
			}
		}
		for(i=1;i<=c;i++)
		{
			cin>>x;
			vector<string>::iterator it=find(p2.begin(),p2.end(),x);
			if(it!=p2.end())
			{
				p2.erase(it,it+1);
			}
		}
		if(p2.size()==0)
		printf("No enemy spy\n");
		else
		{
			for(auto it=p2.begin();it!=p2.end();it++)
		{
			if(it!=p2.begin())
			cout<<" ";
			cout<<*it;
		}
		cout<<endl;
		}
	}
	return 0;
}