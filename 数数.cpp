#include <bits/stdc++.h>
using namespace std;
int t,n,f[51000];
int get_pri(int x)
{
	set<int> st;
	for(int i=1;i<=floor(sqrt(x));i++)
	{
		if(x%i==0) st.insert(i),st.insert(x/i);
	}
	return st.size();
}
void init()
{
	for(int i=1;i<=4000;i++)
	{
		int pri=get_pri(i);
		if(pri&1) f[i]=1;
		f[i]+=f[i-1];
	}
}
int main ()
{
	init();
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<f[n]<<endl;
	}
	return 0;
}