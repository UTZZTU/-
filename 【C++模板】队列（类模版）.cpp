#include <iostream>
using namespace std;
template <class T>
class queue
{
public:
       queue(int num);
       bool insert(T item);   
       T remove();                 
private:
       T *data;
       int maxCount;   
       int  front,rear;      
};
template <class T>
queue<T>::queue(int num)
{
	maxCount=num;
	data=new T[num+1];
	front=1;
	rear=0;
}
template <class T>
bool queue<T>::insert(T item)
{
	if(rear<maxCount)
	{
		data[++rear]=item;
		return true;
	}
	else
	return false;
}
template <class T>
T queue<T>::remove()
{
	front++;
	return data[front-1];
}
int main ()
{
	queue<char> q( 3 ) ;
q.insert( 'A' ) ;
q.insert( 'B' ) ;
q.insert( 'C' ) ;
 
cout << q.remove() ;
cout << q.remove() ;
cout << q.remove() << endl; 
return 0;
}