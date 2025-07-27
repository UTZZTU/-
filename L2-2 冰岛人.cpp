#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
struct people
{
	char sex;
	string zx;
};
map<string,people> s;
bool check (string a,string b)
{
	int x=1,y;
	for(string i=a;i.size();i=s[i].zx,x++)
	{
		y=1;
		for(string j=b;j.size();j=s[j].zx,y++)
		{
			if(x>=5&&y>=5)
			break;
			if(i==j)
			return 0;
		}
	}
	return 1;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	string a,b,t;
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		if(b.back()=='n')
		{
			s[a]={'m',b.substr(0,b.length()-4)};
		}
		else if(b.back()=='r')
		{
			s[a]={'f',b.substr(0,b.length()-7)};
		}
		else
		{
			s[a].sex=b.back();
		}
	}
	cin>>m;
	while(m--)
	{
		cin>>a>>t>>b>>t;
		if(s.find(a)==s.end()||s.find(b)==s.end())
		printf("NA\n");
		else if(s[a].sex==s[b].sex)
		printf("Whatever\n");
		else if(check(a,b)==0)
		printf("No\n");
		else if(check(a,b)==1)
		printf("Yes\n");
	}
	return 0;
}