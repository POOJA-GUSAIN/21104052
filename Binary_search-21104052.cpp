#include <iostream>
using namespace std;

int binary_search(int arr[], int lower, int upper, int element)
{
    int m = (lower + upper) / 2; 
    while (lower <= upper)
    {
        if (arr[m] == element)
        {
            return m;
        } // if element is present it will return index of the element
        else
        {
            if (arr[m] < element)
            {
                lower = m + 1;
            }
            else
            {
                upper = m - 1;
            }
        }
        m = (lower + upper) / 2;
        
    }
    return -1; 
    // if element is not present it will return -1
}

int binary_search_size_unknown(int arr[], int element)
{
    int lower = 0, upper = 1;
    // We will increase upper until arr[upper] exceeds element to be searched.
    while (element > arr[upper])
    {
        lower= upper;
        upper = 2 * upper;
    }
    return binary_search(arr, lower, upper, element);
}
int main()
{
    int ARR[] = {1, 2, 3, 4, 5};
    binary_search_size_unknown(ARR, 4);
    return 0;
}
