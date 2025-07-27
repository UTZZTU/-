#include <iostream>
#include <vector>
using namespace std;
int zc=1,bh,sum=1;
vector<int> s[100010];
void dfs(int x)
{
    if(s[x].size()==0)
    {
        if(sum>zc)
        {
            zc=sum;
            bh=x;
        }
        return;
    }
    else
    {
        int i;
        for(i=0;i<s[x].size();i++)
        {
            sum++;
            dfs(s[x][i]);
            sum--;
        }
    }
}
int main ()
{
    
    int n,i,k,j;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>j;
        while(j--)
        {
            cin>>k;
            s[i].push_back(k);
        }
    }
    dfs(1);
    printf("%d",bh);
    return 0;
}