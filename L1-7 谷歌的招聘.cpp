#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l,k,res;
string u;
bool judge(ll x)
{
	if(x==1||x==0) return false;
	if(x==2||x==3) return true;
	if(x%6!=1&&x%6!=5) return false;
	for(int i=5;i<=floor(sqrt(x));i+=6)
	{
		if(x%i==0||x%(i+2)==0) return false;
	}
	return true;
}
int num(ll x)
{
	int res=0;
	while(x)
	{
		x/=10;
		res++;
	}
	return res;
}
int main ()
{
	cin>>l>>k;
	cin>>u;
	if(u.size()<k)
	{
		cout<<"404";
		return 0;
	}
	for(int i=0;i<k;i++)
	{
		res=res*10+(u[i]-'0');
	}
	if(judge(res))
	{
		int l=num(res);
		for(int i=1;i<=k-l;i++)
		cout<<0;
		cout<<res;
		return 0;
	}
	for(int i=k;i<l;i++)
	{
		res=res%(ll)pow(10,k-1);
		res=res*10+(u[i]-'0');
		if(judge(res))
		{
			int l=num(res);
			for(int i=1;i<=k-l;i++)
			cout<<0;
			cout<<res;
			return 0;
		}
	}
	cout<<"404";
	return 0;
}