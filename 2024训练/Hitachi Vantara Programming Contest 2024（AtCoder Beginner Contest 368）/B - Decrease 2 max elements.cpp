#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n,k,cnt,res;
multiset<int> st;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		st.insert(-k);
	}
	cnt=n;
	while(cnt>1)
	{
		int x=*st.begin();
		st.erase(st.begin());
		int y=*st.begin();
		st.erase(st.begin());
		res++;
		x++;
		y++;
		if(x<0) st.insert(x);
		else cnt--;
		if(y<0) st.insert(y);
		else cnt--;
	}
	cout<<res<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}