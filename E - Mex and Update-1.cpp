#include <bits/stdc++.h>
using namespace std;
int n,q,a[200010],f[200010],ik,x;
set<int> st;
int main ()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]=min(a[i],n);
		f[a[i]]++;
	}
	for(int i=0;i<=n;i++)
	if(!f[i]) st.insert(i);
	while(q--)
	{
		scanf("%d%d",&ik,&x);
		f[a[ik]]--;
		if(f[a[ik]]==0)
		{
			st.insert(a[ik]);
		}
		x=min(x,n);
		a[ik]=x;
		f[x]++;
		if(f[x]==1)
		{
			st.erase(x);
		}
		printf("%d\n",*(st.begin()));
	}
	return 0;
}