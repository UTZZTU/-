#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+10;
vector<int> vec[N];
map<int,bool> mp;
int n,a[N],res;
int get_num(int x,int y)
{
	set<int> st;
	for(int i=x;i<=y;i++)
	{
		for(int j=0;j<vec[i].size();j++) st.insert(vec[i][j]);
	}
	for(auto it=st.begin();it!=st.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	return (int)st.size();
}
signed main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		for(int j=2;j*j<=a[i];j++)
		{
			if(a[i]%j==0)
			{
				while(a[i]%j==0)
				{
					a[i]/=j;
				}
				vec[i].push_back(j);
			}
		}
		if(a[i]>1)
		{
			vec[i].push_back(a[i]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			res+=get_num(i,j);
		}
	}
	cout<<res;
	return 0;
}