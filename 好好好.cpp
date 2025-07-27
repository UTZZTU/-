#include <bits/stdc++.h>
using namespace std;
int t,n,a[200010],b[200010],res;
bool judge(){
	for(int i=1;i<=n;i++){
		if(i==n&&a[i]!=b[i])
		return false;
		if((a[i]+b[i])&1)
		return false;
		if(a[i]==b[i]) continue;
		if(a[i]<b[i]) res+=(b[i]-a[i])/2,a[i+1]-=(b[i]-a[i]);
		else if(a[i]>b[i]) res+=(a[i]-b[i])/2,a[i+1]+=(a[i]-b[i]);
	}
	return true;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		for(int i=1;i<=n;i++)
		cin>>b[i];
		res=0;
		if(judge())
		cout<<res<<endl;
		else
		cout<<-1<<endl;
	}
	return 0;
}
