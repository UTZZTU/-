#include<iostream>
using namespace std;
int main(){
	
    int dp[5005]={0},n,a[105],tot,i,j,s1;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
        tot+=a[i];
    }    
    for(i=1;i<=n;i++)
        for(j=tot/2;j>=a[i];j--){
            dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
        }
    s1=tot-dp[tot/2];
    cout<<s1*s1-dp[tot/2]*dp[tot/2];
}