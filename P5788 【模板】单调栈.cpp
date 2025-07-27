#include <bits/stdc++.h>
using namespace std;
int n,f[3000010],k;
stack<pair<int,int>> st;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		while(st.size()&&st.top().second<k)
		{
			f[st.top().first]=i;
			st.pop();
		}
		st.push({i,k});
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",f[i]);
	}
	return 0;
}