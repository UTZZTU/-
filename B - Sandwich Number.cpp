#include <iostream>
using namespace std;
string u;
bool check(string u)
{
	int pos=0,num=0,ls=0;
	if(!(u[0]>='A'&&u[0]<='Z')||!(u[u.size()-1]>='A'&&u[u.size()-1]<='Z'))
	return false;
	if(u.size()==1&&u[0]>='A'&&u[0]<='Z')
	return false;
	for(int i=0;i<u.size();i++)
	{
		if(u[i]>='A'&&u[i]<='Z')
		{
			if(i!=0)
			{
				if(pos!=-1)
			    return false;
			}
			pos=1;
		}
		else
		{
			if(pos!=1)
			return false;
			num=0;
			ls=0;
			int j=i;
			while(j<u.size()&&u[j]>='0'&&u[j]<='9')
			{
				num=num*10+(u[j]-'0');
				if(num>999999)
				return false;
				j++;
				ls++;
			}
			if(num<100000||ls!=6)
			return false;
			pos=-1;
			j--;
			i=j;
		}
	}
	return true;
}
int main ()
{
	cin>>u;
	if(check(u))
	cout<<"Yes";
	else
	cout<<"No";
	return 0;
}