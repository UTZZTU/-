#include <bits/stdc++.h>
using namespace std;
struct node
{
	int pos,num;
};
stack<node> st;
string u;
int ans,n,wz;
int main ()
{
	cin>>n;
	getchar();
	cin>>u;
	wz=0;
	ans=n;
	for(int i=0;i<u.size();i++)
	{
		if(u[i]=='.')
		continue;
		else if(u[i]=='L')
		{
			if(st.empty())
			{
				ans-=(i+1)-wz;
				wz=i+1;
			}
			else
			{
				ans-=(i+1)-st.top().num+1;
				wz=i+1;
				if(((i+1)-st.top().num+1)&1)
				ans++;
				st.pop();
			}
		}
		else if(u[i]=='R')
		{
			if(st.empty())
			{
				wz=i+1;
				st.push({1,i+1});
			}
			else
			{
				;
			}
		}
	}
	if(!st.empty())
	{
		ans-=n-st.top().num+1;
	}
	cout<<ans;
	return 0;
}