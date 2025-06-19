#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode
{
	string addr;
	int data;
	string next;
};

void reorderList(map<string, ListNode> &nodes, string head)
{
	vector<ListNode> list;
	string current = head;

	while (current != "-1")
	{
		list.push_back(nodes[current]);
		current = nodes[current].next;
	}
	int n = list.size();
	int left = 0, right = n - 1;
	vector<ListNode> reorderedList;
	while (left <= right)
	{
		reorderedList.push_back(list[right]);
		if (left != right)
		{
			reorderedList.push_back(list[left]);
		}
		left++;
		right--;
	}

	for (int i = 0; i < n - 1; i++)
	{
		reorderedList[i].next = reorderedList[i + 1].addr;
	}
	reorderedList[n - 1].next = "-1";

	for (const auto &node : reorderedList)
	{
		cout << node.addr << " " << node.data << " " << node.next << endl;
	}
}

int main()
{
	string head;
	int n;
	cin >> head >> n;
	map<string, ListNode> nodes;
	for (int i = 0; i < n; i++)
	{
		string addr, next;
		int data;
		cin >> addr >> data >> next;
		nodes[addr] = {addr, data, next};
	}

	reorderList(nodes, head);

	return 0;
}

// 30 + 20*2 + 16*3 + 22*4
// 70+48+88 = 118+88 = 206