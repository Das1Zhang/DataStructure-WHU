#include"SqList.h"

template<typename T>
class SqList
{
public:
	int length;	//注意length的用法，既可以存储数组长度的信息，也可以作为最后一个元素的索引
	T* data;
	int capacity;

	// 顺序表扩容操作
	void recap(int newcap) {
		if (newcap <= 0) return;
		
		T* odddata = data;
		data = new T[newcap];

		for (int i = 0; i < length; i++) {
			data[i] = odddata[i];
		}

		delete[]odddata;
	}

	void CreateList(T a[], int n) {
		for (int i = 0; i < n; i++) {
			if (length == capacity) {
				recap(2 * capacity);
			}
			data[length] = a[i];
			length++;
		}
	}

	SqList()
	{
		data = new T[initcap];
		capacity = initcap;
		length = 0;
	}

	// 复制构造函数，采用深复制
	SqList(const SqList& s)
	{
		capacity = s.capacity;
		length = s.length;
		data = new T[capacity];
		for (int i = 0; i < length; i++)
		{
			data[i] = s->data[i];
		}
	}

	~SqList()
	{
		delete[]data;
	}

	void Add(T e)
	{
		if (length == capacity)
		{
			recap(2 * capacity);
		}
		data[length] = e;
		length++;
	}

	int Getlength()
	{
		return length;
	}

	bool GetElem(int i, T& e)
	{
		if (i < 0 || i >= length)
		{
			return false;
		}

		e = data[i];
		return true;
	}

	bool SetElem(int i, T e)
	{
		if (i < 0 || i >= length)
		{
			return false;
		}
		data[i] = e;
		return true;
	}

	int GetNo(T e)
	{
		int i = 0;
		while (i < length && data[i] != e)
		{
			i++;
		}
		if (i >= length)
			return -1;
		else
			return i;
	}

	bool Insert(int i, T e)
	{
		if (i < 0 || i > length)
		{
			return false;
		}
		if (length == capacity)
			recap(2 * capacity);
		for (int j = length - 1; j > i; j--)
		{
			data[j] = data[j - 1];
		}
		data[i] = e;
		length++;
		return true;
	}

	bool Delete(int i)
	{
		if (i < 0 || i >= length)
		{
			return false;
		}

		for (int j = length - 1; j > i; j--)
		{
			data[j - 1] = data[j];
		}
		length--;
		if (capacity > initcap && length <= capacity / 4)
			recap(capacity / 2);
		return true;
	}

	void DispList()
	{
		for (int i = 0; i < length; i++)
			cout << data[i] << " ";
		cout << endl;
	}
};