/*
	功能：Kruskal算法实现道路建设
	输入：村庄数、道路数、 道路信息以及已建道路信息 
	输出：最小的新建道路长度和 

	编译环境：Dev-C++ v5.11
	开发注释：王文博 
	修订日期：2022年12月10日 

	参考文献：殷人昆《数据结构(用面向对象方法与C++语言描述)(第3版)》
	版次：2021年9月第3版			印次：2021年9月第1次印刷
	页码：PP335-9
*/
#include<iostream>
#include <algorithm>
using namespace std;
const int heh = 20;
const int max = 32767;

#define re register  //加快编译速度 
#define il inline    //设置内联函数，加快编译速度 

struct Edges //设置存边的结构体 
{
	int u,v,w;
}edge[200005];

struct letter  //存新建的道路边的结构体 
{
	int u,v,w;
}s[200005];
int fa[5005],n,m,ans,eu,ev,k,cnt;  //必要元素，如并查集等 
char c1,c2;
 
il bool cmp1(Edges a,Edges b)     //手写重排函数1
{
    return a.w<b.w;
}

il bool cmp2(letter a,letter b)     //手写重排函数2
{
    if(a.u!=b.u)
    return a.u<b.u;
    else
    return a.v<b.v;
}

il int find(int x)               //find函数找祖先 
{
    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}

il void kruskal()
{
    sort(edge,edge+m,cmp1);
    //对边集进行从小到大排序 
    for(re int i=0;i<m;i++)
    {
        eu=find(edge[i].u), ev=find(edge[i].v);
        if(eu==ev)
        {
            continue;
        }
        //如果两个结点的祖先节点是一样的，就不加入了 
        s[++cnt].u=edge[i].u;
        s[cnt].v=edge[i].v;
        s[cnt].w=edge[i].w;
        //存入要建的新道路的信息 
        ans+=edge[i].w;
        //否则，一定会取到这个边
        fa[ev]=eu;
        //合并祖先 
    }
}

il void pre_process(int x,int y)  //预处理 
{
	eu=find(x), ev=find(y);
    if(eu!=ev)
    {
        fa[ev]=eu;
        //如果不相等，则合并祖先 
    }
}
    
template <class T>
struct Edge
{
	int dest;
	Edge<T>* link;
	Edge() {}
	Edge(int num) :dest(num), link(NULL) {}
};

//图中顶点的定义 
template <class T>
struct  Vertex
{
	T data;
	Edge<T>* adj;
};

template <class T>
class Graphlnk
{
public:
	Graphlnk(int sz = heh);//图的构造函数 
	~Graphlnk();//图的析构函数 
	T getValue(int i)//得到下标为i的顶点 
	{
		return (i >= 0 && i < numVertices) ? NodeTable[i].data : 0;
	}
	int getVnum()//得到当前图中结点数 
	{
		return numVertices;
	}
	int getEnum()//得到当前图中边的数目 
	{
		return numEdges;
	}
	bool insertVertex(const T& vertex);//插入结点 
	bool insertEdge(int v1, int v2);//插入边 
	int getFirstNeighbor(int v);//得到第一个邻接顶点 
	int getNextNeighbor(int v, int w);//得到下一个邻接点 
	void input();//输入图 
	void output();//输出图 
	int getVertexPos(const T vertex)    //给出顶点vertex在图中的位置
	{
		for (int i = 0; i < numVertices; i++)
		{
			if (NodeTable[i].data == vertex)//找到返回该顶点对应的下标 
			{
				return i;
			}
		}
		return -1;//未找到返回-1； 
	}
private:
	int maxVertices;//图的最大顶点数
	int numVertices;
	int numEdges;
	Vertex<T>* NodeTable;
};

template <class T>
Graphlnk<T>::Graphlnk(int sz)   //构造函数：建立一个空的邻接表
{
	maxVertices = sz;
	numVertices = 0;
	numEdges = 0;
	NodeTable = new Vertex<T>[maxVertices];	//创建顶点表数组
	if (NodeTable == NULL)
	{
		cerr << "存储分配错！" << endl;
	}
	for (int i = 0; i < maxVertices; i++)
	{
		NodeTable[i].adj = NULL;
	}
}

