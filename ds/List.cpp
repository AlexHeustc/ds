#include<iostream>
#include<string>

using namespace std;

//#define MAX_SIZE 100
//
//typedef struct 
//{
//	int *elems;		//顺序表的基地址
//	int length;		//长度
//	int size;		//总空间大小
//}SqList;

template <typename T>
class SqList
{
public:
	SqList() {}
	SqList(int size) {
		m_size = size;
		elems = new T[size];
		m_length = 0;
	}
	int length()//获取长度
	{
		return m_length;
	}
	int size()//获取容量
	{
		return m_size;
	}
	void PushBack(T x)//尾插数据
	{
		if (m_length != m_size)
		{
			elems[m_length] = x;
			m_length++;
		}
	}
	T& operator [](int x)//重载[]，使可以访问赋值
	{
		if (x >= m_length)
		{
			throw - 1;
		}
		else
		{
			return elems[x];
		}
	}
	void Insert(int num, T x)//插入数据
	{
		if (num >= m_length)
		{
			throw - 1;
		}
		else
		{
			m_length++;
			for (int i = m_length - 1; i > num; i--)
			{
				elems[i] = elems[i - 1];
			}
			elems[num] = x;
		}
	}
	void Delete(int x)//删除数据
	{
		if (m_length == x)
		{
			m_length--;
		}
		else
		{
			for (int i = x; i < m_length - 1; i++)
			{
				elems[i] = elems[i + 1];
			}
			m_length--;
		}
	}
	void destroyList()//销毁顺序表
	{
		delete[]elems;
		m_length = 0;
		m_size = 0;
	}
	~SqList()
	{
		delete[]elems;
	}
private:
	T* elems;		//顺序表的基地址
	int m_length;	//长度
	int m_size;		//总空间大小
};

int main()
{
	SqList<string> s(20);
	s.PushBack("x");
	s.PushBack("y");
	s.PushBack("z");
	cout << s.length() << " " << s[0] << " " << s.size() << endl;
	s.Insert(1, "a");
	cout << s[0] << " " << s[1] << " " << s[2] << " " << s[3] << endl;
	s.Delete(1);
	for (int i = 0; i < s.length(); i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
