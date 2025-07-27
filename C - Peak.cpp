#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n,m,f[300010],maxx,pos,cnt=2;
deque<int> q;
int main ()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
	}
	sort(f+1,f+1+n);
	pos=f[1];
	for(int i=1;i<=n;i++)
	{
		if(f[i]<pos+m)
		{
			q.push_back(f[i]);
		}
		else
		{
			maxx=max(maxx,(int)(q.size()));
			pos=f[cnt++];
			while(q.size()&&q.front()<pos)
			{
				q.pop_front();
			}
			i--;
		}
	}
	maxx=max(maxx,(int)(q.size()));
	cout<<maxx;
	return 0;
}