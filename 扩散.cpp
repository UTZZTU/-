#include <iostream>
using namespace std;
typedef long long ll;
//曼哈顿法
int main ()
{
	ll ans=0;
	for(int x=-2020;x<=4040;x++)
	{
		for(int y=-2020;y<=4020;y++)
		{
			if(abs(x - 0) + abs(y - 0) <= 2020 || abs(x - 2020) + abs(y - 11) <= 2020 || abs(x - 11) + abs(y - 14) <= 2020 || abs(x - 2000) + abs(y - 2000) <= 2020)
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}