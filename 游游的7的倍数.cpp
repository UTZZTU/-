#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string x;
bool check(string t)
{
	ll res=0;
	for(int i=0;i<t.size();i++) res=res*10+(t[i]-'0');
	if(res%7==0) return true;
	return false;
}
string get_str(int x)
{
	if(x==0) return "0";
	else if(x==1) return "1";
	else if(x==2) return "2";
	else if(x==3) return "3";
	else if(x==4) return "4";
	else if(x==5) return "5";
	else if(x==6) return "6";
	else if(x==7) return "7";
	else if(x==8) return "8";
	else return "9";
}
int main ()
{
	cin>>x;
	for(int i=1;i<=9;i++)
	{
		string v=get_str(i)+x;
		if(check(v))
		{
			cout<<v;
			return 0;
		}
	}
	for(int i=0;i<=9;i++)
	{
		string v=x+get_str(i);
		if(check(v))
		{
			cout<<v;
			return 0;
		}
	}
	for(int i=0;i<x.size()-1;i++)
	{
		for(int j=0;j<=9;j++)
		{
			string u=x.substr(0,i+1)+get_str(j)+x.substr(i+1,x.size()-i-1);
			if(check(u))
			{
				cout<<u;
				return 0;
			}
		}
	}
	return 0;
}