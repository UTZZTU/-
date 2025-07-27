#include <iostream>
#include <set>
using namespace std;
class settype 
{
public:
 settype();                                  
 void setdata(int *a, int num);     
void display();
 settype operator+(const settype& B) const;    
 settype operator*(const settype& B) const;   
 settype operator-(const settype& B) const;    
 
private:
    int *set;          
    int n;    
 };
 settype::settype()
 {
 	n=0;
 }
 void settype::setdata(int *a, int num)
 {
 	set=new int[num];
 	n=num;
 	for(int i=0;i<num;i++)
 	{
 		set[i]=a[i];
	 }
 }
 void settype::display()
 {
 	for(int i=0;i<n;i++)
 	{
 		if(i!=0)
 		printf(",");
 		cout<<set[i];
	 }
 }
 settype settype::operator+(const settype& B) const
 {
 	int a[100],gs=n;
 	for(int i=0;i<n;i++)
 	{
 		a[i]=set[i];
	 }
	 int pd=0;
	 for(int i=0;i<B.n;i++)
	 {
	 	pd=0;
	 	for(int j=0;j<gs;j++)
	 	{
	 		if(B.set[i]==a[j])
	 		{
	 			pd=1;
	 			break;
			 }
		 }
		 if(pd==0)
			 {
			 	a[gs]=B.set[i];
			 	gs++;
			 }
	 }
 	settype d;
 	d.n=gs;
 	d.set=new int[gs];
 	for(int i=0;i<d.n;i++)
 	{
 		d.set[i]=a[i];
	 }
	 return d;
 }
 settype settype::operator*(const settype& B) const
 {
 	int a[100],ks=0;
 	for(int i=0;i<n;i++)
 	{
 		for(int j=0;j<B.n;j++)
 		{
 			if(set[i]==B.set[j])
 			{
 				a[ks]=set[i];
 				ks++;
 				break;
			 }
		 }
	 }
	 settype c;
	 c.n=ks;
	 c.set=new int[ks];
	 for(int i=0;i<ks;i++)
	 {
	 	c.set[i]=a[i];
	 }
	 return c;
 }
 settype settype::operator-(const settype& B) const
 {
 	int a[100],ks=0,pd=0;
 	for(int i=0;i<n;i++)
 	{
 		pd=0;
 		for(int j=0;j<B.n;j++)
 		{
 			if(set[i]==B.set[j])
 			{
 				pd=1;
 				break;
			 }
		 }
		 if(pd==0)
		 {
		 	a[ks]=set[i];
		 	ks++;
		 }
	 }
	 settype c;
	 c.n=ks;
	 c.set=new int[ks];
	 for(int i=0;i<ks;i++)
	 {
	 	c.set[i]=a[i];
	 }
	 return c;
 }
int main ()
{
	settype A,B,C;
	int a[100],n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	A.setdata(a,n);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	B.setdata(a,n);
	printf("A={");
	A.display();
	printf("}\n");
	printf("B={");
	B.display();
	printf("}\n");
	C=A+B;
	printf("A+B={");
	C.display();
	printf("}\n");
	C=A*B;
	printf("A*B={");
	C.display();
	printf("}\n");
	C=A-B;
	printf("A-B={");
	C.display();
	printf("}\n");
	return 0;
}