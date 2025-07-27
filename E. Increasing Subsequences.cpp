#include <bits/stdc++.h>
using namespace std;
#define int long long
int x,f[65],bj[65];
void init()
{
	f[0]=1;
	for(int i=1;i<=60;i++)
	{
		f[i]=f[i-1]*2;
	}
}
void solve()
{
	cin>>x;
	memset(bj,0,sizeof bj);
	for(int i=60;i>=0;i--)
	{
		if(x>=f[i])
		{
			x-=f[i];
			bj[i]=1;
		}
	}
	vector<int> vec;
	int pos=1,num=0;
	int i=60;
	for(int i=60;i>=0;i--)
	{
		if(bj[i])
		{
			for(int j=pos;j<pos+i;j++) vec.push_back(j);
			bj[i]--;
			break;
		}
	}
	for(int i=vec.size()-1;i>=0;i--)
	{
		if(bj[num])
		{
			auto it=find(vec.begin(),vec.end(),vec[i]);
			vec.insert(it+1,1);
		}
		num++;
	}
	if(vec.size()==0) vec.push_back(1);
	cout<<vec.size()<<endl;
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}
signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	init();
	while(t--)
	{
		solve();
	}
	return 0;
}