template <class T>
Graphlnk<T>::~Graphlnk()
{
	for (int i = 0; i < numVertices; i++)
	{
		Edge<T>* p = NodeTable[i].adj;
		while (p != NULL)
		{
			NodeTable[i].adj = p->link;
			delete p;
			p = NodeTable[i].adj;
		}
	}
	delete[]NodeTable;//删除顶点表数组
}

template <class T>
int Graphlnk<T>::getFirstNeighbor(int v)
{
	if (v != -1)//顶点v存在
	{
		Edge<T>* p = NodeTable[v].adj;
		if (p != NULL)
		{
			return p->dest;   //存在, 返回第一个邻接顶点
		}
	}
	return -1;		//第一个邻接顶点不存在
}

template <class T>
int Graphlnk<T>::getNextNeighbor(int v, int w)
{
	if (v != -1) 			 //顶点v存在
	{
		Edge<T>* p = NodeTable[v].adj;	   //对应边链表第一个边结点
		while (p != NULL && p->dest != w)
		{
			p = p->link;
		}
		if (p != NULL && p->link != NULL)
		{
			return p->link->dest;
		}
	}
	return -1; 			//下一邻接顶点不存在
}
template <class T>
bool Graphlnk<T>::insertVertex(const T& vertex)
{
	//插入顶点 
	if (numVertices == maxVertices)
	{
		return false;
	}
	NodeTable[numVertices].data = vertex;
	NodeTable[numVertices].adj = NULL;
	numVertices++;
	return true;
}

template <class T>
bool Graphlnk<T>::insertEdge(int v1, int v2)   //不带权无向图
{
	//插入无权边 
	Edge<T>* q, * p;
	if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices)//先对两个顶点进行判断 
	{
		p = NodeTable[v1].adj;
		while (p != NULL && p->dest != v2)
		{
			//找到指向v2顶点的边 
			p = p->link;
		}
		if (p != NULL)
		{
			//如果边已经存在返回false 
			return false;
		}
		p = new Edge<T>;
		p->dest = v2;
		p->link = NodeTable[v1].adj;
		NodeTable[v1].adj = p;
		q = new Edge<T>;
		q->dest = v1;
		q->link = NodeTable[v2].adj;
		NodeTable[v2].adj = q;
		numEdges++;
	}
	return true;
}
template <class T>
void Graphlnk<T>::input()
{
	int i, j, k, vn, en;
	T v1, v2;
	cin >> vn >> en;
	for (i = 0; i < vn; i++)
	{
		cin >> v1;
		insertVertex(v1);
	}
	i = 0;
	while (i < en)
	{
		cin >> v1 >> v2;
		j = getVertexPos(v1);
		k = getVertexPos(v2);
		if (j == -1 || k == -1)
		{
			cout << "重新输入边的两个顶点信息！" << endl;
		}
		else
		{
			insertEdge(j, k);
			i++;
		}
	}
}

template <class T>
void Graphlnk<T>::output()
{
	int i, vn;
	Edge<T>* p;
	vn = numVertices;
	for (i = 0; i < vn; i++)
	{
		cout << i << " " << NodeTable[i].data;//输出顶点元素 
		p = NodeTable[i].adj;
		while (p != NULL)
		{
			cout << "-->" << p->dest;
			p = p->link;
		}
		cout << endl;
	}
}

//	########################  程序主入口  ########################
int main()
{
	cin>>n>>m;
	for(re int i=1;i<=30;i++)  //并查集预处理 
    {
        fa[i]=i;
    }
	for(re int i=0;i<m;i++)   //读边集 
	{
		cin>>c1>>c2>>edge[i].w;
		edge[i].u=(c1-'A'+1);
		edge[i].v=(c2-'A'+1);
	}
	cin>>k;
	while(k--)      //进行预处理 
	{
		cin>>c1>>c2;
		pre_process((c1-'A'+1),(c2-'A'+1));
	}
	kruskal();
	cout<<ans<<endl;
	sort(s+1,s+cnt+1,cmp2);
	for(int i=1;i<=cnt;i++)   //输出新建道路的详细信息 
	{
		cout<<(char)(s[i].u-1+'A')<<" "<<(char)(s[i].v-1+'A')<<" "<<s[i].w<<endl;
	}
	return 0;									// 返回退出
}
