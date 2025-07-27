#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inf 1e18
const int mod=1e9+7;
const int N=2e5+5;
int n,k;
void solve(){
	cin>>n>>k;
	if(n==1){
		cout<<1;
		return;
	}
	int ans=k+1;
	int x=n,cnt=0;
	while(x!=1){
		cnt++;
		int t=sqrt(x);
		if(t!=1){
			if(t*t!=x) ans+=k-cnt; 
		}
		else break;
		x=t;
	}
	cout<<ans+cnt;
}
signed main(){
	int tt=1;
	cin>>tt;
	while(tt--) solve();
	return 0;
}