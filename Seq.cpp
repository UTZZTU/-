#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
	int l,r;
};
vector<node> vec;
map<int,int> mp;
int ans,sum;
int main ()
{
	int n,m;
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		vec.push_back((node){x,y});
	}
	reverse(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++)
	{
		sum=0;
		node u=vec[i];
		for(int j=u.l;j<=u.r;j++)
		{
			if(!mp.count(j))
			{
				mp[j]=1;
				sum++;
			}
		}
		if(sum)
		{
			ans++;
		}
	}
	ll o=pow(2,ans);
	cout<<o;
	return 0;
}