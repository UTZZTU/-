#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main ()
{
	string a="wwb",b;
	char s='1',w;
	int x=0,y;
	ofstream out;
	out.open("P:\\666.txt");
	if(out.fail())
	{
		cerr<<"error open this outtxt\n";
		return 1;
	}
	out<<s<<" "<<a<<" "<<x<<endl;
	out.close();
	ifstream in;
	in.open("D:\\555.txt");
	if(in.fail())
	{
		cerr<<"error open this intxt\n";
		return 1;
	}
	in>>w>>b>>y;
	cout<<w<<" "<<b<<" "<<y<<endl;
	return 0;
}