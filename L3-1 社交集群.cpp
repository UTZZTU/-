#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1005
int father[N];
int course[N];
int root[N];
bool cmp(int a,int b)
{
	return a > b;
}
void Init(int n)
{
	for(int i = 1; i <= n; i++)
		father[i] = i;
}
int Find(int x)
{
	while(father[x] != x)
		x = father[x];
	return x;
}
void Union(int a,int b)
{
	int fa = Find(a);
	int fb = Find(b);
	if(fa != fb)
		father[fa] = fb;
}
int main()
{
	int n;
	scanf("%d",&n);
	Init(n);
	for(int i = 1; i <= n; i++)
	{
		int k;
		scanf("%d:",&k);
		for(int j = 0; j < k; j++)
		{
			int t;
			scanf("%d",&t);
			if(course[t] == 0)
				course[t] = i;
			Union(i,course[t]);
		}
	}
	int count = 0;
	for(int i = 1; i <= n; i++)
	{
		int f = Find(i);
		if(root[f] == 0)
			count++;
		root[f]++;
	}
	printf("%d\n",count);
	sort(root + 1,root + N, cmp);
	int cnt = 0;
	for(int i = 1; root[i] != 0; i++)
	{
		if(cnt == 0)
		{
			cnt++;
			printf("%d",root[i]);
		}
		else
			printf(" %d",root[i]);
	}
	printf("\n");
	return 0;
}