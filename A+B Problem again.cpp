#include <iostream>
using namespace std;
int jf(int x1,int x2)
{
    int b[100],q=0,t=0;
    while(x1!=0||x2!=0)
    {
        b[q]=x1%10+x2%10;
        b[q]%=10;
        q++;
        x1/=10;
        x2/=10;
    }
    q--;
    for(q;q>=0;q--)
    {
        t=t*10+b[q];
    }
    return t;
}
int main ()
{
    int n,a[100010],i,j,mx,t;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=n;i++)
    {
        mx=0;
        for(j=1;j<=n;j++)
        {
            if(i==j)
                continue;
            else
                t=jf(a[i],a[j]);
            mx=max(mx,t);
        }
        cout<<mx<<" ";
    }
    return 0;
}