#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int main ()
{
	map<int,int> mp;
	int n,i,k,a[10010],m=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		if(mp.find(k)==mp.end())
		{
			a[m]=k;
			m++;
			mp[k]=1;
		}
		else
		mp[k]++;
	}
	sort(a,a+m);
	for(i=0;i<m;i++)
	printf("%d %d\n",a[i],mp[a[i]]);
	return 0;
}