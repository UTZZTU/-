#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,m,a,b,n;
	cin >> n;
	m = n;
	a = m;
	b = m;
	for(i = m;i >= 1;i--)
	{
		for(j = i - 1;j >= 1;j--)
		{
			cout << " ";
		}
		for(j = m;j >= a;j--)
		{
			cout << (char)(j + 64);
		}
		for(j = a + 1;j <= m;j++)
		{
			cout << (char)(j + 64);
		}
		a = a - 1;
		cout << endl;
	}
	a = 2;
	for(i = 2;i <= m;i++)
	{
		for(j = 1;j <= i - 1;j++)
		{
			cout << " ";
		}
		if(i != m)
		{
			for(j = m;j >= a;j--)
			{
				cout << (char)(j + 64);
			}
			for(j = a + 1;j <= m;j++)
			{
				cout << (char)(j + 64);
			}
		}
		else
		{
			cout << (char)(n + 64);
		}
		a = a + 1;
		cout << endl;
	}
	return  0;
}