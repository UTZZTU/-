#include <iostream>
using namespace std;
int main ()
{
	for(int i=316;;i++)
	{
		if(i*i>999999)
		break;
		else
		{
			int j=i*i;
			if(j/100000==i/100&&j%10==i/10%10)
			cout<<i<<" "<<i<<" "<<j<<endl;
		}
	}
	return 0;
}