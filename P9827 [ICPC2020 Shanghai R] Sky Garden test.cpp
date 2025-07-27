#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
double ans;
int n,m;

double calc(int x){
	double ret=0;
	for(int i=1;i<m;i++) ret+=min(2.0*x,pi*x*i/m);
	ret*=2;
	ret+=2*x;
	return ret;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			if(i==j) ans+=calc(i)*m;
			else ans+=(2*m*(i-j)+calc(j))*2*m;
	ans+=(m!=1)*(1+n)*n*m;
	cout<<setprecision(10)<<fixed<<ans<<"\n";
}
