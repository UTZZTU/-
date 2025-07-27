#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int  mod;
typedef struct node
{
	__int64 mat[2][2];
}mat;
mat A;  //  定义 A  与 mat相同的结构体
void In()
{
	A.mat[0][0] = 1;
	A.mat[0][1] = 1;
	A.mat[1][0] = 1;
	A.mat[1][1] = 0;
}
mat add(mat a,mat b)   // 矩阵加法
{
	mat C;
	memset(C.mat, 0, sizeof(C.mat)); //  特别注意 等价于  C.mat[i][j] = 0;
	for (int i = 0; i<2; i++)
	{
		for (int j = 0; j<2; j++)
		{		
			C.mat[i][j] = (a.mat[i][j] + b.mat[i][j]) % mod;			
		}
	}
	return C;
}
mat mul(mat a, mat b)  // 矩阵乘法
{
	mat C;
	memset(C.mat, 0, sizeof(C.mat)); //  特别注意 等价于  C.mat[i][j] = 0;
	for (int i = 0; i<2; i++)
	{
		for (int j = 0; j<2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				C.mat[i][j] = (C.mat[i][j] + a.mat[i][k] * b.mat[k][j] % mod) % mod;
			}
		}
	}
	return C;
}
 
mat Pow(mat A, int k)  // 求 A^k
{
	mat B;
	memset(B.mat, 0, sizeof(B.mat)); //  特别注意 等价于  B.mat[i][j] = 0;
	for (int i = 0; i<2; i++)       //  单位矩阵初始化
	{
		B.mat[i][i] = 1;
	}
	while (k>0)
	{
		if (k & 1)  B = mul(B, A);
		A = mul(A, A);
		k >>= 1;
	}
	return B;
}
 
mat Pow1(mat A, __int64 k) //  矩阵中元素是矩阵 的幂次方   // 构造这样   { A  B1 }^k
{														  //   的矩阵    { 0  B2 }        B1=I+A^1+A^2+A^3+A^4+......A^k-1 
	mat B1,B2,I2,I1; 	           
	memset(B1.mat, 0, sizeof(B1.mat)); //  单位矩阵初始化         
	memset(B2.mat, 0, sizeof(B2.mat)); //  单位矩阵初始化
	memset(I1.mat, 0, sizeof(I1.mat)); //  单位矩阵初始化
	memset(I2.mat, 0, sizeof(I2.mat)); //  单位矩阵初始化
	for (int i = 0; i<2; i++)   
	{
		B1.mat[i][i] = 1;
		B2.mat[i][i] = 1;
		I1.mat[i][i] = 1;
		I2.mat[i][i] = 1;
	}
	int a = 1;
	while (k>0)
	{
		if (k & 1)
		{   
			if (a)
			{
				I1 = mul(I1, A);
				I2 = mul(I2, B1);
				a = 0;
			}
			else
			{	
				I2 = add(mul(I1, B1), mul(I2, B2));
				I1 = mul(I1, A);	
			}					
		}		
		  B1 = add(mul(A, B1), mul(B1, B2));
		  A = mul(A, A); 
		  k =k/2;
	}
	return I2;
}
int main()
{
	int k, b;
	__int64 n;
	while (scanf("%d %d %I64d %d",&k,&b,&n,&mod) != EOF)
	{
		mat x,y,z,e;
		In();
		memset(x.mat, 0, sizeof(x.mat));
		memset(y.mat, 0, sizeof(y.mat));
		memset(z.mat, 0, sizeof(z.mat));
		memset(e.mat, 0, sizeof(e.mat));
		y = Pow(A, b);	  //   A^b
		x = Pow(A, k);    //   A^k
		z = Pow1(x, n);	  //   I+A^1+A^2+A^3+A^4+......A^n-1
		e = mul(y, z);
		printf("%d\n", e.mat[0][1] % mod);
 	}
	return 0;
}