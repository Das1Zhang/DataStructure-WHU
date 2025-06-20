#include <vector>
using namespace std;

void InsertSort(vector<int> &R, int n);

void BinInsertSort(vector<int> &R, int n);

void ShellSort(vector<int> &R, int n);

void BubbleSort(vector<int> &R, int n);

//========快速排序=========
int Partition1(int A[], int low, int high);

void QuickSort(int A[], int low, int high);

//=========选择排序======
void SelectSort(vector<int> &R, int n);

//=========归并排序==========

void MergePass(vector<int> &R, int length);

void MergeSort1(vector<int> &R, int n);
