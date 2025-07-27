#include <iostream>
using namespace std;
int main ()
{
	int mn=100000;
	for(int i=1;i<=40;i++)
	{
		for(int j=1;j<=100;j++)
		{
			if(i*5+j*2>200)
			break;
			for(int k=1;k<=200;k++)
			{
				if(i*5+j*2+k>200)
				break;
				if(j!=10*k||i*5+j*2+k!=200)
				continue;
				if(i+j+k<mn)
				mn=i+j+k;
			}
		}
	}
	cout<<mn;
	return 0;
}