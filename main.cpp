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

//Задача 1---------------------------------------------------------------------------------------------------------------------------------------------
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

//Задача 2-------------------------------------------------------------------------------------------------------------------------------------------------
#ifdef lab4_2
#include <random> // для std::random_device и std::mt19937
#include <array>
int main()
{

 std::random_device rd;
 std::mt19937 mersenne(rd()); //инициализируем Вихрь Мерсенна случайным стартовым числом
 std::array<unsigned int, 10>arr;

 //Заполнение массива случайными числами
 for(int i = 0; i < (int)arr.size(); ++i)
     arr[i] = mersenne()%10;
 for(auto n:arr)
    std::cout<<n<<" ";

 unsigned int max = arr[0];
 unsigned int min = arr[0];

 //поиск минимума и максимума
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

//Задача 3-------------------------------------------------------------------------------------------------------------------------------------------------
#ifdef lab4_3
int main()
{
    int arr[5][5];

    //Заполняем массив
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            if(i == j) arr[i][j] = 1;
            else arr[i][j] = 0;
        }
    }

    //Выведем через foreach чтобы выглядело замороченнее:)
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
//Задача 4-----------------------------------------------------------------------------------------------------------------------------------------------
#include <cstdlib> // для функций rand() и srand()
#include <ctime> // для функции time()
#define SIZE1 8
#define SIZE2 8


//Функция для подсчета суммы выше главной диагонали
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
    srand(static_cast<int>(time(0)));  // устанавливаем значение системных часов в качестве стартового числа
    int arr[SIZE1][SIZE2];             //Создаем двумерный массив 8х8

    //Заполняем массив случайными числами
    for(int i = 0; i < SIZE1; ++i)
    {
        for(int j = 0; j < SIZE2; ++j)
            arr[i][j] = rand()%31-15;

    }

    //Выводим массив на экран
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

//Задача 5---------------------------------------------------------------------------------------------------------------------------------------------------
#ifdef lab4_5
//Задача 4------------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    for(char symbol = 'a'; symbol <='z'; symbol++ )
        std::cout<<symbol<<" "<<static_cast<int>(symbol)<<"\n";

}
#endif
//-----------------------------------------------------------------------------------------------------------------------------------------------------

//Задача 6---------------------------------------------------------------------------------------------------------------------------------------------
#ifdef lab4_6
//----------------------------------------------------------------------------------------------------------------------------------------------------
//Очистка буфера cin
#define BUFF_CLEAR std::cin.ignore(10000, '\n')

//Функция верификации ввода
void inputVerification(int& input)
{
    while (std::cin.fail() || input < 0)
    {
        std::cin.clear();
        BUFF_CLEAR;
        std::cout<<"Вводите положительные числовые значения\n";
        std::cin>>input;
    }
}

//Вычисление факториала
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
    std::cout<<"Введите целое положительное число(намите Enter для ввода) ";
    std::cin>>number;
    inputVerification(number);
    //std::cout<<factorialRec(number);
    std::cout<<factorialIt(number);
    return 0;
}

#endif
//---------------------------------------------------------------------------------------------------------------------------------------------------

//Задача 7-------------------------------------------------------------------------------------------------------------------------------------------
#ifdef lab4_7

//Очистка буфера cin
#define BUFF_CLEAR std::cin.ignore(10000, '\n')

//Функция верификации ввода
void inputVerification(int& input)
{
    while (std::cin.fail() || input < 0)
    {
        std::cin.clear();
        BUFF_CLEAR;
        std::cout<<"Вводите положительные числовые значения\n";
        std::cin>>input;
    }
}

//Функция вычесления цисел Фиббоначи
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
    std::cout<<"Введите целое число ";
    std::cin>>number;
    inputVerification(number);
    for(int i = 0; i < number; i++)
        std::cout<<fib(i)<<" ";
    return 0;
}
#endif
//------------------------------------------------------------------------------------------------------------------------------------------------------

//Задача 8----------------------------------------------------------------------------------------------------------------------------------------------
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


//Задача 9---------------------------------------------------------------------------------------------------------------------------------------------
#ifdef lab4_9
#include <array>
#include "sort.h"  // Фаил с функциями сортировки
#include <cstdlib> // для функций rand() и srand()
#include <ctime>   // для функции time()

//Очистка буфера cin
#define BUFF_CLEAR std::cin.ignore(10000, '\n')

//Функция верификации ввода
void inputVerification(int& input)
{
    while (std::cin.fail() || input < 0)
    {
        std::cin.clear();
        BUFF_CLEAR;
        std::cout<<"Вводите положительные числовые значения\n";
        std::cin>>input;
    }
}

int main()
{
    srand(static_cast<int>(time(0)));  // устанавливаем значение системных часов в качестве стартового числа
    int quantity = 0;
    std::cout<<"Введите количество элементов массива ";
    std::cin>>quantity;
    inputVerification(quantity);
    int *array = new int[quantity];

    //Заполняем массив случайными числами
    for(int i = 0; i < quantity ; ++i)
            array[i] = rand();

    //Выводим массив
    std::cout<<"Изначальный массив:";
    for(int i = 0; i < quantity; ++i)
        std::cout<<array[i]<<" ";

    //Соритируем массив пузырьковым методом
    //bubbleSort(array, quantity);

    //Сортируем методом выбора
    //selectionSort(array, quantity);

    //Сортируем кучей(пирамидальная сортировка)
    heapSort(array, quantity);

    //Выводим отсортированный массив
    std::cout<<"\nОтсортированный массив:";
    for(int i = 0; i < quantity; ++i)
        std::cout<<array[i]<<" ";
    delete[] array;
    return 0;
}

#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------
