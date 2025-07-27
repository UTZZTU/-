#include <bits/stdc++.h>
using namespace std;
int f[110][5],k,n,a[110];
int main ()
{
	f[1][0]=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		f[i][0] = max(f[i - 1][0],max(f[i - 1][1],f[i - 1][2]));    //如果今天休息
        f[i][1] = f[i][0];        //为这两个选择先赋初值，因为之后可能会被访问到
        f[i][2] = f[i][0];

        //如果选择去图书馆或者健身房
        if(a[i] == 1 || a[i] == 3) f[i][1] = max(f[i - 1][1],max(f[i - 1][0],f[i - 1][2]) + 1);
        if(a[i] == 2 || a[i] == 3) f[i][2] = max(f[i - 1][2],max(f[i - 1][0],f[i - 1][1]) + 1);
    }

    int res = 0;
    for(int i = 0;i <= 2;i++) res = max(res,f[n][i]);
    res = n - res;
    cout << res << endl;

	return 0;
}