#include <iostream>
using namespace std;
int n,le1[10],le2[10],mi1[10],mi2[10],ri1[10],ri2[10],flag;
string r,p;
char s[10][10];
bool judge(int x)
{
	int a=0,b=0,c=0;
	for(int i=0;i<n;i++)
	{
		if(s[x][i]=='A') a++;
		else if(s[x][i]=='B') b++;
		else if(s[x][i]=='C') c++;
	}
	if(!(a==1&&b==1&&c==1)) return false;
	int i=0;
	while(s[x][i]=='.') i++;
	if(s[x][i]!=r[x]) return false;
	return true;
}
bool check()
{
	int a,b,c;
	for(int i=0;i<n;i++)
	{
		a=b=c=0;
		for(int j=0;j<n;j++)
		{
			if(s[i][j]=='A') a++;
			else if(s[i][j]=='B') b++;
			else if(s[i][j]=='C') c++;
		}
		if(!(a==1&&b==1&&c==1)) return false;
	}
	for(int i=0;i<n;i++)
	{
		a=b=c=0;
		for(int j=0;j<n;j++)
		{
			if(s[j][i]=='A') a++;
			else if(s[j][i]=='B') b++;
			else if(s[j][i]=='C') c++;
		}
		if(!(a==1&&b==1&&c==1)) return false;
	}
	for(int i=0;i<n;i++)
	{
		int j=0;
		while(s[i][j]=='.')
		j++;
		if(s[i][j]!=r[i]) return false;
	}
	for(int i=0;i<n;i++)
	{
		int j=0;
		while(s[j][i]=='.')
		j++;
		if(s[j][i]!=p[i]) return false;
	}
	return true;
}
void dfs(int row,int col)
{
//	cout<<row<<" "<<col<<endl;
//	for(int i=0;i<n;i++)
//	{
//		printf("%s\n",s[i]);
//	}
	if(flag)
	{
		return;
	}
	if(row==n)
	{
		if(check())
		{
			flag=1;
			puts("Yes");
			for(int i=0;i<n;i++)
			{
				printf("%s\n",s[i]);
			}
		}
		
		return;
	}
	for(int i=0;i<4;i++)
	{
		if(i==3)
		{
			s[row][col]='.';
			if(col<n-1) dfs(row,col+1);
			else dfs(row+1,0);
		}
		else if(i==0)
		{
			if(!le1[row]&&!le2[col])
			{
				le1[row]=le2[col]=1;
				s[row][col]='A';
				if(col<n-1) dfs(row,col+1);
				else
				{
					if(judge(row))
					{
						dfs(row+1,0);
					}
				}
				le1[row]=le2[col]=0;
			}
		}
		else if(i==1)
		{
			if(!mi1[row]&&!mi2[col])
			{
				mi1[row]=mi2[col]=1;
				s[row][col]='B';
				if(col<n-1) dfs(row,col+1);
				else 
				{
					if(judge(row))
					{
						dfs(row+1,0);
					}
				}
				mi1[row]=mi2[col]=0;
			}
		}
		else if(i==2)
		{
			if(!ri1[row]&&!ri2[col])
			{
				ri1[row]=ri2[col]=1;
				s[row][col]='C';
				if(col<n-1) dfs(row,col+1);
				else
				{
					if(judge(row))
					{
						dfs(row+1,0);
					}
				}
				ri1[row]=ri2[col]=0;
			}
		}
	}
}
int main ()
{
	cin>>n>>r>>p;
	dfs(0,0);
	if(!flag)
	{
		puts("No");
	}
	return 0;
}