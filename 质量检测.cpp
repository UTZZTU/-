#include <bits/stdc++.h>
using namespace std;
int n,k,a[1000010];
deque<int> q;
int main ()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		while(q.size()&&q.back()>a[i]) q.pop_back();
		q.push_back(a[i]);
		if(i-k>=1&&q.front()==a[i-k]) q.pop_front();
		if(i>=k) printf("%d\n",q.front());
	}
	return 0;
}