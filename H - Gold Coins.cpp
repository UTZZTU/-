#include <iostream>
using namespace std;
int s[10010],day,xz,ts;
int main ()
{
	ts=1;
	xz=1;
	for(int i=1;i<=10000;i++)
	{
		if(ts>xz)
		{
			ts=1;
			xz++;
		}
		s[i]=s[i-1]+xz;
		ts++;
	}
	while(cin>>day)
	{
		if(!day)
		break;
		cout<<day<<" "<<s[day]<<endl;
	}
	return 0;
}