#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
multiset<int> mul;
int n,k,minn=0x3f3f3f3f;
int check(int x)
{
	int res=1;
	int be=*mul.begin();
	auto it=mul.upper_bound(be+i);
	while(it!=mul.end())
	{
		be=*it;
		it=mul.upper_bound(be+i);
		res++;
	}
	return res;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		mul.insert(k);
	}
	for(int i=0;i<=200000;i++)
	{
		int num=check(i);
		minn=min(minn,num+i);
	}
	cout<<minn<<endl;
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