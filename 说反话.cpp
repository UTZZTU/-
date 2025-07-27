#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	string a[1000];
	int i;
	i = 0;
	while(cin >> a[i])
	{
		i++;
	}
	i--;
	for(;i >= 1;i--)
	{
		cout << a[i] << " ";
	}
	cout << a[0];
	return  0;
}