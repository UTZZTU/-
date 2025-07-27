#include <iostream>
#include <set>
using namespace std;
int main ()
{
	set<int> s;
	int n;
	cin>>n;
	while(n--)
	{
		int x,y;
		cin>>x>>y;
		if(x==1)
		{
			s.insert(y);
		}
		else if(x==2)
		{
			set<int>::iterator it=s.find(y);
			if(it!=s.end())
			{
				s.erase(y);
			}
		}
		else
		{
			set<int>::iterator it=s.find(y);
			if(it!=s.end())
			{
				printf("Yes\n");
			}
			else
			printf("No\n");
		}
	}
	return 0;
}