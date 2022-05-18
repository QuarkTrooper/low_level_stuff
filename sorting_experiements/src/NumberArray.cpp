
#include <iostream>
#include "NumberArray.h"

NumberArray::NumberArray(){
    sort_function_ = [](void){std::cout << "default function" << std::endl;};
}

NumberArray::NumberArray(int arraySize)
{
    array_length_ = arraySize;
    number_array_ = new int[arraySize];
}

NumberArray::~NumberArray(){}

void NumberArray::SetSortFunction(void(*new_sort_function_)(void))
{
    sort_function_ = new_sort_function_;
}

void NumberArray::Sort()
{
    sort_function_();
}

int NumberArray::GetArrayLength()
{
    return array_length_;
}