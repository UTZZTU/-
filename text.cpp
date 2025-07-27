#include<iostream>
using namespace std;
const int N=6e3+10,Q=2e5+10;
int n,q;
int l,r,a[N];
int sum[N][N],sum2[N][N];
int ans[Q];
void Init(){
	for(int i=n-1;i>=1;i--){
		for(int j=i+1;j<=n;j++){
			if(a[j]<a[i]) sum[i][j]=sum[i+1][j]-sum[i+1][j-1]+sum[i][j-1]+1;
			else sum[i][j]=sum[i+1][j]-sum[i+1][j-1]+sum[i][j-1];
		}
	}
	for(int i=n-1;i>=1;i--){
		for(int j=i+1;j<=n;j++){
			if(a[j]>a[i]) sum2[i][j]=sum2[i+1][j]-sum2[i+1][j-1]+sum2[i][j-1]+1;
			else sum2[i][j]=sum2[i+1][j]-sum2[i+1][j-1]+sum2[i][j-1];
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	Init();
	int sumv=sum[1][n];
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>l>>r;
		ans[i]=sumv-sum[l][r]+sum2[l][r];
		cout<<sum[l][r]<<endl;
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
	return 0;
}