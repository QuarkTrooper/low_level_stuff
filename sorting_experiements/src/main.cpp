
#include <iostream>
#include "NumberArray.h"

void testFun(void)
{
    std::cout << "Heellluuuuu!" << std::endl;
}

int main()
{
    NumberArray testArray(5);
    testArray.SetSortFunction(testFun);
    //testArray.Sort();
    std::cout << "array length: " << testArray.GetArrayLength() << std::endl;

    return 0;
}