#include <vector>
using namespace std;

void InsertSort(vector<int> &R, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (R[i] < R[i - 1])
        {
            int tmp = R[i];
            int j = i - 1;
            do
            {
                R[j + 1] = R[j];
                j--;
            } while (j >= 0 && R[j] > tmp);
            R[j + 1] = tmp;
        }
    }
}

void BinInsertSort(vector<int> &R, int n)
{
    for (int i = 1; i < n; i++)
    {
        int tmp = R[i];
        int low = 0, high = i - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (tmp < R[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
            for (int j = i - 1; j >= high + 1; j--)
            {
                R[j + 1] = R[j];
            }
            R[high + 1] = tmp;
        }
    }
}

void ShellSort(vector<int> &R, int n)
{
    int d = n / 2;
    while (d > 0)
    {
        for (int i = d; i < n; i++)
        {
            if (R[i] < R[i - d])
            {
                int tmp = R[i];
                int j = i - d;
                do
                {
                    R[j + d] = R[j];
                    j = j - d;
                } while (j >= 0 && R[j] > tmp);
                R[j + d] = tmp;
            }
        }
        d = d / 2;
    }
}

void BubbleSort(vector<int> &R, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool exchange = false;
        for (int j = n - 1; j > i; j--)
        {
            if (R[j] < R[j - 1])
            {
                swap(R[j], R[j - 1]);
                exchange = true;
            }
        }
        if (!exchange)
        {
            return;
        }
    }
}

//========快速排序=========
int Partition1(int A[], int low, int high)
{
    int pivot = A[low];
    while (low < high)
    {
        while (low < high && A[high] >= pivot)
        {
            --high;
        }
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
        {
            ++low;
        }
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

void QuickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int pivot = Partition1(A, low, high);
        QuickSort(A, low, pivot - 1);
        QuickSort(A, pivot + 1, high);
    }
}

//=========选择排序======
void SelectSort(vector<int> &R, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minj = i;
        for (int j = i + 1; j < n; j++)
        {
            if (R[j] < R[minj])
            {
                minj = j;
            }
        }
        if (minj != i)
        {
            swap(R[i], R[minj]);
        }
    }
}

//=========归并排序==========
void Merge(vector<int> &R, int low, int mid, int high)
{
    vector<int> R1;
    R1.resize(high - low + 1);
    int i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high)
    {
        if (R[i] <= R[j])
        {
            R1[k] = R[i];
            i++;
            k++;
        }
        else
        {
            R1[k] = R[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        R1[k] = R[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        R1[k] = R[j];
        j++;
        k++;
    }
    for (k = 0, i = low; i <= high; k++, i++)
    {
        R[i] = R1[k];
    }
}

void MergePass(vector<int> &R, int length)
{
    int n = R.size(), i;
    for (i = 0; i + 2 * length - 1 < n; i += 2 * length)
    {
        Merge(R, i, i + length - 1, i + 2 * length - 1);
    }
    if (i + length < n)
    {
        Merge(R, i, i + length - 1, n - 1);
    }
}

void MergeSort1(vector<int> &R, int n)
{
    for (int length = 1; length < n; length = 2 * length)
    {
        MergePass(R, length);
    }
}
