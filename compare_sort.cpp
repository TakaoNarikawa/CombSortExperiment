#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void combSort(int divRate);
void bubbleSort();
void selectionSort();
void mergeSort(int left, int right);
void quickSort(int left, int right);

void initArray();
bool isSorted();

const int ARRAY_SIZE = 100000;
const int MAX_NUMBER = 100000;
int arr[ARRAY_SIZE];

int main()
{
    srand(256);
    initArray();

    combSort(13);
    // bubbleSort();
    // selectionSort();
    // mergeSort(0, ARRAY_SIZE - 1);
    // quickSort(0, ARRAY_SIZE - 1);
    std::cout << "isSorted(): " << isSorted() << std::endl;
    return 0;
}
int getNextGap(int gap, int divRate)
{
    gap = (gap * 10) / divRate;

    if (gap < 1)
        return 1;
    return gap;
}
void combSort(int divRate)
{
    int gap = ARRAY_SIZE;
    bool swapped = true;
    while (gap != 1 || swapped == true)
    {
        gap = getNextGap(gap, divRate);
        swapped = false;
        for (int i = 0; i < ARRAY_SIZE - gap; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                swap(&arr[i], &arr[i + gap]);
                swapped = true;
            }
        }
    }
}
void bubbleSort()
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        for (int j = ARRAY_SIZE - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(&arr[j], &arr[j - 1]);
            }
        }
    }
}

void selectionSort()
{
    int min, temp;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        min = i;
        for (int j = i + 1; j < ARRAY_SIZE; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(&arr[i], &arr[min]);
        }
    }
}
void mergeSort(int left, int right)
{
    int i, j, k, mid;
    int work[ARRAY_SIZE]; // 作業用配列
    if (left < right)
    {
        mid = (left + right) / 2;  // 真ん中
        mergeSort(left, mid);      // 左を整列
        mergeSort(mid + 1, right); // 右を整列
        for (i = mid; i >= left; i--)
        {
            work[i] = arr[i];
        } // 左半分
        for (j = mid + 1; j <= right; j++)
        {
            work[right - (j - (mid + 1))] = arr[j]; // 右半分を逆順
        }
        i = left;
        j = right;
        for (k = left; k <= right; k++)
        {
            if (work[i] < work[j])
            {
                arr[k] = work[i++];
            }
            else
            {
                arr[k] = work[j--];
            }
        }
    }
}

int partition(int l, int r)
{
    int pivot = arr[r];
    int i = (l - 1);

    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return (i + 1);
}
void quickSort(int left, int right)
{
    if (left < right)
    {
        int pivot = partition(left, right);
        quickSort(left, pivot - 1);
        quickSort(pivot + 1, right);
    }
}

void initArray()
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = rand() % MAX_NUMBER + 1;
    }
}

bool isSorted()
{
    int prev = 0;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (prev > arr[i])
        {
            return false;
        }
        prev = arr[i];
    }
    return true;
}