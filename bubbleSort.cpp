
//����஢�� ����쪮�
#include "sort.h"

void bubbleSort(int* arr, int n)
{

      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < n-1; j++)
        {
          if (arr[j] > arr[j + 1])
          {
            int b = arr[j];      // ᮧ���� �������⥫��� ��६�����
            arr[j] = arr[j + 1]; // ���塞 ���⠬�
            arr[j + 1] = b;      // ���祭�� ������⮢
          }
        }
      }

}
