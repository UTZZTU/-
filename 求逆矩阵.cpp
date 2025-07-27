#include <bits/stdc++.h>
using namespace std;
void MatrixInverse(float a[][4], float b[][4])
{
	int i, j, k, N = 4;
	float max, temp;
	float t[N][N];
	for (i = 1; i < N; i++)
	{
		for (j = 1; j < N; j++)
		{
			t[i][j] = a[i][j];
		}
	}
	for (i = 1; i < N; i++)
	{
		for (j = 1; j < N; j++)
		{
			b[i][j] = (i == j) ? (float)1 : 0;
		}
	}
	for (i = 1; i < N; i++)
	{
		max = t[i][i];
		k = i;
		for (j = i + 1; j < N; j++)
		{
			if (fabs(t[j][i]) > fabs(max))
			{
				max = t[j][i];
				k = j;
			}
		}
		if (k != i)
		{
			for (j = 1; j < N; j++)
			{
				temp = t[i][j];
				t[i][j] = t[k][j];
				t[k][j] = temp;
				temp = b[i][j];
				b[i][j] = b[k][j];
				b[k][j] = temp;
			}
		}
		if (t[i][i] == 0)
		{
			cout << "\nthe matrix does not exist inverse matrix\n";
			break;
		}
		temp = t[i][i];
		for (j = 1; j < N; j++)
		{
			t[i][j] = t[i][j] / temp;
			b[i][j] = b[i][j] / temp;
		}
		for (j = 1; j < N; j++)
		{
			if (j != i)
			{
				temp = t[j][i];
				for (k = 1; k < N; k++)
				{
					t[j][k] = t[j][k] - temp * t[i][k];
					b[j][k] = b[j][k] - temp * b[i][k];
				}
			}
 
		}
	}
}
int main ()
{
	float solve1[4][4]={
		{0,0,0,0},
		{0,1,0,0},
		{0,0,1,0},
		{0,2,3,1}
	},solve2[4][4]={0};
	MatrixInverse(solve1,solve2);
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<solve2[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}