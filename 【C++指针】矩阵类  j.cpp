#include <iostream>
using namespace std;
class matrix
{
	public:
		int (*s)[100]=new int[100][100];
		matrix(int m,int n)
		{
			int sum=1,ssum=0;
			for(int i=0;i<m;i++)
			{
				for(int j=0;j<n;j++)
				{
					s[i][j]=sum;
					ssum+=sum;
					sum++;
				}
			}
			he=ssum;
		}
		int at(int i)
		{
			return s[0][i-1];
		}
		int at(int i,int j)
		{
			return s[i-1][j-1];
		}
		int sum()
		{
			return he;
		}
	private:
		int he;
};
int main ()
{
	int rowNum,colNum;
 cin>>rowNum>>colNum;
 matrix mat(rowNum,colNum);
 cout<<mat.at(4)<<' '<<mat.at(3,4)<<' '<<mat.sum();
 return 0;
}