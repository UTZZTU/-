#include<iostream>
using namespace std;
int n;
int main()
{
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		int temp = x & -x;//2^k
		cout << x - temp + 1 << " " << x + temp - 1 << endl;
	}
	return 0;
}
