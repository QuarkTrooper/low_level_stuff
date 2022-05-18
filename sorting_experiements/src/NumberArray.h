
#ifndef NUMBERARRAY_H_
#define NUMBERARRAY_H_

class NumberArray
{
public:
    NumberArray();
    NumberArray(int);
    ~NumberArray();

    void SetSortFunction(void(*)(void));
    void Sort();
    int GetArrayLength();

private:
    int array_length_{0};
    int* number_array_{nullptr};
    void (*sort_function_)(void){nullptr};
};

#endif // NUMBERARRAY_H_