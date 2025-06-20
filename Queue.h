#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>
using namespace std;

const int MaxSize = 100;

template <typename T>
class SqQueue;

template <typename T>
class CSqQueue;

bool pushk(CSqQueue<int> &qu, int k, int e);

void simulateTeamQueue();