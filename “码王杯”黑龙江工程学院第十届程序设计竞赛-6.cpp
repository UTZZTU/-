#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
#define LL long long
int x,y;
vector<int>a[maxn];
queue<int>q;
int b[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;cin>>T;
	while(T--){
		int n,m;cin>>n>>m;
		for(int i=1;i<=n;i++)a[i].clear(),b[i]=0;
		for(int i=1;i<=m;i++){
			int lst,now;
			for(int j=1;j<=n;j++){
				cin>>now;
				if(j>2){
					a[lst].push_back(now);
					b[now]++;
				}
				lst=now;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++)if(b[i]==0)q.push(i);
		while(q.size()){
			int x=q.front();q.pop();cnt++;
			for(int i=0;i<a[x].size();i++){
				int y=a[x][i];
				b[y]--;
				if(b[y]==0)q.push(y);
			}
		}
		if(cnt==n)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
} 
//submit
	    			  	 		 	 		  					 	