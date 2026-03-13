#include <iostream>
#include <locale>

int cadiou(int x, int y, int z) 
{
    if (x == y) 
    {
        return z;
    }
    else if (x > y) 
    {
        cadiou(x, y + 1, z * (y + 1));
    }
    else if (x < y)
    {
        std::cout << "Ошибка: X не может быть меньше Y.";
    }
}

float CalculationPi(int k, int N) 
{
    if (k > N) 
    {
        return 0;
    }

    return pow(-1, k) / pow((k + 1), 2) + CalculationPi(k + 1, N);
    
}

int main()
{
    setlocale(LC_ALL, "rus");

    int x, y, z;

    std::cout << "Часть A: \n";
    std::cout << "Введите x, y, z: ";
    std::cin >> x >> y >> z;
    std::cout << "Результат: " << cadiou(x,y,z) << "\n";


    int N;

    std::cout << "Часть B: \n";
    std::cout << "Введите N: ";
    std::cin >> N;
    std::cout << "Результат Pi = " << sqrt(12*CalculationPi(0, N));

}
