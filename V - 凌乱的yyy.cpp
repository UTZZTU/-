#include <iostream>
#include <algorithm>
using namespace std;
struct contest
{
    int s,e;
};
bool cmp (contest a, contest b)
{
    return a.e < b.e;
}
contest arr [1000005];
int n,st=0,ans=0;
int num[1000005];
int main ()
{
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> arr[i].s >> arr[i].e;
    sort (arr,arr+n,cmp);
    for (int i=0,l=0;i<n;i++)
    {
        if (arr[i].s>=l)
        {
            ans++;
            l=arr[i].e;
        }
    }
    cout << ans;
    return 0;
}

