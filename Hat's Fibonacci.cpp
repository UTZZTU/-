#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
const int N=4e5+7;
int ans[2010],a[4][2010];
int main()
{
    int n;
    while(cin>>n)
    {
        if(n<=4)
        {
            cout<<"1"<<endl;
            continue;
        }
        memset(a,0,sizeof(a));
        memset(ans,0,sizeof(ans));
        int len=1;//所求值的长度
        a[0][0]=a[1][0]=a[2][0]=a[3][0]=1;
        for(int i=4;i<n;i++)
        {
            int f=0;
            for(int j=0;j<len;j++)
            {
                int x=f+a[0][j]+a[1][j]+a[2][j]+a[3][j];
                ans[j]=x%10;
                f=x/10;
            }
            while(f)
            {
                ans[len++]=f%10;
                f/=10;
            }
            for(int j=0;j<len;j++)
                a[i%4][j]=ans[j];//求出的第i个值放到a数组中
        }
        for(int i=len-1;i>=0;i--)
            cout<<ans[i];
        cout<<endl;
    }
    return 0;
}
