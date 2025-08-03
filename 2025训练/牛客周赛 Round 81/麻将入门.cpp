#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int f[3];
void solve()
{
	for(int i=1;i<=3;i++)
	{
		cin>>f[i];
	}
	sort(f+1,f+1+3);
	if(f[1]==f[3]||f[2]==f[1]+1&&f[3]==f[2]+1) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
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