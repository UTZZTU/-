#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,f[200010];
ll sum;
struct node
{
	int a,b;
}s[200010];
bool cmp(node x,node y)
{
	return x.a<y.a;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&s[i].a,&s[i].b);
		}
		sort(s+1,s+1+n,cmp);
		vector<int> vec;
		vec.push_back(s[n].b);
		for(int i=n-1;i>=1;i--)
		{
			int pos=upper_bound(vec.begin(),vec.end(),s[i].b)-vec.begin();
			sum+=pos;
			vec.insert(upper_bound(vec.begin(),vec.end(),s[i].b),s[i].b);
		}
		printf("%lld\n",sum);
	}
	return 0;
}