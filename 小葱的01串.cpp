#include <bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> mp;
map<pair<int,int>,bool> mp2;
int n,f[1000010],res,num;
string u,v;
int main ()
{
	cin>>n;
	getchar();
	cin>>u;
	v=u+u;
	for(int i=0;i<n;i++)
	{
		if(v[i]=='1') num++,f[i]=1;
		if(i) f[i]+=f[i-1];
		mp2[{f[i],i+1-f[i]}]=true;
		mp[{f[i],i+1-f[i]}]=i;
	}
	if(num&1||(n-num)&1)
	{
		cout<<"0";
		return 0;
	}
	for(int i=n;i<n*2;i++)
	{
		if(v[i]=='1') f[i]=1;
		f[i]+=f[i-1];
		if(mp2[{f[i]-num/2,i+1-f[i]-(n-num)/2}]&&mp[{f[i]-num/2,i+1-f[i]-(n-num)/2}]+n>=i)
		{
			res++;
		}
		mp2[{f[i],i+1-f[i]}]=true;
		mp[{f[i],i+1-f[i]}]=i;
	}
	cout<<res;
	return 0;
}