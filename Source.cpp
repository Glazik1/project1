#include <iostream>
#include <ostream>
#include <malloc.h>
#include <cmath>

using namespace std;

class Kvadrat
{
public:

    int operator()(const int num) const 
    {
        return num * num * num;
    }
};

class ArrayData
{
public:

    int* operator()(int arr[], int size, const int num) const 
    {

        int* mass = new int[size];
        int j = 0;

        for (int i = 0; i < size; i++)
        {
            if (arr[i] <= num)
                continue;

            mass[j] = arr[i];
            j++;
        }

        int* cutedMass = new int[j];
        for (int i = 0; i < j; i++)
        {
            cutedMass[i] = mass[i];
        }

        return cutedMass;
    }
};

class DeleteRange
{
public:
    int* operator()(int num_arr[], int start, int end) const 
    {

        if (start > end)
            return nullptr;

        int* range = new int[end - start];
        int j = 0;

        for (int i = start; i < end; i++)
        {
            range[j] = num_arr[i];
            j++;
        }

        return range;
    }
};

int main()
{
    Kvadrat Kvadrat_num;
    cout << Kvadrat_num(4) << endl;

    ArrayData array;
    int temp[15] = { 8,6,3,5,9,1,2,4,7,2,9,4,1,2,3 };
    int* arr = array(temp, 15, 5);

    for (int i = 0; i < sizeof(arr); i++)
        cout << arr[i] << " ";

    cout << endl;
    DeleteRange range;
    int* del = range(temp, 2, 8);

    for (int i = 0; i < 6; i++)
        cout << del[i] << " ";

    return 0;
}