#include <iostream>
using namespace std;
template <typename T>
class array
{
	private:
		T *a;
		int gs;
	public:
		array(int n);
		int sizeOfArray();
		void setElement(int index, T item);
		T operator[](int index);
	
};
template <typename T>
array<T>::array(int n)
{
		gs=n;
	       a=new T[gs+1];
}
template <typename T>
int array<T>::sizeOfArray()
{
	return gs;
}
template <typename T>
void array<T>::setElement(int index, T item)
{
	a[index]=item;
}
template <typename T>
T array<T>::operator[](int index)
{
	return a[index];
}
int main ()
{
	int pd,n;
	cin>>pd>>n;
	if(pd==1)
	{
		array<int>p(n);
		int k;
		for(int i=1;i<=n;i++)
		{
			cin>>k;
			p.setElement(i,k);
		}
		int u=p.sizeOfArray();
		for(int i=1;i<=u;i++)
		{if(i!=1)
			cout<<" ";
			cout<<p[i];	
		}
	}
	else if(pd==2)
	{
		array<double> p(n);
		double k;
		for(int i=1;i<=n;i++)
		{
			cin>>k;
			p.setElement(i,k);
		}
		int u=p.sizeOfArray();
		for(int i=1;i<=u;i++)
		{if(i!=1)
			cout<<" ";
			cout<<p[i];	
		}
	}
	else if(pd==3)
	{
		array<char> p(n);
		char k;
		for(int i=1;i<=n;i++)
		{
			cin>>k;
			p.setElement(i,k);
		}
		int u=p.sizeOfArray();
		for(int i=1;i<=u;i++)
		{if(i!=1)
			cout<<" ";
			cout<<p[i];	
		}
	}
	return 0;
}