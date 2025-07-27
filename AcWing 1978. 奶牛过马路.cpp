#include <bits/stdc++.h>
using namespace std;
struct node{
    int a,b;
}s[100010];
bool cmp(node x,node y)
{
    return x.a<y.a;
}
int n,f1[100010],f2[100010],res;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&s[i].a,&s[i].b);
    }
    sort(s+1,s+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        if(i==1)
            f1[i]=s[i].b;
        else
            f1[i]=max(f1[i-1],s[i].b);
    }
    for(int i=n;i>=1;i--)
    {
        if(i==n)
            f2[i]=s[i].b;
        else
            f2[i]=min(f2[i+1],s[i].b);
    }
    if(n==1)
    {
        printf("1");
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            if(f2[i+1]>s[i].b)
                res++;
        }
        else if(i==n)
        {
            if(f1[i-1]<s[i].b)
                res++;
        }
        else
        {
            if(f1[i-1]<s[i].b&&f2[i+1]>s[i].b)
                res++;
        }
    }
    printf("%d",res);
    return 0;
}
