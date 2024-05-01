#include <iostream>
//#define lab4_1
//#define lab4_2
//#define lab4_3
//#define lab4_4
//#define lab4_5
#define lab4_6
//#define lab4_7
//#define lab4_8
//#define lab4_9

//����� 1---------------------------------------------------------------------------------------------------------------------------------------------
#ifdef lab4_1
int main()
{
   int x{500};
   float y{52.3};
   double z{-10.2};
   unsigned short k{4};

   int i = (x+y)*z+k ;
   std::cout<<"i = "<<i<<"\n";

   k = static_cast<unsigned short>(x-y/z);
   std::cout<<"k = "<<k<<"\n";

   z = (double)(x*y+z/x);
   std::cout<<"z = "<<z<<"\n";

   unsigned int ui = x/y+k;
   std::cout<<"ui = "<<ui<<"\n";

   short s = x%(short)(x/y);
   std::cout<<"s = "<<s<<"\n";

}
#endif
//------------------------------------------------------------------------------------------------------------------------------------------------------

//����� 2-------------------------------------------------------------------------------------------------------------------------------------------------
#ifdef lab4_2
#include <random> // ��� std::random_device � std::mt19937
#include <array>
int main()
{

 std::random_device rd;
 std::mt19937 mersenne(rd()); //���樠�����㥬 ����� ���ᥭ�� ��砩�� ���⮢� �᫮�
 std::array<unsigned int, 10>arr;

 //���������� ���ᨢ� ��砩�묨 �᫠��
 for(int i = 0; i < (int)arr.size(); ++i)
     arr[i] = mersenne()%10;
 for(auto n:arr)
    std::cout<<n<<" ";

 unsigned int max = arr[0];
 unsigned int min = arr[0];

 //���� �����㬠 � ���ᨬ㬠
 for(int i = 1; i < (int)arr.size(); ++i)
 {
     if(arr[i] > max)
         max = arr[i];
     if(arr[i] < min)
         min = arr[i];
 }

 std::cout<<"\nmax = "<<max<<"\n"<<"min = "<<min<<"\n";
}
#endif
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

//����� 3-------------------------------------------------------------------------------------------------------------------------------------------------
#ifdef lab4_3
int main()
{
    int arr[5][5];

    //������塞 ���ᨢ
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            if(i == j) arr[i][j] = 1;
            else arr[i][j] = 0;
        }
    }

    //�뢥��� �१ foreach �⮡� �룫拉�� �����祭���:)
    for(auto &k:arr)
    {
        for(auto m:k)
        std::cout<<m<<" ";
        std::cout<<"\n";

    }

    return 0;
}
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------

#ifdef lab4_4
//����� 4-----------------------------------------------------------------------------------------------------------------------------------------------
#include <cstdlib> // ��� �㭪権 rand() � srand()
#include <ctime> // ��� �㭪樨 time()
#define SIZE1 8
#define SIZE2 8


//�㭪�� ��� ������ �㬬� ��� ������� ���������
int sum_diagDiagonal(int arr[][SIZE2], int size1, int size2)
{
    int sum = 0;
    for(int i = 0; i < size1; ++i)
    {
        for(int j = 0; j < size2; ++j)
            if(i < j) sum+=arr[i][j];
    }
    return sum;
}


int main()
{
    srand(static_cast<int>(time(0)));  // ��⠭�������� ���祭�� ��⥬��� �ᮢ � ����⢥ ���⮢��� �᫠
    int arr[SIZE1][SIZE2];             //������� ��㬥�� ���ᨢ 8�8

    //������塞 ���ᨢ ��砩�묨 �᫠��
    for(int i = 0; i < SIZE1; ++i)
    {
        for(int j = 0; j < SIZE2; ++j)
            arr[i][j] = rand()%31-15;

    }

    //�뢮��� ���ᨢ �� �࠭
    for(int i = 0; i < SIZE1; ++i)
    {
        for(int j = 0; j < SIZE2; ++j)
            std::cout<<arr[i][j]<<"\t";
        std::cout<<"\n\n\n\n";
    }

    std::cout<<"sum = "<<sum_diagDiagonal(arr, SIZE1, SIZE2);


}
#endif
//-----------------------------------------------------------------------------------------------------------------------------------------------------

//����� 5---------------------------------------------------------------------------------------------------------------------------------------------------
#ifdef lab4_5
//����� 4------------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    for(char symbol = 'a'; symbol <='z'; symbol++ )
        std::cout<<symbol<<" "<<static_cast<int>(symbol)<<"\n";

}
#endif
//-----------------------------------------------------------------------------------------------------------------------------------------------------

//����� 6---------------------------------------------------------------------------------------------------------------------------------------------
#ifdef lab4_6
//----------------------------------------------------------------------------------------------------------------------------------------------------
//���⪠ ���� cin
#define BUFF_CLEAR std::cin.ignore(10000, '\n')

