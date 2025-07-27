#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Array
{
public:
    Array()
    {
    	number_of_element=0;
	}
    void Display()
    {
    	for(int i=0;i<number_of_element;i++)
    	{
    		if(i!=0)
    		cout<<" ";
    		cout<<data[i];
		}
		cout<<endl;
	}
    void Sort()
    {
    	cin>>number_of_element;
    	data =new T[number_of_element+1];
    	for(int i=0;i<number_of_element;i++)
    	cin>>data[i];
    	sort(data,data+number_of_element);
	}
private:
    T *data;
    int number_of_element;
};
int main ()
{
	Array<int> int_array;
    Array<double> double_array;
    int_array.Sort();
    int_array.Display();
    double_array.Sort();
    double_array.Display();
    return 0;
}