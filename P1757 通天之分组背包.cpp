#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int f[1010];
struct wp
{
	int weight;
	int value;
};
int main ()
{
	vector<wp> p[1010];
	wp o;
	int m,n,i,j,k,mx=0;
	cin>>m>>n;
	while(n--)
	{
		cin>>o.weight>>o.value>>k;
		mx=max(mx,k);
		p[k].push_back(o);
	}
	for(i=0;i<=mx;i++)
	{
		if(p[i].size()==0)
		continue;
		for(j=m;j>=0;j--)
		{
			for(auto it:p[i])
			{
				if(j>=it.weight)
				f[j]=max(f[j],f[j-it.weight]+it.value);
			}
		}
	}
	cout<<f[m];
	return 0;
}