#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	char a[50];
	while(n--)
	{
		cin>>a;
		if(strcmp(a,"Australia")==0)
		printf("Canberra\n");
		else if(strcmp(a,"Belgium")==0)
		printf("Brussels\n");
		else if(strcmp(a,"China")==0)
		printf("Beijing\n");
		else if(strcmp(a,"Denmark")==0)
		printf("Copenhagen\n");
		else if(strcmp(a,"England")==0)
		printf("London\n");
		else if(strcmp(a,"France")==0)
		printf("Paris\n");
		else if(strcmp(a,"Greece")==0)
		printf("Athens\n");
		else if(strcmp(a,"Ireland")==0)
		printf("Dublin\n");
		else if(strcmp(a,"Scotland")==0)
		printf("Edinburgh\n");
		else if(strcmp(a,"Wales")==0)
		printf("Cardiff\n");
		else
		printf("Not found!\n");
	}
	return 0;
}