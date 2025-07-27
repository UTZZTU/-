#include <iostream>
using namespace std;
int a[2000];
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,pd=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<n;i++)
            if((a[i]+a[i+1])%2==0)
            {
                printf("NO\n");
                pd=1;
				break;
            }
        if(pd==0)
            printf("YES\n");
    }
    return 0;
}