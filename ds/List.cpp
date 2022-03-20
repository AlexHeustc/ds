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
	SqList() {};
	SqList(int size) {
		m_size = size;
		elems = new T[size];
		m_length = 0;
	}
	int length() {
		return m_length;
	}
	int size() {
		return m_size;
	}
	void PushBack(T x) {
		if (m_length !=m_size)
		{
			elems[m_length] = x;
			m_length++;

		}
	}

	T& operator [](int x)
	{
		if ( x >= m_length || x < 0) {
			throw - 1;
		}
		else
		{
			return elems[x];
		}
	}

	void Insert(int num, T x) {
		if (num < 0 || num >= m_length)
		{
			throw - 1;
		}
		else
		{
			m_length++;
			for (int i = m_length; i > num;i--)
			{
				elems[i] = elems[i - 1];

			}
			elems[num] = x;
		}

	}

	void Delete(int x) {
		if (x<0||x>=m_length)
		{
			throw - 1;

		}
		else if (x == m_length)
		{
			m_length--;

		}
		else
		{
			
			for (int i = x; i <= m_length; i++)
			{
				elems[i] = elems[i + 1];


			}
			m_length--;
		}

	}

	void destoryList()
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
	T* elems;
	int m_length;
	int m_size;

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

