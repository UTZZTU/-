#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int h[5001],s[5001][5001],ans[5001];
int main(){
    memset(ans,0x3f,sizeof ans);
    int n;
    cin>>n;
    for(int j=1;j<=n;j++){
        cin>>h[j];
    }
    for(int j=2;j<=n;j++){//山脉长度
        for(int i=1;i<=n-j+1;i++){//起点
            s[i][i+j-1]=abs(h[i+j-1]-h[i])+s[i+1][i+j-2];//转移
            ans[j]=min(ans[j],s[i][i+j-1]);
        }
    }
    ans[1]=0;
    for(int j=1;j<=n;j++)cout<<ans[j]<<" ";
}