#include <iostream>
#include <queue>
using namespace std;
int main ()
{
	int n;
	while(cin>>n)
	{
		if(n==0)
		break;
		else
		{
			queue<int> q;
			for(int i=1;i<=n;i++)
			q.push(i);
			printf("Discarded cards:");
			while(q.size()>1)
		{
			if(q.size()!=n)
			printf(",");
			printf(" %d",q.front());
			q.pop();
			int k=q.front();
			q.pop();
			q.push(k);
		}
		printf("\n");
		printf("Remaining card: %d\n",q.front());
		}
	}
	return 0;
}