#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
vector<int> v[110];
int a[110],b[100010];
int main ()
{
    int n,k,m,t;
    memset(a,1,sizeof(a));
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>b[i];
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>t;
            v[i].push_back(t);
        }
    }
    int sum=0,jc=1;
    while(sum<m)
    {
        for(int i=1;i<=m;i++)
        {
            if(a[i]==0)
                continue;
            int fjc=jc,j;
            for(j=0;j<v[i].size()&&v[i][j]==b[fjc];j++,fjc++)
            ;
            if(j==v[i].size())
            {
                sum++;
                jc=fjc-1;
                a[i]=0;
                if(sum!=1)
                    printf(" ");
                printf("%d",i);
                break;
            }
        }
    }
    return 0;
}