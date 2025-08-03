#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n;
string t,s[110];
string cl(string p)
{
	string u="",v="";
	if(p.find("_")!=-1)
	{
		for(int i=0;i<p.size();i++)
		{
			if(p[i]=='_')
			{
				u+=v;
				v="";
			}
			else
			{
				if(v.size()==0)
				{
					v+=p[i]-32;
				}
				else v+=p[i];
			}
		}
		u+=v;
	}
	else if(p[0]>='a'&&p[0]<='z')
	{
		p[0]-=32;
		u=p; 
	}
	else
	{
		u=p;
	}
	return u;
}
void cl1(string p)
{
	p[0]+=32;
	cout<<p<<endl;
}
void cl2(string p)
{
	cout<<p<<endl;
}
void cl3(string p)
{
	string u="",v="";
	for(int i=0;i<p.size();i++)
	{
		if(p[i]>='A'&&p[i]<='Z')
		{
			if(v.size())
			{
				u+=v;
				v="";
				u+='_';
			}
			p[i]+=32;
			v+=p[i];
		}
		else v+=p[i];
	}
	u+=v;
	cout<<u<<endl;
}
void solve()
{
	cin>>n>>t;
//	if(t=="Camel")
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		s[i]=cl(s[i]);
	}
	if(t=="Camel")
	{
		for(int i=1;i<=n;i++)
		{
			cl1(s[i]);
		}
	}
	else if(t=="Pascal")
	{
		for(int i=1;i<=n;i++)
		{
			cl2(s[i]);
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			cl3(s[i]);
		}
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}