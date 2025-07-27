#include <bits/stdc++.h>
using namespace std;
string u;
int main ()
{
	while(getline(cin,u))
	{
		if(u.size()==1&&u[0]=='0')
		break;
		stack<double> st;
		int i=0,num=0;
		double s;
		if(u[0]=='-')
		{
			i++;
			while(u[i]==' '&&i<u.size())
			i++;
			for(i;u[i]>='0'&&u[i]<='9'&&i<u.size();i++)
			num=num*10+u[i]-'0';
			s=num;
			st.push(-s);
		}
		else
		{
			for(i;u[i]>='0'&&u[i]<='9'&&i<u.size();i++)
			num=num*10+u[i]-'0';
			s=num;
			st.push(s);
		}
		for(i;i<u.size();i++)
		{
			num=0;
			if(u[i]=='-')
			{
				i++;
				while(u[i]==' '&&i<u.size())
				i++;
				while(u[i]>='0'&&u[i]<='9'&&i<u.size())
				{
					num=num*10+u[i]-'0';
					i++;
				}
				s=num;
				st.push(-s);
			}
			else if(u[i]=='+')
			{
				i++;
				while(u[i]==' '&&i<u.size())
				i++;
				while(u[i]>='0'&&u[i]<='9'&&i<u.size())
				{
					num=num*10+u[i]-'0';
					i++;
				}
				s=num;
				st.push(s);
			}
			else if(u[i]=='*')
			{
				i++;
				while(u[i]==' '&&i<u.size())
				i++;
				while(u[i]>='0'&&u[i]<='9'&&i<u.size())
				{
					num=num*10+u[i]-'0';
					i++;
				}
				s=st.top();
				st.pop();
				s=s*num;
				st.push(s);
			}
			else if(u[i]=='/')
			{
				i++;
				while(u[i]==' '&&i<u.size())
				i++;
				while(u[i]>='0'&&u[i]<='9'&&i<u.size())
				{
					num=num*10+u[i]-'0';
					i++;
				}
				s=st.top();
				st.pop();
				s=s*1.0/num;
				st.push(s);
			}
		}
		s=0;
		while(!st.empty())
		{
			s+=st.top();
			st.pop();
		}
		printf("%.2f\n",s);
	}
	return 0;
}