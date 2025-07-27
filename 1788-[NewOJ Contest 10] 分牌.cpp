#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
int n,k,a[1000010];
map<int,int> mp;
int main ()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mp[a[i]]++;
	}
	while(1)
	{
		vector<int> vec;
		int cnt=0;
		for(auto it=mp.begin();it!=mp.end();it++)
		{
			int fi=it->fi,se=it->se;
			if(se>0)
			{
				vec.push_back(fi);
				cnt++;
				if(cnt==k)
				break;
			}
		}
		if(cnt<k) break;
		else
		{
			for(int i=0;i<cnt;i++)
			{
				printf("%d ",vec[i]);
				mp[vec[i]]--;
			}
			cout<<endl;
		}
	}
	return 0;
}