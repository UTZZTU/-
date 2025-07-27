#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 3e5+10;
int n,a[N],t;
int sum[N];
int main() {

	scanf("%d",&t);
	while(t--)
	{
		memset(sum,0,sizeof 0);
	unordered_map<int,int>m;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		m[a[i]]++;
	}
	unordered_map<int,int>mp;
	int cnt=0;
	for(auto &[k,v]:m) {
		mp[v]++;
		cnt=max(cnt,v);
	}
	for(int i=1; i<=n; i++) {
		if(mp[i]>0)sum[i]=sum[i-1]+mp[i];
		else sum[i]=sum[i-1];
	}
	int res=0;
	for(int i=1; i<=n; i++) {
		int ans=0;
		if(i<cnt) {
			res+=(sum[i]-sum[i-1])*i;
			ans+=(i-1)*(sum[cnt]-sum[i]);
		} else {
			res=n;
		}
		cout<<res+ans<<endl;
	}
	}
	return 0;
}