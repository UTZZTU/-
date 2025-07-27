#include <bits/stdc++.h>
using namespace std;
string u[30010],v;
map<string,int> mp;
int w,n,k;
int main ()
{
    scanf("%d %d",&w,&n);
    getchar();
    for(int i=1;i<=w;i++)
    {
    	cin>>u[i];
    	mp[u[i]]=i;
	}
    sort(u+1,u+1+w);
    for(int i=1;i<=n;i++)
    {
    	cin>>k>>v;
    	int pos=lower_bound(u+1,u+1+w,v)-u;
    	pos+=k-1;
    	if(pos>w||u[pos].find(v)!=0)
    	cout<<-1<<endl;
    	else
    	cout<<mp[u[pos]]<<endl;
	}
	return 0;
}