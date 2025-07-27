#include <bits/stdc++.h>
using namespace std;
int t,a,b,c,minn,cnt;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		scanf("%d%d%d",&a,&b,&c);
		priority_queue<int> q;
		minn=min(a,min(b,c));
		q.push(a);
		q.push(b);
		q.push(c);
		while(cnt<3&&q.top()!=minn)
		{
			int x=q.top();
//			cout<<x<<endl;
			q.pop();
			int u=minn,v=x-minn;
			q.push(u);
			q.push(v);
			minn=min(minn,x-minn);
			cnt++;
		}
		if(q.top()!=minn) puts("NO");
		else puts("YES");
	}
	return 0;
}