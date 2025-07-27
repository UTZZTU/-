#include <bits/stdc++.h>
using namespace std;
multiset<int> st;
int n,m,k,h;
int main ()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		st.insert(k);
	}
	while(m--)
	{
		scanf("%d %d",&k,&h);
		auto it=st.lower_bound(k);
		if(it==st.begin())
		continue;
		int x=*prev(it);
		st.erase(prev(it));
		st.insert(x+h);
	}
	cout<<*st.rbegin()<<endl;
	return 0;
}