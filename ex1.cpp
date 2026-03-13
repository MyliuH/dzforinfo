#include <iostream>

typedef int(*func)(int);

int SevenPlus(int num) {
    return num + 7;
}

int SevenMultiplie(int num) {
    return num * 7;
}

void map(int* A, size_t size, func f) {

    for (size_t i = 0; i < size; i++) {
        std::cout << f(A[i]) << " ";
    }
    std::cout << "\n";
}

int main()
{
    int A[10];

    for (size_t i = 0; i < std::size(A); i++) {
        A[i] = i;
        std::cout << A[i] << " ";
    }
    std::cout << "\n";

    map(A, std::size(A), SevenPlus);

    map(A, std::size(A), SevenMultiplie);
}

