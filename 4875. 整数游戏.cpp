#include <bits/stdc++.h>
using namespace std;
int t,n,a[200010],minn;
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		minn=0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			minn=min(minn,a[i]);
		}
		if(a[1]==minn)
		cout<<"Bob"<<endl;
		else
		cout<<"Alice"<<endl;
	}
	return 0;
}