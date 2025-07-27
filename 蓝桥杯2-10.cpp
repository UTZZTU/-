#include<iostream> 
#include<cmath>
using namespace std; 
typedef long long ll;
ll sum;
ll a[1000010];
int main() 
{ 
	ll N;
	int i = 0, j = 0; 
	cin >> N; 
	for (i = 0; i<N; i++) 
		cin >> a[i]; 
	for (i = 0; i<N - 1; i++) { 
		for (j = 0; j<N - 1 - i; j++)
		{
			if (a[j]>a[j + 1]) { 
				ll tmp;
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				sum+=max(a[j],a[j+1]);
			}
		}
	}
	cout << sum;
	return 0; 
}