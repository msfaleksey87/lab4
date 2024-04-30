//����஢�� ��祩

#include "sort.h"

// �㭪�� "��ᥨ�����" �१ ���� - �ନ஢���� ���
void siftDown(int* numbers, int root, int bottom)
{
    int maxChild; // ������ ���ᨬ��쭮�� ��⮬��
    bool done = false; // 䫠� ⮣�, �� ��� ��ନ஢���

    // ���� �� ��諨 �� ��᫥����� �鸞
    while ((root * 2 <= bottom) && (!done))
    {
        if (root * 2 == bottom)    // �᫨ �� � ��᫥���� ���,
            maxChild = root * 2;    // ���������� ���� ��⮬��
        // ���� ���������� ����訩 ��⮬�� �� ����
        else if (numbers[root * 2] > numbers[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        // �᫨ ����� ���設� ����� ���ᨬ��쭮�� ��⮬��
        if (numbers[root] < numbers[maxChild])
        {
            int temp = numbers[root]; // ���塞 �� ���⠬�
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        }
        else // ����
            done = true; // ��ࠬ��� ��ନ஢���
    }
}
// �㭪�� ���஢�� �� ���
void heapSort(int* numbers, int array_size)
{
    // ��ନ�㥬 ������ �� ��ࠬ���
    for (int i = (array_size / 2); i >= 0; i--)
        siftDown(numbers, i, array_size - 1);
    // ��ᥨ���� �१ ��ࠬ��� ��⠫�� ������
    for (int i = array_size - 1; i >= 1; i--)
    {
        int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        siftDown(numbers, 0, i - 1);
    }
}
