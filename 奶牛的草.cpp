#include<bits/stdc++.h>
#include<map>
using namespace std;
string s;
int main()
{
    typedef multimap<string,int> MR;
    MR mp;
    int n,m,k;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s>>m;
        mp.insert(make_pair(s,m));
    }
    cin>>k;
    for(int i=0;i<k;i++)
    {
        cin>>s;
        MR::iterator p;
        for(p=mp.begin();p!=mp.end();p++)
        {
            if(s==p->first)
            {
                cout<<p->second<<endl;
            }
        }
    }
    return 0;
}
