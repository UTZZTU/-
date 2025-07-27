#include <bits/stdc++.h>
using namespace std;
multiset<int> st;
int n,q,a[500010],f[500010],l,r,x;
int main ()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(i==1) f[i]=a[i];
		else f[i]=a[i]-a[i-1],st.insert(abs(f[i]));
	}
	cout<<*st.rbegin()<<endl;
	while(q--)
	{
		scanf("%d%d%d",&l,&r,&x);
		if(l!=1)
		st.erase(st.lower_bound(abs(f[l])));
		if(r+1<=n)
		st.erase(st.lower_bound(abs(f[r+1])));
		f[l]+=x;
		f[r+1]-=x;
		if(l!=1)
		st.insert(abs(f[l]));
		if(r+1<=n) st.insert(abs(f[r+1]));
		auto it = st.rbegin();
		cout<<*st.rbegin()<<endl;
	}
	return 0;
}