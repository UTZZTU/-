#include <bits/stdc++.h>
using namespace std;
#define  PII pair<int,int>
map<PII,bool> mp1,mp2;
int a,b,xk,yk,xq,yq,res;
void tt(int x,int y,int pos)
{
	if(pos==1)
	{
		mp1[{x-a,y-b}]=true;
		mp1[{x-a,y+b}]=true;
		mp1[{x+a,y-b}]=true;
		mp1[{x+a,y+b}]=true;
		mp1[{x-b,y-a}]=true;
		mp1[{x-b,y+a}]=true;
		mp1[{x+b,y-a}]=true;
		mp1[{x+b,y+a}]=true;
	}
	else
	{
		mp2[{x-a,y-b}]=true;
		mp2[{x-a,y+b}]=true;
		mp2[{x+a,y-b}]=true;
		mp2[{x+a,y+b}]=true;
		mp2[{x-b,y-a}]=true;
		mp2[{x-b,y+a}]=true;
		mp2[{x+b,y-a}]=true;
		mp2[{x+b,y+a}]=true;
	}
}
void solve()
{
	mp1.clear();
	mp2.clear();
	res=0;
	cin>>a>>b;
	cin>>xk>>yk;
	cin>>xq>>yq;
	tt(xk,yk,1);
	tt(xq,yq,2);
	for(auto [x,y]:mp1)
	{
		if(mp2[x]) res++;  
	}
	cout<<res<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}