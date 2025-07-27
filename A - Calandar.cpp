#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,yy1,yy2,mm1,mm2,dd1,dd2,current_day,res;
string days[5]={"Monday", "Tuesday", "Wednesday", "Thursday" , "Friday"},day;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>yy1>>mm1>>dd1>>day;
		cin>>yy2>>mm2>>dd2;
		if(day==days[0])
		{
			current_day=0;
		}
		else if(day==days[1])
		{
			current_day=1;
		}
		else if(day==days[2])
		{
			current_day=2;
		}
		else if(day==days[3])
		{
			current_day=3;
		}
		else if(day==days[4])
		{
			current_day=4;
		}
		res=(yy2-1)*360+(mm2-1)*30+dd2-((yy1-1)*360+(mm1-1)*30+dd1);
		if(res>=0)
		{
			cout<<days[(current_day+res)%5]<<endl;
		}
		else
		{
		    cout<<days[((current_day+res)%5+5)%5]<<endl;
		}
	}
	return 0;
}