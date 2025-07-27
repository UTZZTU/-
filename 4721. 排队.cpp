#include <bits/stdc++.h>
using namespace std;
int n,f[100010],post[100010],tt[100010];
vector<int> vec;
int find(int x)
{
	while(x!=post[x])
	x=post[x]=post[post[x]];
	return x;
}
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
		post[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(st.empty()||f[i]>f[st.top()])
		st.push(i);
		else
		{
			while(!st.empty()&&f[i]<f[st.top()])
			{
				int k=st.top();
				st.pop();
				post[k]=i;
			}
			st.push(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		int k=find(post[i]);
		cout<<k<<":";
		printf("%d ",k-i-1);
	}
	return 0;
}