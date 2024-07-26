#include<iostream>
#include"exceptdef.h"

using namespace mystl;
int main() {
    int x = 5;
    
    // Example of MYSTL_DEBUG
    MYSTL_DEBUG(x == 5); // Assertion will pass
    
    // Example of THROW_LENGTH_ERROR_IF
    int arraySize = 10;
    THROW_LENGTH_ERROR_IF(arraySize > 100, "Array size exceeds maximum"); // No exception thrown
    
    // Example of THROW_OUT_OF_RANGE_IF
    int index = 9;
    THROW_OUT_OF_RANGE_IF(index >= arraySize, "Index out of range"); // Exception thrown
    
    // Example of THROW_RUNTIME_ERROR_IF
    int divisor = 0;
    THROW_RUNTIME_ERROR_IF(divisor == 0, "Division by zero"); // Exception thrown
    
    return 0;
}