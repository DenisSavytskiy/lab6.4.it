#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

void generateArray(int* a, const int size) {
    for (int i = 0; i < size; i++) {
        a[i] = rand() % 46 - 10;
    }
}

void printArray(const int* a, const int size) {
    for (int i = 0; i < size; i++) {
        std::cout << std::setw(5) << a[i];
    }
    std::cout << std::endl;
}

int findMaxIndex(const int* a, const int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (a[i] > a[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int productBetweenZeros(const int* a, const int size) {
    int firstZero = -1, secondZero = -1;
    int product = 1;
    bool foundFirst = false;

    for (int i = 0; i < size; i++) {
        if (a[i] == 0) {
            if (!foundFirst) {
                foundFirst = true;
                firstZero = i;
            }
            else {
                secondZero = i;
                break;
            }
        }
        else if (foundFirst) {
            product *= a[i];
        }
    }
    return (secondZero != -1) ? product : 0;
}

void printTransformedArray(const int* a, const int size) {
    for (int i = 0; i < size; i += 2) {
        std::cout << std::setw(5) << a[i];
    }
    for (int i = 1; i < size; i += 2) {
        std::cout << std::setw(5) << a[i];
    }
    std::cout << std::endl;
}

int main() {
    srand((unsigned)time(NULL));

    int size;
    std::cout << "size = ";
    std::cin >> size;

    int* arr = new int[size];

    generateArray(arr, size);

    printArray(arr, size);

    int maxIndex = findMaxIndex(arr, size);
    std::cout << "Max element index: " << maxIndex << std::endl;

    int product = productBetweenZeros(arr, size);
    std::cout << "Product of elements between 0 and 0: " << product << std::endl;

    printTransformedArray(arr, size);

    return 0;
}