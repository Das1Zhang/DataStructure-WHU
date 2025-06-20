#include"Input.h"

void Input()
{
	string input;
	cout << "Input numbers divided by space:";
	getline(cin, input);

	istringstream iss(input);	//输入字符串转化为输入流
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
	// getline读取字符串
	string input;
	getline(cin, input);

	// istringstream 将读取字符串转化为输入流
	istringstream iss(input);	//输入字符串转化为输入流
	vector<int> numbers;	// 接收读取到的数字

	// 将输入流一个一个读取到临时变量中
	int number;
	while (iss >> number)
	{
		numbers.push_back(number);
	}

	//遍历输出
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

// 处理多行输入
void InputMultiline()
{
	vector<vector<int>> data;
	string line;

	while (getline(cin, line))
	{
		if (line.empty()) break; // 空行结束输入

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