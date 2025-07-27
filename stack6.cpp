#include <iostream>
#include<cstring>
#include <queue>
using namespace std;
int t,n,m;
int job[100];
struct jobNode
{
	int s;
	int r;
};
queue <jobNode> q;
int a[10];
int getNext(int s)
{
	for(int i=s;i>0;i--)
	{
		if(a[i])return i;
	}
	return 0;
}
int main()
{
    int i,j,max,count;
	jobNode k;
	cin>>t;
	for(i=0;i<t;i++)
	{
		memset(job,0,sizeof(int)*100);
		memset(a,0,sizeof(int)*10);
		cin>>n>>m;
		count=1;
		for(j=0;j<n;j++)
		{
			cin>>job[j];
			a[job[j]]++;
			k.s=j;
			k.r=job[j];
			q.push(k);
		}
		max=getNext(9);
		while(job[m]<max)
		{
			while(q.front().r<max)
			{
			    q.push(q.front());q.pop();
            }
			count++;
			q.pop();
			a[max]--;
			max = getNext(max);
		}
		while(q.front().s!=m)
		{
			if(q.front().r==job[m])
			count++;
			q.pop();
		}
		while(!q.empty())q.pop();
		cout<<count<<endl;
	}
	return 0;
}