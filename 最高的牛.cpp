#include<iostream>
#include <set>
using namespace std;
int a[10010];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    set<pair<int,int>> s;
    int m,i,h,p,n,q1,q2;
    cin>>n>>p>>h>>m;
    a[1]=h;
    for(i=1;i<=m;i++)
    {
        cin>>q1>>q2;
        if(q1>q2)
        swap(q1,q2);
        if(!s.count({q1,q2}))
        {
            a[q1+1]--;
            a[q2]++;
            s.insert({q1,q2});
        }
    }
    for(i=1;i<=n;i++)
    {
        a[i]+=a[i-1];
        cout<<a[i]<<endl;
    }
    return 0;
}