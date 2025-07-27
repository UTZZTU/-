#include <bits/stdc++.h>
using namespace std;
int n,k,cnt,pp=1;
map<pair<int,int>,bool> mp;
int main ()
{
	scanf("%d%d",&n,&k);
	printf("%d 1\n",n);
	mp[{n,1}]=true;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=2;j++)
		{
			if(pp<=n)
			{
				printf("%d %d\n",i,pp);
				mp[{i,pp}]=true;
			}
			pp++;
		}
		pp--;
	}
	cnt=2*n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(!mp[{i,j}]&&cnt<k)
			{
				cnt++;
				printf("%d %d\n",i,j);
			}
			else if(cnt>=k)
			{
				return 0;
			}	
		}
	}
	return 0;
}