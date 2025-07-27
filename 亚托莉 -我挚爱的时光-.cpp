#include <bits/stdc++.h>
using namespace std;
int n;
string u,v,w,x,y,z;
map<string,bool> mp1,mp2,mp3;
int main ()
{
	cin>>n;
	while(n--)
	{
		cin>>u;
		if(u=="1")
		{
			cin>>v;
			if(mp1[v]==true&&mp2[v]==false&&mp3[v]==false)
			{
				cout<<"yes"<<endl;
			}
			else cout<<"no"<<endl;
		}
		else if(u=="2")
		{
			cin>>v;
			if(mp1[v]==true&&mp3[v]==false)
			cout<<"yes"<<endl;
			else cout<<"no"<<endl;
		}
		else if(u=="sudo")
		{
			cin>>v;
			if(v=="rm")
			{
				cout<<"wuwuwu"<<endl;
				break;
			}
			else
			{
				cin>>x>>y;
				mp1[y]=true;
			}
		}
		else
		{
			cin>>x>>y;
			if(x=="-R")
			{
				mp2[y]=true;
			}
			else mp3[y]=true;
		}
	}
	return 0;
}