#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long d,k,ans=1;
    cin>>d;
    if(1<=d&&d<=5){
    for(int i=1;i<=d;i++)
        ans=(ans*i)%(d+1);
    cout<<ans<<endl;
    return 0;}
    d=d-4;
    if(d%6==2||d%6==0){
        cout<<d+4;
        return 0;
    }
    cout<<"0";
    return 0;
}