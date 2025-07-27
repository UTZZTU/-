#include <bits/stdc++.h>
using namespace std;
string s;
map<long long,long long> mp;
long long maxx1,maxx2,minn1,minn2,cs;
bool isnum(string s)
{
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<'0'||s[i]>'9') return false;
	}
	return true;
}
long long getnum(string s)
{
	long long res=0;
	for(int i=0;i<s.size();i++)
	{
		res=res*10+(s[i]-'0');
	}
	return res;
}

void solve(int pos,string s)
{
	if(isnum(s))
	{
		if(pos==0)
		{
			cs+=getnum(s);
		}
		else cs-=getnum(s);
		return;
	}
	long long p=0,q=0,i=0;
	if(s[0]=='d') p=1;
	else
	{
		for(;i<s.size();i++)
		{
			if(s[i]=='d') break;
			p=p*10+(s[i]-'0');
		}
	}
	i++;
	for(i;i<s.size();i++)
	{
		q=q*10+(s[i]-'0');
	}
	mp[q]+=p;
	if(pos==0)
	{
		maxx1+=p*q;
		minn1+=p;
	}
	else
	{
		maxx2+=p*q;
		minn2+=p;
	}
}
int main ()
{
	getline(cin,s);
	if(s[0]=='-')
	{
		;
	}
	else
	{
		s="+"+s;
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='+')
		{
			string u;
			int j=i+1;
			while(j<s.size()&&s[j]!='+'&&s[j]!='-')
			{
				u+=s[j];
				j++;
			}
			solve(0,u);
			i=j-1;
		}
		else if(s[i]=='-')
		{
			string u;
			int j=i+1;
			while(j<s.size()&&s[j]!='+'&&s[j]!='-')
			{
				u+=s[j];
				j++;
			}
			solve(1,u);
			i=j-1;
		}
	}
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
	cout<<minn1-maxx2+cs<<" "<<maxx1-minn2+cs;
	return 0;
}