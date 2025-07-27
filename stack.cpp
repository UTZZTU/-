#include <bits/stdc++.h>
using namespace std;
int main ()
{
	stack<string> p1,p2;
	string a="VISIT",b="BACK",c="FORWARD",d="QUIT",e="http://www.acm.org/",x,y,dq;
	dq=e;
	while(cin>>x)
	{
		if(x==d)
		break;
		else
		{
			if(x==a)
			{
				cin>>y;
				p2.push(dq);
				dq=y;
				while(!p1.empty())
				p1.pop();
				cout<<dq<<endl;
			}
			else if(x==b)
			{
				if(p2.empty())
				cout<<"Ignored"<<endl;
				else
				{
					p1.push(dq);
					dq=p2.top();
					p2.pop();
					cout<<dq<<endl;
				}
			}
			else if(x==c)
			{
				if(p1.empty())
				cout<<"Ignored"<<endl;
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
	return 0;
}