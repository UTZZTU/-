#include <bits/stdc++.h>
using namespace std;
set<char> cs1;
set<pair<char,char>> cs2;
int main ()
{
	string a[3];
	for(int i=0;i<3;i++)
	{
		getline(cin,a[i]);
	}
	for(int i=0;i<3;i++)
	{
		set<char> p;
		for(int j=0;j<3;j++)
		p.insert(a[i][j]);
		if(p.size()==1)
		{
			cs1.insert(a[i][0]);
		}
		else if(p.size()==2)
		{
			char x,y;
			for(auto it=p.begin();it!=p.end();it++)
			{
				if(it==p.begin())
				x=*it;
				else
				y=*it;
			}
			cs2.insert({x,y});
			cs2.insert({y,x});
		}
	}
	for(int i=0;i<3;i++)
	{
		set<char> p;
		for(int j=0;j<3;j++)
		p.insert(a[j][i]);
		if(p.size()==1)
		{
			cs1.insert(a[0][i]);
		}
		else if(p.size()==2)
		{
			char x,y;
			for(auto it=p.begin();it!=p.end();it++)
			{
				if(it==p.begin())
				x=*it;
				else
				y=*it;
			}
			cs2.insert({x,y});
			cs2.insert({y,x});
		}
	}
	set<char> p;
	p.insert(a[0][0]);
	p.insert(a[1][1]);
	p.insert(a[2][2]);
	if(p.size()==1)
		{
			cs1.insert(a[0][0]);
		}
		else if(p.size()==2)
		{
			char x,y;
			for(auto it=p.begin();it!=p.end();it++)
			{
				if(it==p.begin())
				x=*it;
				else
				y=*it;
			}
			cs2.insert({x,y});
			cs2.insert({y,x});
		}
	p.clear();
	p.insert(a[0][2]);
	p.insert(a[1][1]);
	p.insert(a[2][0]);
	if(p.size()==1)
		{
			cs1.insert(a[1][1]);
		}
		else if(p.size()==2)
		{
			char x,y;
			for(auto it=p.begin();it!=p.end();it++)
			{
				if(it==p.begin())
				x=*it;
				else
				y=*it;
			}
			cs2.insert({x,y});
			cs2.insert({y,x});
		}
		cout<<cs1.size()<<endl<<cs2.size()/2;
	return 0;
}