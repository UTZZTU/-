#include<iostream>
using namespace std;
int a[2][2];
int main() {
//	int x, y, z, k;
	scanf("%d %d\n", &a[1][1], &a[1][2]);
	scanf("%d %d", &a[2][1], &a[2][2]);
	if (a[1][1] == a[2][2] || a[1][2] == a[2][1])
		printf("YES");
	else printf("NO");
	return 0;
}