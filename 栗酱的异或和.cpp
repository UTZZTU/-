#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,m=0,s,a;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            if(i==k-1)a=s;
           // if(i>k-2)
                m=m^s;
        }//cout<<a;
        if(m==0)cout<<"No"<<'\n';
        else if(a<(m^a))cout<<"No"<<'\n';
        else cout<<"Yes"<<'\n';
    }
    return 0;
}