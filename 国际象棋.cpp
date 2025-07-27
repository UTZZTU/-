#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mx=3e6+7;
int n,m;
int k,t;
int a[1207][1207];
int b[1207];
int tx[]={1,1,1,0,-1,-1,-1,0};
int ty[]={-1,0,1,1,1,0,-1,-1};
int G[5];
bool check(int x,int y){
    for(int i=0;i<4;i++)G[i]=1;
    for(int i=0;i<8;i++){
        int oo=0;
        for(int j=1;j<k;j++){
            if(a[ x+j*tx[i] ][ y+j*ty[i] ]==a[x][y]){
                oo++;
            }
            else break;
        }
        G[i%4]+=oo;
        if(G[i%4]>=k)return 1;
    }
    return 0;
}
int main(){
	cin>>n>>m;
	
	cin>>k>>t;
	int ans=t;
	for(int i=1,x;i<=t;i++){
        scanf("%d",&x);
        b[x]++;
        a[x][b[x]]=(i%2)+1;
        if(check(x,b[x])){
            ans=i;
            break;
        }
	}
	cout<<ans;
}