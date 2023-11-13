#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));

    // Test 1: Fill arrays with random values
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    // Test 2: Copy constructor and assignment operator with different-sized arrays
    Array<int> smallerArray(MAX_VAL - 1);
    smallerArray = numbers;  // Test assignment operator
    Array<int> copiedArray = numbers;  // Test copy constructor

    // Test 3: Output sizes
    std::cout << "Size of numbers array: " << numbers.size() << std::endl;
    std::cout << "Size of smallerArray: " << smallerArray.size() << std::endl;
    std::cout << "Size of copiedArray: " << copiedArray.size() << std::endl;

    // Test 4: Copy constructor with an empty array
    Array<int> emptyArray;
    Array<int> copiedEmptyArray = emptyArray;

    // Test 5: Access elements after copying
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i] || mirror[i] != copiedArray[i])
        {
            std::cerr << "Test 5: Didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    // Test 6: Try accessing out-of-bounds indices
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Test 6: " << e.what() << '\n';
    }

    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Test 6: " << e.what() << '\n';
    }

    // Test 7: Modify elements after copying
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }

    delete [] mirror;//
    return 0;
}
