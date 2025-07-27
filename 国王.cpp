#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,l,r,x,temp=0;
    scanf("%d %d",&n,&m);
    int a[n+1];
    memset(a,0,sizeof(a));
    while(m--)
    {
        scanf("%d %d %d",&l,&r,&x);
        a[l]+=x;
        a[r+1]-=x;
    }
    for(int i=1; i<n; i++)
    {
        temp+=a[i];//避免了超时
        printf("%d ",temp);
    }
    temp+=a[n];
    printf("%d\n",temp);
    return 0;
}
