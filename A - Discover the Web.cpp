#include <iostream>
#include <stack>
using namespace std;
int main ()
{
	string bd1="VISIT",bd2="BACK",bd3="FORWARD",bd4="QUIT",ks="http://www.lightoj.com/";
	int n,i;
	cin>>n;
	getchar();
	for(i=1;i<=n;i++)
	{
		printf("Case %d:\n",i);
		string a,dq;
		stack<string> p1,p2;
		dq=ks;
		while(cin>>a)
		{
			if(a==bd4)
			break;
			else
			{
				if(a==bd1)
				{
					string b;
					cin>>b;
					p2.push(dq);
					dq=b;
					while(!p1.empty())
					{
						p1.pop();
					}
					cout<<dq<<endl;
				}
				else if(a==bd2)
				{
					if(p2.empty())
					printf("Ignored\n");
					else
					{
						p1.push(dq);
						dq=p2.top();
						p2.pop();
						cout<<dq<<endl;
					}
				}
				else if(a==bd3)
				{
					if(p1.empty())
					{
						printf("Ignored\n");
					}
					else
					{
						p2.push(dq);
						dq=p1.top();
						p1.pop();
						cout<<dq<<endl;
					}
				}
			}
		}
		
	}
	return 0;
}