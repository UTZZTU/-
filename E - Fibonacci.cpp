#include <cstdio>
#include <cmath>
int main()
{
	int f[22]={0,1,1};
	for (int i = 3 ; i <= 20 ; i++)
		f[i] = f[i-1] + f[i-2];
	double n;
	double a1 = log10(1.0 / sqrt(5));
	double a2 = log10((1 + sqrt(5)) / 2);
	while (~scanf ("%lf",&n))
	{
		if (n <= 20)
		{
			printf ("%d\n",f[(int)n]);
			continue;
		}
		double ans = a1 + n * a2;
		ans -= floor(ans);
		ans = pow (10,ans);
		ans = (int)(ans * 1000);
		printf ("%.lf\n",ans);
	}
	return 0;
}