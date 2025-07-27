#include <bits/stdc++.h>
using namespace std;
#define il inline
int n,f[1000010],tmp[1000010],t;
void merge_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (q[i] <= q[j]) tmp[k ++ ] = q[i ++ ];
        else tmp[k ++ ] = q[j ++ ];

    while (i <= mid) tmp[k ++ ] = q[i ++ ];
    while (j <= r) tmp[k ++ ] = q[j ++ ];

    for (i = l, j = 0; i <= r; i ++, j ++ ) q[i] = tmp[j];
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&f[i]);
	merge_sort(f,1,n);
	printf("%d\n",f[n]);
	}
	return 0;
}