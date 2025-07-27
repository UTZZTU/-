#include<iostream>
#include<cstdio>
using namespace std;
int t,n;
long long a[25],del;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=n;i>=0;--i)scanf("%lld",&a[i]);
        if(n==0||n==1)printf("Yes\n");
        else if(n>2)printf("No\n");
        else{
            if(a[1]*a[1]-4*a[0]*a[2]<0)printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}