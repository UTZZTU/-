#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[400010],p[400010],pp[400010],res,r[400010];
int main  ()
{
	scanf("%lld",&t);
	for(int j=1;j<=t;j++)
	{
		scanf("%lld",&n);
		res=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			p[i]=p[i-1]+a[i];
			pp[i]=pp[i-1]+p[i];
		}
		stack<int> st;
		st.push(n+1),p[n+1]=-1e9;
		for(int i=n;i>=0;i--)
		{
			while(p[i]<=p[st.top()])
			{
				st.pop();
			}
			r[i+1]=st.top();
			st.push(i);
		}
		for(int i=1;i<=n;i++)
		{
			int k=r[i];
			res+=pp[k-1]-pp[i-1]-(k-i)*p[i-1];
		}
		printf("Case #%d: %lld\n",j,res);
	}
	return 0;
}