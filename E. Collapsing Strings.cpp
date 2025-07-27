#include <bits/stdc++.h>
using namespace std;
//#define int long long
typedef long long ll;
const int N = 1000010;
int tr[N][27],cnt[N],idx,n;
ll ans,pp,sum;
string s;
vector<string> vec;
void insert(string s)
{
    int p=0;
    for(int i=0;i<s.size();i++)
    {
        int u=s[i]-'a';
        if(!tr[p][u]) tr[p][u]=++idx;
        p=tr[p][u];
        cnt[p]++;
    }
}

int query(string s)
{
    int res=0,p=0;
    for(int i=0;i<s.size();i++)
    {
        int u=s[i]-'a';
        if(cnt[tr[p][u]]) res+=cnt[tr[p][u]]*2,p=tr[p][u];
        else return res;
    }
    return res;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        sum+=s.size();
        vec.push_back(s);
        reverse(s.begin(),s.end());
        insert(s);
    }
    for(int i=0;i<n;i++)
    {
        s=vec[i];
        pp=(ll)s.size()*n+sum;
        ans+=pp-query(s);
    }
    cout<<ans<<endl;
    return 0;
}