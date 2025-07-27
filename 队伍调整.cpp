#include <vector>
#include <stdio.h>
using namespace std;
int main ()
{
	int n,i,m,k;
	vector<int> a;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		a.push_back(k);
	}
	scanf("%d",&m);
	a.erase(a.begin()+m-1);
	for(i=0;i<a.size();i++)
	printf("%d ",a[i]);
}