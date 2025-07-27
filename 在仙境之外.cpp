#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,s,a[100010],res=1;
struct node
{
	int i,j,k;
	char c;
};
vector<node> vec;
signed main ()
{
	scanf("%lld%lld",&n,&s);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	vec.push_back({1,1,1,'/'});
	int i=0;
	while(res<=s)
	{
//		cout<<"res:"<<res<<endl;
		if(((s>>i)&1))
		{
			vec.push_back({n+1,n+1,1,'+'});
		}
		vec.push_back({1,1,1,'+'});
		i++;
		res=res*2;
	}
	printf("%d\n",vec.size());
	for(int i=0;i<vec.size();i++)
	{
		printf("%lld %lld %lld %c\n",vec[i].i,vec[i].j,vec[i].k,vec[i].c);
	}
	return 0;
}