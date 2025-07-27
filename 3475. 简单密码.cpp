#include <bits/stdc++.h>
using namespace std;
string u,a="START",b="END",c="ENDOFINPUT";
int main ()
{
	while(getline(cin,u))
	{
		if(u==a)
		{
			getline(cin,u);
			for(int i=0;i<u.size();i++)
			{
				if(u[i]>='A'&&u[i]<='Z')
				{
					u[i]='A'+(u[i]-'A'-5+26)%26;
				}
			}
			cout<<u<<endl;
			getline(cin,u);
		}
		else if(u==c)
		break;
	}
	return 0;
}