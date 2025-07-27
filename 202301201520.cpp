#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define endl '\n'
#define close ios::sync_with_stdio(false),cin.tie(0)
using namespace std;
const int N=2e5+5;

void solve(){
    int n;
    cin>>n;
    if(n<=3||n==7){
        cout<<-1<<endl;
        return ;
    }
    vector<int>ans(n+1);
    int g4[4]={3,4,1,2};
    int g5[5]={4,5,1,2,3};
    int g6[6]={4,5,6,1,2,3};
    for(int i=1;i+3<=n;i+=4){
        ans[i]=i+2;
        ans[i+1]=i+3;
        ans[i+2]=i;
        ans[i+3]=i+1;
    }
    if(n%4==1){
        ans[n-4]=n-1;
        ans[n-3]=n;
        ans[n-2]=n-4;
        ans[n-1]=n-3;
        ans[n]=n-2;
    }
    else if(n%4==2){
        ans[n-5]=n-2;
        ans[n-4]=n-1;
        ans[n-3]=n;
        ans[n-2]=n-5;
        ans[n-1]=n-4;
        ans[n]=n-3;
    }
    else if(n%4==3){
        for(int i=n-10,j=0;i<=n-6;i++,j++){
            int x=n-11;
            ans[i]=g5[j]+x;
        }
        for(int i=n-5,j=0;i<=n;i++,j++){
            int x=n-6;
            ans[i]=g6[j]+x;

        }
    }
    cout<<ans[1];
    for(int i=2;i<=n;i++)
        cout<<" "<<ans[i];
    cout<<endl;
}

int main()
{
    close;
    int _=1;
    //cin>>_;
    while(_--){
        solve();
    }
    return 0;
}