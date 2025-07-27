#include <bits/stdc++.h>
using namespace std;
int m,n,k,f[1010];
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>m>>n>>k;
	for(int i=1;i<=k;i++)
	{
		bool judge=true;
		for(int j=1;j<=n;j++)
		{
			cin>>f[j];
		}
		stack<int> st;
		int k=1;
		for(int j=1;j<=n;j++)
		{
			st.push(j);
			if(st.size()>m)
			{
				judge=false;
				break;
			}
			while(!st.empty()&&st.top()==f[k])
			{
				k++;
				st.pop();
			}
		}
		if(!st.empty()||k!=n+1) judge=false;
		if(judge)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}
	return 0;
}
