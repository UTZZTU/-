#include<iostream>
using namespace std;
typedef long long ll;
ll f[3010],a[3010][3010];
int c[3010];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k,t;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        for(int j=1;j<=c[i];j++)
        {
            cin>>t;
            a[i][j]=a[i][j-1]+t;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=k;j>=0;j--)
        {
            for(int w=1;w<=c[i];w++)
            {    
                if(w<=j)
                f[j]=max(f[j],f[j-w]+a[i][w]);
            }
        }
    }
    cout<<f[k];
    return 0;
}