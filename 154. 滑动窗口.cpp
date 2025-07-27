#include <bits/stdc++.h>
using namespace std;
deque<int> q;
int n,k,f[1000010];
int main ()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&f[i]);
	for(int i=1;i<=n;i++)
	{
		while(!q.empty()&&q.back()>f[i]) q.pop_back();
		q.push_back(f[i]);
		if(i-k>=1&&q.front()==f[i-k]) q.pop_front();
		if(i>=k) printf("%d ",q.front());
	}
	printf("\n");
	q.clear();
	for(int i=1;i<=n;i++)
	{
		while(!q.empty()&&q.back()<f[i]) q.pop_back();
		q.push_back(f[i]);
		if(i-k>=1&&q.front()==f[i-k]) q.pop_front();
		if(i>=k) printf("%d ",q.front());
	}
	return 0;
}