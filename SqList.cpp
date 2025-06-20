#include"SqList.h"

template<typename T>
class SqList
{
public:
	int length;	//ע��length���÷����ȿ��Դ洢���鳤�ȵ���Ϣ��Ҳ������Ϊ���һ��Ԫ�ص�����
	T* data;
	int capacity;

	// ˳������ݲ���
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

	// ���ƹ��캯�����������
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