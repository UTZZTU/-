#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n,q,l,r,f[300010],cnt=1;
string s;
int main ()
{
	scanf("%d%d",&n,&q);
	getchar();
	cin>>s;
	for(int i=1;i<n;i++)
	{
		if(s[i]==s[i-1])
		{
			f[cnt++]=i;
		}
	}
	while(q--)
	{
		scanf("%d%d",&l,&r);
		int pos1=lower_bound(f+1,f+cnt,l)-f;
		int pos2=lower_bound(f+1,f+cnt,r)-f;
		printf("%d\n",pos2-pos1);
	}
	return 0;
}