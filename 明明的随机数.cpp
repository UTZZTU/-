#include<set>
#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
	set<int> a;
	int n,i,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		a.insert(k);
	}
	set<int>::iterator it;
	printf("%d\n",a.size());
for (it = a.begin(); it != a.end(); it++)
    printf("%d ", *it);

	return 0;
}