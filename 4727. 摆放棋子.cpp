#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e8;
ll n1,n2,k1,k2;
int split(int n, int m)
{
   if(n < 1 || m < 1) return 0;
   if(n == 1 || m == 1) return 1;
   if(n < m) return split(n, n);
   if(n == m) return (split(n, m - 1) + 1);
   if(n > m) return (split(n, m - 1) + split((n - m), m));
}
int main ()
{
//	cin>>n1>>n2>>k1>>k2;
	cout<<split(3,2);
	return 0;
}