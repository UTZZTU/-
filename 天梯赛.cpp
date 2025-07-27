#include <iostream>
#include <string.h>
#include <cmath>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <vector>
using namespace std;
vector<int> v[100010];
int main ()
{
    
    map<int,int> mp;
    int n,m,i,k,t,j,ks=1;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
    	cin>>k;
    	for(j=1;j<=k;j++)
    	{
    		cin>>t;
    		v[i].push_back(t);
		}
	}
	for(i=1;i<=m;i++)
	{
		cin>>k>>j;
		if(k==0)
		{
			ks=v[ks][j-1];
		}
		else if(k==1)
		{
			mp[j]=ks;
			printf("%d\n",ks);
		}
		else
		{
			ks=mp[j];
		}
	}
	printf("%d",ks);
    return 0;
}