// Client.cpp : Client app for both DLL as well as Static Library
#include <iostream>
#include "DLLMathLibrary.h"
#include "StaticMathLibrary.h"

int main()
{
    // Initialize a Fibonacci relation sequence.
    fibonacci_init(1, 1);
    // Write out the sequence values until overflow.
    do {
        std::cout << fibonacci_index() << ": "
            << fibonacci_current() << std::endl;
    } while (fibonacci_next());
    // Report count of values written before overflow.
    std::cout << fibonacci_index() + 1 <<
        " Fibonacci sequence values fit in an " <<
        "unsigned 64-bit integer." << std::endl;


    double a = 7.4;
    int b = 99;

    std::cout << "a + b = " <<
        StaticMathLibrary::Arithmetic::Add(a, b) << std::endl;
    std::cout << "a - b = " <<
        StaticMathLibrary::Arithmetic::Subtract(a, b) << std::endl;
    std::cout << "a * b = " <<
        StaticMathLibrary::Arithmetic::Multiply(a, b) << std::endl;
    std::cout << "a / b = " <<
        StaticMathLibrary::Arithmetic::Divide(a, b) << std::endl;
}