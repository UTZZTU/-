#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string> 
#include<map>
#include<set>
#include<vector>
#include<queue>
#define ll long long
#define maxn 1000010
using namespace std;
string inp;
string s[maxn];
string dp[maxn];
int lenn;
int pos[maxn];
int main()
{
    cin>>inp;
    int len=1;
    for(int i=0;i<inp.size();)
    {
        if(isupper(inp[i]))
        {
            do
            {
                s[len]+=inp[i++];
            }while(islower(inp[i]));
            len++;
        }
    }
    dp[1]=s[1];
    pos[1]=1;
    lenn=1;
    for(int i=1;i<len;i++)
    {
        if(s[i]>dp[lenn])
        {
            dp[++lenn]=s[i];
            pos[i]=lenn;
        }
        else
        {
            int x=lower_bound(dp+1,dp+1+lenn,s[i])-dp;
            dp[x]=s[i];
            pos[i]=x;
        }
    }
    string maxx="zzzzzzzzzzz";
    vector<string> v;
    for(int i=len-1;i>=1;i--)
    {
        if(len==0)
        break;
        if(pos[i]==lenn && maxx>s[i])
        {
            lenn--;
            maxx=s[i];
            v.push_back(s[i]);
        }
    }
    for(int i=v.size()-1;i>=0;i--)
    {
        cout<<v[i];
    }
    cout<<endl;
}