//�㭪�� ���䨪�樨 �����
void inputVerification(int& input)
{
    while (std::cin.fail() || input < 0)
    {
        std::cin.clear();
        BUFF_CLEAR;
        std::cout<<"������ ������⥫�� �᫮�� ���祭��\n";
        std::cin>>input;
    }
}

//���᫥��� 䠪�ਠ��
//int factorialRec(int number)
//{
//    if(number ==1) return number;
//    else return number*factorialRec(number-1);
//}

int factorialIt(int number)
{

    for(int i = number-1; i > 0; --i)
        number*=i;
     return number;
}

int main()
{
    int number;
    std::cout<<"������ 楫�� ������⥫쭮� �᫮(����� Enter ��� �����) ";
    std::cin>>number;
    inputVerification(number);
    //std::cout<<factorialRec(number);
    std::cout<<factorialIt(number);
    return 0;
}

#endif
//---------------------------------------------------------------------------------------------------------------------------------------------------

//����� 7-------------------------------------------------------------------------------------------------------------------------------------------
#ifdef lab4_7

//���⪠ ���� cin
#define BUFF_CLEAR std::cin.ignore(10000, '\n')

//�㭪�� ���䨪�樨 �����
void inputVerification(int& input)
{
    while (std::cin.fail() || input < 0)
    {
        std::cin.clear();
        BUFF_CLEAR;
        std::cout<<"������ ������⥫�� �᫮�� ���祭��\n";
        std::cin>>input;
    }
}

//�㭪�� ���᫥��� �ᥫ ��������
int fib(int number)
{
    int fib1 = 0;
    int fib2 = 1;
    int fibSum = 0;
    if(number == 0)
        return 0;
    else if(number == 1)
        return 1;
    else
        for(int i = 2; i <= number; ++i)
        {
            fibSum = fib1 + fib2;
            fib1 = fib2;
            fib2 = fibSum;
        }
    return fibSum;
}

int main()
{
    int number;
    std::cout<<"������ 楫�� �᫮ ";
    std::cin>>number;
    inputVerification(number);
    for(int i = 0; i < number; i++)
        std::cout<<fib(i)<<" ";
    return 0;
}
#endif
//------------------------------------------------------------------------------------------------------------------------------------------------------

//����� 8----------------------------------------------------------------------------------------------------------------------------------------------
#ifdef lab4_8
#define SIZE 10

int main()
{
    int sum = 0;
    for(int i = 1; i <= SIZE; ++i)
    {
       for(int j =  SIZE; j > i; --j)
           std::cout<<" ";
       for(int j = 1; j <= i; sum+=j, ++j )
            std::cout<<j<<" ";

       std::cout<<"  "<<sum;
       std::cout<<"\n";
       sum = 0;
    }
    return 0;
}
#endif


//����� 9---------------------------------------------------------------------------------------------------------------------------------------------
#ifdef lab4_9
#include <array>
#include "sort.h"  // ���� � �㭪�ﬨ ���஢��
#include <cstdlib> // ��� �㭪権 rand() � srand()
#include <ctime>   // ��� �㭪樨 time()

//���⪠ ���� cin
#define BUFF_CLEAR std::cin.ignore(10000, '\n')

//�㭪�� ���䨪�樨 �����
void inputVerification(int& input)
{
    while (std::cin.fail() || input < 0)
    {
        std::cin.clear();
        BUFF_CLEAR;
        std::cout<<"������ ������⥫�� �᫮�� ���祭��\n";
        std::cin>>input;
    }
}

int main()
{
    srand(static_cast<int>(time(0)));  // ��⠭�������� ���祭�� ��⥬��� �ᮢ � ����⢥ ���⮢��� �᫠
    int quantity = 0;
    std::cout<<"������ ������⢮ ����⮢ ���ᨢ� ";
    std::cin>>quantity;
    inputVerification(quantity);
    int *array = new int[quantity];

    //������塞 ���ᨢ ��砩�묨 �᫠��
    for(int i = 0; i < quantity ; ++i)
            array[i] = rand();

    //�뢮��� ���ᨢ
    std::cout<<"����砫�� ���ᨢ:";
    for(int i = 0; i < quantity; ++i)
        std::cout<<array[i]<<" ";

    //�����㥬 ���ᨢ ����쪮�� ��⮤��
    //bubbleSort(array, quantity);

    //�����㥬 ��⮤�� �롮�
    //selectionSort(array, quantity);

    //�����㥬 ��祩(��ࠬ����쭠� ���஢��)
    heapSort(array, quantity);

    //�뢮��� �����஢���� ���ᨢ
    std::cout<<"\n�����஢���� ���ᨢ:";
    for(int i = 0; i < quantity; ++i)
        std::cout<<array[i]<<" ";
    delete[] array;
    return 0;
}

#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------
