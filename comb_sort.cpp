#include <iostream>
#include <time.h>
using namespace std;

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

void combSort(int divRate);

void initArray();

const int ARRAY_SIZE = 100000;
const int MAX_NUMBER = 100000;
int arr[ARRAY_SIZE];

int main()
{

  // 1.1, 1.2, ..., 1.9
  for (int i = 11; i < 20; i++)
  {
    // 計測
    clock_t start = clock();
    srand(256);
    initArray();
    combSort(i);
    clock_t end = clock();

    double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    std::cout << "div[" << (double)i / 10.0 << "] : " << time << "ms" << endl;
  }

  // 0.1, 0.2, ..., 0.9
  for (int i = 8; i < 10; i++)
  {
    // 計測
    clock_t start = clock();
    srand(256);
    initArray();
    combSort(i);
    clock_t end = clock();

    double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    std::cout << "div[" << (double)i / 10.0 << "] : " << time << "ms" << endl;
  }

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

void initArray()
{
  for (int i = 0; i < ARRAY_SIZE; i++)
  {
    arr[i] = rand() % MAX_NUMBER + 1;
  }
}