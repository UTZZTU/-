#include <bits/stdc++.h>
using namespace std;
int lowbit(int x)
{
	return x&-x;
}
int main ()
{
	cout<<lowbit(8);
	return 0;
}