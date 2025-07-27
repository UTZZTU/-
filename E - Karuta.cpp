#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
unordered_map<string,int> mp1;
string u[500010];
int n,maxx,f[500010];
int leng(string u,string v)
{
	int res=0,i=0,j=0;
	while(i<u.size()&&j<v.size()&&u[i]==v[j])
	{
		res++;
		i++;
		j++;
	}
	return res;
}
int main ()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cin>>n;
	getchar();
	for(int i=1;i<=n;i++)
	{
		cin>>u[i];
		mp1[u[i]]=i;
	}
	sort(u+1,u+1+n);
	for(int i=1;i<n;i++)
	{
		maxx=0;
		maxx=max(maxx,leng(u[i],u[i+1]));
		f[mp1[u[i]]]=max(maxx,f[mp1[u[i]]]);
		f[mp1[u[i+1]]]=max(maxx,f[mp1[u[i+1]]]);
	}
	for(int i=1;i<=n;i++)
	{
		cout<<f[i]<<endl;
	}
	return 0;
}