/*
	功能：在单链表中统计值为x的结点个数
	输入：键盘输入 
	输出：线性表测试结果 

	编译环境：Dev-C++ v5.11
	开发注释：王文博 
	修订日期：2022年10月4日 

    参考文献：殷人昆《数据结构(用面向对象方法与C++语言描述)(第3版)》,
	版次：2021年9月第3版
	印次：2022年6月第2次印刷
	页码：PP49-75
*/
// ------------------------------ Testing Main ------------------------
#include <iostream>
#include <stdlib.h>
using namespace std;
template <class T>
struct LinkNode
{
	T data;													// 数据域
	LinkNode<T> *link;										// 链指针域
	LinkNode(LinkNode<T> *ptr=NULL) {link = ptr;};			// 构造函数：仅初始化指针成员
	LinkNode(const T &item, LinkNode<T> *ptr = NULL)
		{ data = item;  link = ptr; }						// 构造函数：初始化数据和指针
};

template <class T>
class List
{
	public:
		List() { Sentinel = new LinkNode<T>; }					// 构造函数
	    List(const T x) { Sentinel = new LinkNode<T>(x); }		// 构造函数
	    List(List<T> &L);										// 复制构造函数
	    int Length() const;										// 求表长
	    LinkNode<T> *getSentinel() const {return Sentinel;}		// 返回附加头结点地址
	    LinkNode<T> *Search(T x);								// 搜索数据为x的元素
	    LinkNode<T> *Locate(int i);								// 定位第i个元素
	    bool getData(int i, T &x);								// 获取元素的数据，改课本代码，只读不了
	    void setData(int i, T &x);								// 设置元素的数据，修改元素的数据为x
	    bool Insert (int i, T &x);								// 在第i元素后插入x
	    bool Remove (int i, T &x);								// 删除第i元素，返回删除元素的值x
	    List<T>& operator=(List<T> &L);						    // 重载函数：赋值
	    void output();                                          //输出链表 
	    void inputRear(T x);                                    //输入链表 
	public:
	    LinkNode<T> *Sentinel;
};

template <class T>
List<T>::List(List<T> &L)
{
	T value; 
	LinkNode<T> *srcptr = L.getSentinel();					// 被复制表的表头
	LinkNode<T> *destptr = Sentinel = new LinkNode<T>;		// 复制表的表头
	while(srcptr->link!=NULL)								// 逐个结点复制 
	{ 	
		value=srcptr->link->data;
		destptr->link = new LinkNode<T>(value);
		destptr = destptr->link;
		srcptr = srcptr->link;
	};
	destptr->link=NULL;										// 结束复制表
};

template <class T>
int List<T> :: Length() const 
{
	LinkNode<T> *p = Sentinel->link;						// 检测指针 p 指示第一号结点
	int count = 0; 
	while ( p != NULL )										// 逐个结点检测
	{
		p = p->link;  count++;
	}			
	return count;
}

template <class T>
LinkNode<T> *List<T>::Search(T x)
{
	LinkNode<T> * current = Sentinel->link;
	while (current!= NULL)
		if (current->data==x) break;
		else current = current->link;
	return current;
}

template <class T>
LinkNode<T> *List<T>::Locate(int i)
{
	// 返回表中第 i 个元素的地址。若 i<0 或 i>表中结点数，则返回NULL
	if (i < 0) return NULL;									// i不合理
	LinkNode<T> *current = Sentinel;  int k = 0;
	while ( current != NULL && k < i )
		{ current = current->link; k++; }
	return current;											// 返回第 i 号结点地址或NULL
};

template <class T>
bool List<T>::getData(int i, T &x)
{
	if (i<=0) return false;
    LinkNode<T> *current = Locate(i);
	if (current == NULL) return false;
	else
	{
		x = current->data;
		return true;
	}
};

template <class T>
void List<T>::setData(int i, T &x)
{
	if (i<=0) 
		cerr << "元素赋值时，位置错误!" << endl;
    LinkNode<T> *current = Locate(i);
	if (current == NULL)
		cerr << "元素赋值时，位置超界!" << endl;
	else
		current->data = x;
};

template <class T>
bool List<T> :: Insert(int i, T& x)
{	// 将新元素 x 插入在链表中第 i 个结点之后。
	LinkNode<T> *current = Locate(i);
	if (current == NULL) return false;						// 无插入位置
	LinkNode<T> *newNode = new  LinkNode<T>(x);				// 创建新结点
	newNode->link = current->link;							// 链入
	current->link = newNode;			
	return true;											// 插入成功
};

template <class T>
bool List<T> :: Remove(int i, T& x)
{
	LinkNode<T> *del,*current=Locate(i);
	if(i<=1)
	{
		del=Sentinel;
		Sentinel=Sentinel->link;
	}
	else
	{
		if(current==NULL||current->link==NULL)
		return false;
		del=current->link;
		current->link=del->link;
	}
	x=del->data;
	delete del;
	return true;											// 删除成功
};

template <class T>
List<T>& List<T>:: operator=(List<T>& L)
{
	T value; 
	LinkNode<T> *srcptr = L.getSentinel();					// 被复制表的表头
	LinkNode<T> *destptr = Sentinel = new LinkNode<T>;		// 复制表的表头
	while(srcptr->link!=NULL)								// 逐个结点复制 
	{ 	
		value=srcptr->link->data;
		destptr->link = new LinkNode<T>(value);
		destptr = destptr->link;
		srcptr = srcptr->link;
	};
	destptr->link=NULL;										// 结束复制表
	return * this;											// 赋值给赋值符的左侧变量
};

template <class T>  
void List<T> :: output()     // 以集合形式输出数据
{
       LinkNode<T> *p=Sentinel->link;
       int k=0;
        while(p!=NULL)
        {     
               if(!k)
               {
               	    cout<<p->data;
               	    k++;
			   }
		       else
		       cout<<"-->"<<p->data;
               p=p->link;   
         }
         cout<<endl;
}

template <class T>  
void List<T> :: inputRear(T x)   //输入函数 
{
       int k=0;
       T n;
       while(cin>>n)
       {
       	if(n==x)
       	    break;
       	else
       	{
       		Insert(k,n);
       		k++;
		}
	   }
}

template <class T>
void findall(List<T> LA,T &x,int &sum)
{
	LinkNode<T> *current=LA.Sentinel->link;
	while(current!=NULL)
	{
		if(current->data==x)
		sum++;
		current=current->link;
	}
}
int main ()
{
       List<int> A;
       int sum=0,n;
       A.inputRear(-1);
       cin>>n;
       findall(A,n,sum);
       A.output();
       cout<<sum;
       return 0;  
}

