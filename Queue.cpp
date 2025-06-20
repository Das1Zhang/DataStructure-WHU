#include "Queue.h"

template <typename T>
class SqQueue
{
public:
	T *data;
	int front, rear;

	SqQueue()
	{
		data = new T[MaxSize];
		front = rear = -1;
	}

	~SqQueue()
	{
		delete[] data;
	}

	bool empty()
	{
		return front == rear;
	}

	bool push(T e)
	{
		if (rear == MaxSize - 1)
			return false;
		rear++;
		data[rear] = e;
		return true;
	}

	bool pop(T &e)
	{
		if (empty())
			return false;
		front++;
		e = data[front];
		return true;
	}

	bool gethead(T &e)
	{
		if (empty())
			return false;
		int head = front + 1;
		e = data[head];
		return true;
	}
};

template <typename T>
class CSqQueue
{
public:
	T *data;
	int front, rear;

	CSqQueue()
	{
		data = new T[MaxSize];
		front = rear = 0;
	}

	~CSqQueue()
	{
		delete data;
	}

	bool empty()
	{
		return front == rear;
	}

	bool push(T e)
	{
		if ((rear + 1) % MaxSize == front)
			return false;
		rear = (rear + 1) % MaxSize;
		data[rear] = e;
		return true;
	}

	bool pop(T &e)
	{
		if (empty())
			return false;
		front = (front + 1) % MaxSize;
		e = data[front];
		return true;
	}

	bool gethead(T &e)
	{
		if (empty())
			return false;
		head = (front + 1) % MaxSize;
		e = data[head];
		return true;
	}

	int getlength()
	{
		return (rear - front + MaxSize) % MaxSize;
	}
};

bool pushk(CSqQueue<int> &qu, int k, int e)
{
	int x;
	int n = qu.getlength();
	if (k < 1 || k > n + 1)
		return false;
	if (k <= n)
	{
		for (int i = 1; i <= n; i++)
		{
			if (i == k)
				qu.push(e);
			qu.pop(x);
			qu.push(x);
		}
	}
	else
		qu.push(e);
	return true;
}

void simulateTeamQueue()
{
	ifstream inputfile("in.txt");

	int t;
	inputfile >> t;
	unordered_map<int, queue<int>> teamDict;
	unordered_map<int, int> membertoTeam;
	for (int teamID = 0; teamID < t; teamID++)
	{
		int teamSize;
		inputfile >> teamSize;
		for (int i = 0; i < teamSize; i++)
		{
			int memberID;
			inputfile >> memberID;
			membertoTeam[memberID] = teamID;
		}
	}
	queue<int> mainQueue;
	vector<int> output;

	string command;

	while (inputfile >> command)
	{
		if (command == "STOP")
			break;
		else if (command == "ENQUEUE")
		{
			int p;
			inputfile >> p;
			int team = membertoTeam[p];
			if (teamDict[team].empty())
			{
				mainQueue.push(team);
			}
			teamDict[team].push(p);
		}
		else if (command == "DEQUEUE")
		{
			if (mainQueue.empty())
			{
				continue;
			}
			int team = mainQueue.front();
			int member = teamDict[team].front();
			teamDict[team].pop();
			if (teamDict[team].empty())
			{
				mainQueue.pop();
			}
			output.push_back(member);
		}
	}

	for (int member : output)
	{
		cout << member << endl;
	}
}