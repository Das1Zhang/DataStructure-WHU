#include"Input.h"

void Input()
{
	string input;
	cout << "Input numbers divided by space:";
	getline(cin, input);

	istringstream iss(input);	//�����ַ���ת��Ϊ������
	vector<int> numbers;
	int number;

	while (iss >> number) {
		numbers.push_back(number);
	}

	cout << "The input numbers are:";
	for (int num : numbers) {
		cout << num << " ";
	}

	cout << endl;
}

void Input2()
{
	// getline��ȡ�ַ���
	string input;
	getline(cin, input);

	// istringstream ����ȡ�ַ���ת��Ϊ������
	istringstream iss(input);	//�����ַ���ת��Ϊ������
	vector<int> numbers;	// ���ն�ȡ��������

	// ��������һ��һ����ȡ����ʱ������
	int number;
	while (iss >> number)
	{
		numbers.push_back(number);
	}

	//�������
	for (int num : numbers)
	{
		cout << num << " ";
	}

}

void InputbyFile()
{
	ifstream inputFile("in.txt");

	vector<int> numbers;
	int number;

	while (inputFile >> number)
	{
		numbers.push_back(number);
	}

	for (int num : numbers)
	{
		cout << num << " ";
	}

}

void Input3()
{
	string line;
	getline(cin, line);
	istringstream iss(line);
	vector<int> numbers;

	string token;
	while (getline(iss, token, ','))
	{
		numbers.push_back(stoi(token));
	}
}

// �����������
void InputMultiline()
{
	vector<vector<int>> data;
	string line;

	while (getline(cin, line))
	{
		if (line.empty()) break; // ���н�������

		istringstream iss(line);
		vector<int> row;
		int number;

		while (iss >> number) {
			row.push_back(number);
		}
		data.push_back(row);
	}
	for (const auto& row : data)
	{
		for (int num : row)
		{
			cout << num << " ";
		}
		cout << endl;
	}
}