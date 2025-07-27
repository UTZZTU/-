#include<iostream>
#include<cmath>
using namespace std;
const int maxn=1e5+5;
int maxx[maxn][20];
int minn[maxn][20];
int lg[maxn]={-1};
int query(int l,int r){
	int len=lg[r-l+1];
	int ans1=max(maxx[l][len],maxx[r-(1<<(len))+1][len]);
	int ans2=min(minn[l][len],minn[r-(1<<(len))+1][len]);
	return ans1-ans2;
}
int main(){
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>maxx[i][0];
		minn[i][0]=maxx[i][0];
		lg[i]=lg[i/2]+1;
	}
	for(int i=1;i<=lg[n];i++)
	{
		for(int j=1;j+(1<<i)-1<=n;j++)
		{
			maxx[j][i]=max(maxx[j][i-1],maxx[j+(1<<(i-1))][i-1]);
			minn[j][i]=min(minn[j][i-1],minn[j+(1<<(i-1))][i-1]);
		}
	}
	while(q--){		
		int l,r;
		cin>>l>>r;
		cout<<query(l,r)<<"\n";
	}
} 
