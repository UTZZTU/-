#include"iostream"
#include"queue"
#include"deque"
using namespace std;
int m,n;
int num;
long a[30003];
long b[30003];
int i;
priority_queue<long,deque<long>,less<long> >big;
priority_queue<long,deque<long>,greater<long> >small;
int main()
{
	int count;
	while(cin>>m>>n)
	{
		for(i=0;i<m;i++)
			cin >> a[i];
		for(i=0;i<n;i++)
			cin >> b[i];
		count=1;
		num=0;
		i=0;
		while(count<=n)
		{
			for(;i<b[num];i++)
			{
				small.push(a[i]);
				big.push(small.top());
				small.pop();
				small.push(big.top());
				big.pop();
			}
			big.push(small.top());
			small.pop();
			cout << big.top()<< endl;
			count++;
			num++;	
		}
	}
	return 0;
}