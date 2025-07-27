#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
	int g;
	cin >> g;
	while (g--)
	{
		int n;
		cin >> n;
		int b[55];
		double k[55];
		double sum = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> b[i];
			k[i] = 640.0 / b[i];
			sum += k[i];
		}
		int flag = 1;
		for (int i = 1; i <= n; i++)
			if (b[i]*k[i] < sum)flag = 0;
		if (flag == 1)cout << "Possible"<<endl;
		else cout << "Impossible"<<endl;
	} 
	return 0;
}