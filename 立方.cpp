#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;
int main()
{
	long double n;
	scanf("%Lf",&n);
	long long sum=pow(n,1.0/3.0);
	printf("%lld",sum);
	return 0;
}
