#include <iostream>
#include <locale>
#include <ctime>
#include <format>

using namespace std;

template<typename Func, typename... Args>

auto FunctionTime(Func f, Args... args) 
{
    clock_t start = clock();
    volatile auto result = f(args...);
    clock_t finish = clock();
    return (double)(finish - start) / CLOCKS_PER_SEC;
}


float RecCadiou(int x, int y, int z) 
{
    if (x == y) 
    {
        return z;
    }
    else if (x > y) 
    {
        RecCadiou(x, y + 1, z * (y + 1));
    }
    else if (x < y)
    {
        cout << "\n Ошибка: X не может быть меньше Y.";
    }
}

float Cadiou(int x, int y, int z)
{
    for (; y < x; y++) 
    {
        z*=(y + 1);
    }
    return z;
}

float RecCalculationPi(int k, int N) 
{
    if (k > N) 
    {
        return 0;
    }

    return pow(-1, k) / pow((k + 1), 2) + RecCalculationPi(k + 1, N);
    
}

float CalculationPi(int k, int N)
{
    float summ = 0;
    for(;k<=N;k++) 
    {
        summ += pow(-1, k) / pow((k + 1), 2);
    }
    return summ;

}


float aveSum = 0;
int k = 0;


float RecAverageSum() 
{
    float num;

    cout << "\nВведите число: ";
    cin >> num;

    if (num >= 0)
    {
        aveSum += num;
        k++;
        RecAverageSum();
    }
    else
    {
        cout << "Среднее арифметическое: " << aveSum / k;
        return aveSum / k;
    }

}


float AverageSum()
{
    float num = 0;
    int n = 0;
    float summ = 0;

    while (num >= 0) 
    {
        cout << "\nВведите число: ";
        cin >> num;
        if (num < 0) break;
        summ += num;
        n++;
    }
    cout << "Среднее арифметическое: " << summ / n;
    return summ / n;
}

int main()
{
    setlocale(LC_ALL, "rus");

    int x, y, z;

    cout << "Часть A: \n";
    cout << "Введите x, y, z: ";
    cin >> x >> y >> z;
    cout << "Результат: " << RecCadiou(x,y,z) << "\n";
    cout << format ("Время выполнения: {:.4f}\n",FunctionTime(RecCadiou, x, y, z));
    cout << "Результат: " << Cadiou(x, y, z) << "\n";
    cout << format("Время выполнения: {:.4f}\n", FunctionTime(Cadiou, x, y, z));


    int N;

    cout << "Часть B: \n";
    cout << "Введите N: ";
    cin >> N;
    cout << "Результат Pi = " << sqrt(12*RecCalculationPi(0, N)) << "\n";
    cout << format("Время выполнения: {:.4f}\n", FunctionTime(RecCalculationPi, 0, N));
    cout << "Результат Pi = " << sqrt(12 * CalculationPi(0, N)) << "\n";
    cout << format("Время выполнения: {:.4f}\n", FunctionTime(CalculationPi, 0, N));


    cout << "Часть С:";
    cout << format("Время выполнения: {:.4f}\n", FunctionTime(RecAverageSum));
    cout << format("Время выполнения: {:.4f}\n", FunctionTime(AverageSum));
    aveSum = 0;
    k = 0;

}
