#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int n,m,a[200010],f[200010];
struct node
{
	int x,y;
	bool operator<(const node &a)const
	{
		if(x!=a.x) return x>a.x;
		else return y<a.y;
	}
};
multiset<node>mul;
int main ()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		if(f[a[i]]==0)
		{
			mul.insert({1,a[i]});
		}
		else
		{
			mul.erase(mul.lower_bound({f[a[i]],a[i]}));
			mul.insert({f[a[i]]+1,a[i]});
		}
		f[a[i]]++;
		auto p=*(mul.begin());
		printf("%d\n",p.y);
	}
	return 0;
}