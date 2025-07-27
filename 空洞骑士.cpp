#include <bits/stdc++.h>
using namespace std;
set<int> st;
vector<int> vec;
int m,k,n;
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>k;
		st.insert(k);
	}
	n=st.size();
	if(n==1)
	{
		cout<<0<<" "<<1000000000<<endl;
	}
	else
	{
		for(auto it=st.begin();it!=st.end();it++)
		{
			vec.push_back(*it);
		}
		if(vec[n-1]+vec[n-1]-1>=1000000000-vec[0]+1000000000-1-vec[0])
		{
			if(vec[n-1]+vec[n-1]-1>=1000000000)
			{
				cout<<0<<" "<<1<<endl;
			}
			else
			{
				cout<<0<<" "<<1000000000<<endl;
			}
		}
		else
		{
			if(1000000000-vec[0]+1000000000-1-vec[0]>=1000000000)
			{
				cout<<1000000000<<" "<<999999999<<endl;
			}
			else
			{
				cout<<0<<" "<<1000000000<<endl;
			}
		}
	}
	return 0;
}