#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+2;
int q[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	    scanf("%d",&q[i]);
	long long s=0;
	for(int i=1;i<=n;i++)
	{
		if(q[i]==i) continue;
		while(q[i]!=i)
		{
			swap(q[i],q[q[i]]);s++;
		}
	}
	printf("%d",s);
	return 0;
}
