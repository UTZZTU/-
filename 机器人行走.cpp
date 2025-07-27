#include <iostream>
using namespace std;
int main ()
{
	int x=0,y=0;
	int fx=1;
	char s;
	while(cin>>s)
	{
		if(s=='S'||s=='s')
		break;
		else
		{
			if(s=='L'||s=='l')
			{
				if(fx==1)
				fx=3;
				else if(fx==2)
				fx=4;
				else if(fx==3)
				fx=2;
				else
				fx=1;
				if(fx==1)
				y++;
				else if(fx==2)
				y--;
				else if(fx==3)
				x--;
				else
				x++;
			}
			else if(s=='R'||s=='r')
			{
				if(fx==1)
				fx=4;
				else if(fx==2)
				fx=3;
				else if(fx==3)
				fx=1;
				else
				fx=2;
				if(fx==1)
				y++;
				else if(fx==2)
				y--;
				else if(fx==3)
				x--;
				else
				x++;
			}
			else if(s=='G'||s=='g')
			{
				if(fx==1)
				y++;
				else if(fx==2)
				y--;
				else if(fx==3)
				x--;
				else
				x++;
			}
		}
	}
	printf("(%d,%d),",x,y);
	if(fx==1)
	printf("N");
	else if(fx==2)
	printf("S");
	else if(fx==3)
	printf("W");
	else
	printf("E");
	return 0;
}