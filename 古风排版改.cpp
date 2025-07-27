#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int N=0,M=0,b=0;
    string a;
    cin>>N;
    getchar(); 
    getline(cin,a);
	int len=a.size();
	if(len%N==0)
	M=len/N;   
	else
	M=len/N+1;    
	char x[N+5][M+5]={};
	for(int i=M-1;i>=0;i--)
		for(int j=0;j<N;j++)
		{
		 if(b<a.size())
	      x[j][i]=a[b++]; 
	     else
	      x[j][i]=' ';  
		}
	    
	for(int i=0;i<N;i++)
	{
	 for(int j=0;j<M;j++)
	  cout<<x[i][j];
	  cout<<endl;	
	}
	  return 0;  
}