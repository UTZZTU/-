#include <iostream>
#include <set>
using namespace std;
typedef long long ll;
multiset<ll> st;
ll n,m,k,a[200010];
ll sum()
{
	int i=0;
	ll res=0;
	for(auto it=st.begin();it!=st.end();it++)
	{
		res+=*it;
		i++;
		if(i==k)
		return res;
	}
} 
int main ()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	int i;
	for(i=1;i<=m;i++)
	st.insert(a[i]);
	printf("%lld",sum());
	for(i;i<=n;i++)
	{
		multiset<ll>::iterator it;
		it=st.find(a[i-m]);
		st.erase(it);
		st.insert(a[i]);
		printf(" %lld",sum());
	}
	return 0;
}