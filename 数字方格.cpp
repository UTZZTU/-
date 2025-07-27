#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,max=0;
    cin>>n;
    for(int i=0;i<=n;i++)
    {for(int j=0;j<=n;j++)
    {for(int k=0;k<=n;k++)
    {if((i+j)%2!=0)continue;
    if((j+k)%3!=0)continue;
    if((i+j+k)%5!=0)continue;
    if(i+j+k>max)max=i+j+k;}}}
    cout<<max<<endl;
    return 0;
}
