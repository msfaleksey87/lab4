//����஢�� �롮஬

#include "sort.h"

void selectionSort(int* arr, int n)
{
    for (int i = 0; i < n - 1; i++)
        {
            int min_index = i;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[min_index])
                {
                    min_index = j;
                }
            }
            if (min_index != i)
            {
                int temp;
                temp = arr[i];
                arr[i] = arr[min_index];
                arr[min_index] = temp;
            }
        }

}
