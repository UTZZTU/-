#include <iostream>
#include <algorithm>
using namespace std;
struct people
{
    int qian;
    int gs;
    int num;
}s[10010];
bool cmp(people a,people b)
{
    if(a.qian!=b.qian)
        return a.qian>b.qian;
    else
        return a.gs>b.gs;
}
int main ()
{
    int n,i,k,j,bh,je;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        s[i].qian=0;
        s[i].gs=0;
        s[i].num=i;
    }
    for(i=1;i<=n;i++)
    {
        cin>>k;
        for(j=1;j<=k;j++)
        {
            cin>>bh>>je;
            s[bh].gs++;
            s[bh].qian+=je;
            s[i].qian-=je;
        }
    }
    sort(s+1,s+1+n,cmp);
    for(i=1;i<=n;i++)
    {
        double r;
        r=s[i].qian*1.0/100;
        printf("%d %.2f\n",s[i].num,r);
    }
    return 0;
}