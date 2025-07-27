#include<iostream>
using namespace std;
int n,sum;
int a[1010],s[1010];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>=2)sum^=a[i];
    }
    for(int i=2;i<=n;i++){
        s[i]=sum^a[i];
    }
    int res=-1;
    for(int i=1;i<=a[1]-1;i++){
        for(int j=2;j<=n;j++){
            int hh=s[j]^(a[1]-i)^(a[j]+i);
            if(hh==0){
                cout<<i<<endl;
                return 0;
            }
        }
    }
    cout<<res;
    return 0;
}