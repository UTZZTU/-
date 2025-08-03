#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n;
int le[100],ri[100],num[100],xl[100],cnt=1;
void postorder(int x)
{
	if(le[x]!=0) postorder(le[x]);
	if(ri[x]!=0) postorder(ri[x]);
	num[x]=xl[cnt++];
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>xl[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(i*2<=n) le[i]=i*2;
		if(i*2+1<=n) ri[i]=i*2+1;
	}
	postorder(1);
	for(int i=1;i<=n;i++)
	{
		if(i!=1) cout<<" ";
		cout<<num[i];
	}
}
/*
                    /\
                /\      /\
            /
*/
int main ()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}