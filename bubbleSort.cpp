
//Сортировка пузырьком
#include "sort.h"

void bubbleSort(int* arr, int n)
{

      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < n-1; j++)
        {
          if (arr[j] > arr[j + 1])
          {
            int b = arr[j];      // создали дополнительную переменную
            arr[j] = arr[j + 1]; // меняем местами
            arr[j + 1] = b;      // значения элементов
          }
        }
      }

}
