#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
struct Task
{
	int begin;
	int end;
};
int cmp(struct Task t1,struct Task t2)
{
	return t1.end<t2.end;
}
int main()
{
   struct Task t[10001];
   	int N;
   	scanf("%d",&N);
   	for(int i=0;i<N;i++)
   	  scanf("%d %d",&t[i].begin,&t[i].end);
   	sort(t,t+N,cmp);
	int cnt=1;
	int temp=t[0].end;
	for(int i=1;i<N;i++)
	{
		if(t[i].begin>=temp)
		{
			cnt++;
			temp=t[i].end;
		}
	}
	printf("%d",cnt);
	return 0;
}