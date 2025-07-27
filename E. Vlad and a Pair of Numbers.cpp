#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,x,a,b,flag,maxx;
bool check(string u,string v)
{
	ll x1=0,x2=0,k=1;
	for(int i=0;i<u.size();i++)
	{
		x1+=(u[i]-'0')*k;
		k*=2;
	}
	k=1;
	for(int i=0;i<v.size();i++)
	{
		x2+=(v[i]-'0')*k;
		k*=2;
	}
	if(x1<=(ll)pow(2,32)&&x2<=(ll)pow(2,32)&&x1^x2==x&&(x1+x2)%2==0&&(x1+x2)/2==x)
	{
		cout<<x1<<" "<<x2<<endl;
		return true;
	}
	return false;
}
bool check_judge(string u,string v)
{
	ll x1=0,x2=0,k=1;
	for(int i=0;i<u.size();i++)
	{
		x1+=(u[i]-'0')*k;
		k*=2;
	}
	k=1;
	for(int i=0;i<v.size();i++)
	{
		x2+=(v[i]-'0')*k;
		k*=2;
	}
	if(x1>x&&x2>x)
	return true;
	else
	return false;
}
void dfs(string u,string s1,string s2, int level)
{
	if(flag)
	return;
	if(level>=maxx)
	{
		if(check(s1,s2))
		{
			flag=1;
			return;
		}
		if(level>=32)
		return;
	}
	if(check_judge(s1,s2))
	{
		return;
	}
	if(u[level]=='0')
	{
		dfs(u,s1+"1",s2+"1",level+1);
		dfs(u,s1+"0",s2+"0",level+1);
	}
	else
	{
		dfs(u,s1+"1",s2+"0",level+1);
		dfs(u,s1+"0",s2+"1",level+1);
	}
}
bool judge(ll x)
{
	string u,s1,s2;
	ll t=x;
	while(t)
	{
		if(t%2)
		u+='1';
		else
		u+='0';
		t/=2;
		maxx++;
	}
	while(u.size()<=32)
	{
		u+='0';
	}
	dfs(u,s1,s2,0);
	if(flag)
	return true;
	else
	return false;
}
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>x;
		flag=maxx=0;
		if(!judge(x))
		cout<<-1<<endl;
	}
	return 0;
}