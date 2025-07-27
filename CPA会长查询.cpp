#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,a[100010],l,r,x,res;
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i],res+=a[i],a[i]+=a[i-1];
	while(q--)
	{
		cin>>l>>r>>x;
		if((res-(a[r]-a[l-1])+(r-l+1)*x)&1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}