#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
int a[1000010];
int main ()
{
	memset(a,-1,sizeof(a));
	int n,k,max=0;
	cin>>n>>k;
	queue<int> p;
	p.push(0);
	a[0]=0;
	while(!p.empty())
	{
		int q=p.front();
		p.pop();
		if(a[(q+1)%n]==-1)
		{
			p.push((q+1)%n);
			a[(q+1)%n]=a[q]+1;
		}
		if(a[(q+k)%n]==-1)
		{
			p.push((q+k)%n);
			a[(q+k)%n]=a[q]+1;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]>max)
		max=a[i];
	}
	cout<<max;
	return 0;
}